/*****************************************************/
/*Author  : Mahmoud Hamdy							               */
/*Version : V01.1			 							                   */
/*Date	  :2020-04-23								*/
/*****************************************************/
/*
 * Changelog from version 1.0:
 * 1. Added a new API to make delay in microseconds (Based on a systick clock of 8MHz)
 * */


#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"

/*Registers*/
#define		SYSTICK_BASE_ADDRESS			(u32)(0xE000E010)
#define 	SYSTICK_CTRL_ADDRESS			(u32 volatile *)(SYSTICK_BASE_ADDRESS + 0x00)
#define 	SYSTICK_LOAD_ADDRESS			(u32 volatile *)(SYSTICK_BASE_ADDRESS + 0x04)
#define 	SYSTICK_VAL_ADDRESS				(u32 volatile *)(SYSTICK_BASE_ADDRESS + 0x08)
#define 	SYSTICK_CALIB_ADDRESS			(u32 volatile *)(SYSTICK_BASE_ADDRESS + 0x0C)

/*This macro is a dummy value that will be written to the current value register to reset the timer*/
#define		SYSTICK_RESET_DUMMY				(u32)0xFFFFFFFF


/*This pointer will hold the address of callback function passed using Set Callback Method*/
static SYSTICK_CallBackFunction_t CallbackFunction = NULL;

/*APIs*/
/*Description: This API will be used to initialize the SYSTICK using configurations from SYSTICKconfig.h
 * Parameters: None
 * Return: None*/
void SYSTICK_voidInit(void)
{
	/*Check clock configuration that the user entered, if he entered one of the valid
	 * choices, then write them directly to the register
	 * If a wrong configuration was entered, use the default which is SYSTICK_CLK_AHB8*/
	if (SYSTICK_SOURCE_CLK_CONFIG == SYSTICK_CLK_AHB8)
	{
		*SYSTICK_CTRL_ADDRESS &= (u32)SYSTICK_CLK_AHB8;
	}
	else if (SYSTICK_SOURCE_CLK_CONFIG == SYSTICK_CLK_AHB)
	{
		*SYSTICK_CTRL_ADDRESS |= (u32)SYSTICK_CLK_AHB;
	}
	else
	{
		*SYSTICK_CTRL_ADDRESS &= (u32)SYSTICK_CLK_AHB8;
	}
	/*Check interrupt configuration that the user entered, if he entered one of the valid
	 * choices, then write them directly to the register
	 * If a wrong configuration was entered, use the default which is SYSTICK_INTERRUPT_DISABLE*/
	if (SYSTICK_INTERRUPT_CONFIG == SYSTICK_INTERRUPT_DISABLE)
	{
		*SYSTICK_CTRL_ADDRESS &= (u32)SYSTICK_INTERRUPT_DISABLE;
	}
	else if (SYSTICK_INTERRUPT_CONFIG == SYSTICK_INTERRUPT_ENABLE)
	{
		*SYSTICK_CTRL_ADDRESS |= (u32)SYSTICK_INTERRUPT_ENABLE;
	}
	else
	{
		*SYSTICK_CTRL_ADDRESS &= (u32)SYSTICK_INTERRUPT_DISABLE;
	}
	/*Add threshold value to Reload register*/
	*SYSTICK_LOAD_ADDRESS |= SYSTICK_RELOAD_VALUE;

}

/*Description: This API will be used to either enable or disable the SYSTICK timer
 * Parameters: Desired State (u32)
 * Return: Error Status (u8)*/
u8 SYSTICK_u8SetSYSTICKStatus(u32 Copy_u32Status)
{
	/*This variable will hold the error status*/
	u8 Local_u8ErrorStatus = STATUS_NOK;
	/*For enabling, the enable value will be ORed with the enable mask*/
	if (Copy_u32Status == SYSTICK_ENABLE)
	{
		*SYSTICK_CTRL_ADDRESS |= SYSTICK_ENABLE;
		Local_u8ErrorStatus = STATUS_OK;
	}
	/*For disabling, the value will be AND with the complement of enable mask*/
	else if (Copy_u32Status == SYSTICK_DISABLE)
	{
		*SYSTICK_CTRL_ADDRESS &= SYSTICK_DISABLE;
		Local_u8ErrorStatus = STATUS_OK;
	}
	return Local_u8ErrorStatus;
}

/*Description: This API will be used to either set callback function for SYSTICK Interrupt
 * Parameters: Pointer to desired function (u32)
 * Return: Error Status (u8)*/
u8 SYSTICK_u8SetCallBack(SYSTICK_CallBackFunction_t Copy_CallbackFunction)
{
	/*This variable will hold the error status that will be returned at the end of the function*/
	u8 Local_u8ErrorStatus=STATUS_NOK;
	/*If function doesn't equal null, then set call back function to passed function*/
	if (Copy_CallbackFunction)
	{
		CallbackFunction = Copy_CallbackFunction;
		Local_u8ErrorStatus=STATUS_OK;
	}
	return Local_u8ErrorStatus;
}

/*Description: This handler will be executed when interrupt of systick is called
 * Parameters: None
 * Return: None*/
void SysTick_Handler (void)
{
	/*Check if pointer to callback function is not null, if it is not null then call it*/
	if (CallbackFunction)
	{
		CallbackFunction();
	}
}

/*Description: This API will be used to either reset the SYSTICK timer
 * Parameters: None
 * Return: None*/
void SYSTICK_u8Reset(void)
{
	/*Reset will be done by writing any value to current value register*/
	*SYSTICK_VAL_ADDRESS |= SYSTICK_RESET_DUMMY;
}

/*Description: This API will be used to make delay in microseconds (based on a clock of 8 MHz)
 * Parameters: Time for delay (in microseconds)
 * Return: None*/
void SYSTICK_voidBusyDelay (u32 Copy_microseconds)
{
	/*Enable systick in case it is not enabled*/
	SYSTICK_u8SetSYSTICKStatus(SYSTICK_ENABLE);
	/*Load timing value to Reload value register*/
	*SYSTICK_LOAD_ADDRESS = Copy_microseconds;
	/*Reset value inside current value register*/
	*SYSTICK_VAL_ADDRESS = 0;
	/*Wait for delay to end*/
	while ((*SYSTICK_CTRL_ADDRESS & SYSTICK_CTRL_COUNT_FLAG_MASK)==0);
}

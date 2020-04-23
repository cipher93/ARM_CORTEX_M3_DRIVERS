/*****************************************************/
/*Author  : Mahmoud Hamdy							*/
/*Version : V01			 							*/
/*Date	  :2020-03-18								*/
/*****************************************************/
#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include "STD_TYPES.h"


/*Type of pointer that will be pointed to desired callback function*/
typedef		void(*SYSTICK_CallBackFunction_t)(void);

/*Macros to be used by user*/
/*Enable/Disable*/
#define		SYSTICK_ENABLE					SYSTICK_CTRL_ENABLE_MASK
#define		SYSTICK_DISABLE					(~(SYSTICK_CTRL_ENABLE_MASK))
#define		SYSTICK_CLK_AHB					SYSTICK_CTRL_AHB_MASK
#define		SYSTICK_CLK_AHB8				(~(SYSTICK_CTRL_AHB_MASK))
#define		SYSTICK_INTERRUPT_ENABLE		SYSTICK_CTRL_TICKINT_MASK
#define		SYSTICK_INTERRUPT_DISABLE		(~(SYSTICK_CTRL_TICKINT_MASK))



/****************************************************************************/
/***********************Warning: Don't change the next section***************/

/*Masks*/
/*Control and Status Register*/
#define		SYSTICK_CTRL_ENABLE_MASK		(0x01)
#define		SYSTICK_CTRL_TICKINT_MASK		(0x02)
#define		SYSTICK_CTRL_AHB_MASK			(0x04)
#define		SYSTICK_CTRL_COUNT_FLAG_MASK	(0x8000)


/****************************************************************************/


/*APIs*/
/*Description: This API will be used to initialize the SYSTICK using configurations from SYSTICKconfig.h
 * Parameters: None
 * Return: None*/
extern void SYSTICK_voidInit(void);

/*Description: This API will be used to either enable or disable the SYSTICK timer
 * Parameters: Desired State (u32)
 * Return: Error Status (u8)*/
extern u8 SYSTICK_u8SetSYSTICKStatus(u32 Copy_u32Status);


/*Description: This API will be used to either set callback function for SYSTICK Interrupt
 * Parameters: Pointer to desired function (u32)
 * Return: Error Status (u8)*/
extern u8 SYSTICK_u8SetCallBack(SYSTICK_CallBackFunction_t Copy_CallbackFunction);

/*Description: This API will be used to either reset the SYSTICK timer
 * Parameters: None
 * Return: None*/
extern void SYSTICK_u8Reset(void);


#endif

/***************************************/
/*Author: Mahmoud Hamdy ****************/
/*Date	: 15/01/2020********************/
/***************************************/

/*Libraries Inclusion				   */
/*Library Layer						   */
/*This is the library that will contain the standard types 
that we will use like u8, u16, etc.*/
#include "STD_TYPES.h"

/*Current Library Layer*/
#include "RCC_interface.h"

/*****************************Registers*****************************/
/*Base address for RCC which will be used to reach peripherals by adding offset to it*/
#define RCC_BASE_ADDRESS 	0x40021000

/*Offset Addresses for peripherals*/
#define RCC_CR 				*((u32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_CFGR 			*((u32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CIR 			*((u32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_APB2RSTR		*((u32*)(RCC_BASE_ADDRESS+0x0C))
#define RCC_APB1RSTR		*((u32*)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHBENR			*((u32*)(RCC_BASE_ADDRESS+0x14))
#define RCC_APB2ENR			*((u32*)(RCC_BASE_ADDRESS+0x18))
#define RCC_APB1ENR			*((u32*)(RCC_BASE_ADDRESS+0x1C))
#define RCC_BDCR			*((u32*)(RCC_BASE_ADDRESS+0x20))
#define RCC_CSR				*((u32*)(RCC_BASE_ADDRESS+0x24))
/******************************************************************/

/*******************************Masks******************************/
/****************************CR Masks******************************/
#define RCC_CR_CLEAR_MASK	((u32)0x0)
#define HSI_ON_MASK 				((u32)0x1)
#define HSI_READY_MASK			((u32)0x2)
#define HSE_ON_MASK			((u32)0x10000)
#define HSE_READY_MASK		((u32)0x20000)
#define PLL_ON_MASK			((u32)0x1000000)
#define PLL_READY_MASK		((u32)0x2000000)
/****************************CRGR Masks****************************/
#define SW_HSI_CLOCK		((u32)0x0)
#define SW_HSE_CLOCK		((u32)0x1)
#define SW_PLL_CLOCK		((u32)0x2)
#define SW_CLEAR_MASK		((u32)0x3)

#define SWS_HSI_MASK		((u32)0x1)
#define SWS_HSE_MASK		((u32)0x4)
#define SWS_PLL_MASK		((u32)0x8)
/******************************************************************/
/**************************Peripherals Masks**************************/
#define PORTA_MASK		 ((u32) 0x4)
#define PORTB_MASK		 ((u32) 0x8)
#define PORTC_MASK		 ((u32) 0x10)
#define PORTD_MASK		 ((u32) 0x20)
#define PORTE_MASK		 ((u32) 0x40)
#define PORTF_MASK		 ((u32) 0x80)
#define PORTG_MASK		 ((u32) 0x100)
#define PORTH_MASK		 ((u32) 0x200)


/*Description: This API will be used by
the user to enable HSI, it will take 
no inputs and return nothing		 */
void RCC_set_HSI_Status(u8 state)
{
	if (state == 1)
	{
	/*CR Register value will be ORed with HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= HSI_ON_MASK;
	}
	else if (state==0)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit														*/
	RCC_CR &= ~HSI_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of HSI, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
status_enum RCC_get_HSI_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & HSI_READY_MASK)
	{
		return STATUS_OK;
	}
	else
	{
		return STATUS_NOK;
	}
}

/*Description: This API will be used by
the user to enable or disable HSI, it 
will take input from user which represents state 
and return nothing */
void RCC_set_HSE_Status(u8 state)
{

	if (state == 1)
	{
	/*CR Register value will be ORed with HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= HSE_ON_MASK;
	}
	else if (state==0)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit												*/
	RCC_CR &= ~HSE_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of HSE, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
status_enum RCC_get_HSE_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & HSE_READY_MASK)
	{
		return STATUS_OK;
	}
	else
	{
		return STATUS_NOK;
	}
}

/*Description: This API will be used by
the user to enable PLL, it will take 
no inputs and return nothing		 */
void RCC_set_PLL_Status(u8 state)
{
	if (state == 1)
	{
	/*CR Register value will be ORed with HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= PLL_ON_MASK;
	}
	else if (state==0)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit														*/
	RCC_CR &= ~PLL_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of PLL, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
status_enum RCC_get_PLL_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & PLL_READY_MASK)
	{
		return STATUS_OK;
	}
	else
	{
		return STATUS_NOK;
	}
}

/*Description: This API will be used by
the user to select HSI as the System Clock */
void RCC_SW_Select_Clock(u32 clock)
{
	/*This local variable will be used to save current state of CFGR
	so that we will do the operation on it and then save its state
	again in the CFGR*/
	u32 Local_u32CFGRValue=0;
	
	if (clock == 10)
	{
		Local_u32CFGRValue = RCC_CFGR;
		Local_u32CFGRValue &= ~SW_CLEAR_MASK;
		Local_u32CFGRValue |= SW_HSI_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
	else if (clock == 11)
	{
		Local_u32CFGRValue = RCC_CFGR;
		Local_u32CFGRValue &= ~SW_CLEAR_MASK;
		Local_u32CFGRValue |= SW_HSE_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
	else if (clock == 12)
	{
		Local_u32CFGRValue = RCC_CFGR;
		Local_u32CFGRValue &= ~SW_CLEAR_MASK;
		Local_u32CFGRValue |= SW_PLL_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
}

/*Description: This API will be used by
the user to get current working clock, it 
will not take input from user and returns
the state as u8								*/
sws_enum RCC_get_SWS_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (!(RCC_CFGR & SWS_HSI_MASK))
	{
		return SWS_HSI;
	}
	
	else if (RCC_CFGR & SWS_HSE_MASK)
	{
		return SWS_HSE;
	}
	else if (RCC_CFGR & SWS_PLL_MASK)
	{
		return SWS_PLL;
	}
	}
	/*Description: This API will be used by
the user to disable ports clock					*/
void RCC_Enable_Peripheral_Clock(u8 Copy_u8Peripheral)
	{
		switch (Copy_u8Peripheral)
	{
		case 0:
			RCC_APB2ENR |= PORTA_MASK;
			break;
		case 1:
			RCC_APB2ENR |= PORTB_MASK;
			break;
		case 2:
			RCC_APB2ENR |= PORTC_MASK;
			break;
		case 3:
			RCC_APB2ENR |= PORTD_MASK;
			break;
		case 4:
			RCC_APB2ENR |= PORTE_MASK;
			break;
		case 5:
			RCC_APB2ENR |= PORTF_MASK;
			break;
		case 6:
			RCC_APB2ENR |= PORTG_MASK;
			break;
		case 7:
			RCC_APB2ENR |= PORTH_MASK;
			break;
	}
	}

	/*Description: This API will be used by
the user to disable ports clock					*/
void RCC_Disable_Peripheral_Clock(u8 Copy_u8Peripheral)
	{
		switch (Copy_u8Peripheral)
	{
		case 0:
			RCC_APB2ENR &= ~PORTA_MASK;
			break;
		case 1:
			RCC_APB2ENR &=~ PORTB_MASK;
			break;
		case 2:
			RCC_APB2ENR &= ~PORTC_MASK;
			break;
		case 3:
			RCC_APB2ENR &= ~PORTD_MASK;
			break;
		case 4:
			RCC_APB2ENR &= ~PORTE_MASK;
			break;
		case 5:
			RCC_APB2ENR &= ~PORTF_MASK;
			break;
		case 6:
			RCC_APB2ENR &= ~PORTG_MASK;
			break;
		case 7:
			RCC_APB2ENR &= ~PORTH_MASK;
			break;
	}
	}

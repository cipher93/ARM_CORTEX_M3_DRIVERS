/***************************************/
/*Author: Mahmoud Hamdy ****************/
/*Date	: 29/02/2020********************/
/***************************************/

/*Changelog from version 1.0
* 1) Changed ENUMs for return status to #define
  2) Added RCC prefix to macros for better use
  3) Changed names of parameters to match naming convention
  4) Changed some magic numbers in functions to their respective macros
  5) Added return status to enable/disable peripheral functions
  6) Added return type to function names
  7) Added new APIs for controlling MCO and PLL
*/


/*Libraries Inclusion				   */
/*Library Layer						   */
/*This is the library that will contain the standard types 
that we will use like u8, u16, etc.*/
#include "STD_TYPES.h"

/*Current Library Layer*/
#include "RCC_interface.h"

/*****************************Registers*****************************/
/*Base address for RCC which will be used to reach peripherals by adding offset to it*/
#define RCC_BASE_ADDRESS 								(u32)0x40021000

/*Offset Addresses for peripherals*/
#define RCC_CR 													*((u32*)(RCC_BASE_ADDRESS+0x00))
#define RCC_CFGR 												*((u32*)(RCC_BASE_ADDRESS+0x04))
#define RCC_CIR 													*((u32*)(RCC_BASE_ADDRESS+0x08))
#define RCC_APB2RSTR											*((u32*)(RCC_BASE_ADDRESS+0x0C))
#define RCC_APB1RSTR											*((u32*)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHBENR											*((u32*)(RCC_BASE_ADDRESS+0x14))
#define RCC_APB2ENR											*((u32*)(RCC_BASE_ADDRESS+0x18))
#define RCC_APB1ENR											*((u32*)(RCC_BASE_ADDRESS+0x1C))
#define RCC_BDCR												*((u32*)(RCC_BASE_ADDRESS+0x20))
#define RCC_CSR													*((u32*)(RCC_BASE_ADDRESS+0x24))
/******************************************************************/

/*******************************Masks******************************/
/****************************CR Masks******************************/
#define RCC_CR_CLEAR_MASK								((u32)0x0)
#define RCC_HSI_ON_MASK 									((u32)0x1)
#define RCC_HSI_READY_MASK								((u32)0x2)
#define RCC_HSE_ON_MASK									((u32)0x10000)
#define RCC_HSE_READY_MASK							((u32)0x20000)
#define RCC_PLL_ON_MASK									((u32)0x1000000)
#define RCC_PLL_READY_MASK								((u32)0x2000000)
/****************************CRGR Masks****************************/
#define RCC_SW_HSI_CLOCK								((u32)0x0)
#define RCC_SW_HSE_CLOCK								((u32)0x1)
#define RCC_SW_PLL_CLOCK									((u32)0x2)
#define RCC_SW_CLEAR_MASK								((u32)0x3)

#define RCC_SWS_HSI_MASK								((u32)0x1)
#define RCC_SWS_HSE_MASK								((u32)0x4)
#define RCC_SWS_PLL_MASK								((u32)0x8)

#define RCC_MCO_CLEAR										((u32)0xF0FFFFFF)
#define RCC_MCO_NOCLOCK_CONFIG					((u32)0x03000000)
#define RCC_MCO_HSI_CONFIG								((u32)0x05000000)
#define RCC_MCO_HSE_CONFIG							((u32)0x06000000)
#define RCC_MCO_PLL_DIVIDED_2_CONFIG			((u32)0x07000000)

#define RCC_PLL_CLEAR										((u32)0xFFC0FFFF)
#define RCC_PLL_SOURCE_HSI2_CONFIG				((u32)0xFFFEFFFF)
#define RCC_PLL_SOURCE_HSE_CONFIG				((u32)0x00010000)

#define RCC_PLL_HSE_NO_DIVIDER_CONFIG			((u32)0xFFFDFFFF)
#define RCC_PLL_HSE_DIVIDER_CONFIG				((u32)0x00020000)
	
#define RCC_PLL_MULTIPLIER_2_CONFIG					((u32)0xFFC3FFFF)
#define RCC_PLL_MULTIPLIER_3_CONFIG					((u32)0x00040000)
#define RCC_PLL_MULTIPLIER_4_CONFIG					((u32)0x00080000)
#define RCC_PLL_MULTIPLIER_5_CONFIG					((u32)0x000C0000)
#define RCC_PLL_MULTIPLIER_6_CONFIG					((u32)0x00100000)
#define RCC_PLL_MULTIPLIER_7_CONFIG					((u32)0x00140000)
#define RCC_PLL_MULTIPLIER_8_CONFIG					((u32)0x00180000)
#define RCC_PLL_MULTIPLIER_9_CONFIG					((u32)0x001C0000)
#define RCC_PLL_MULTIPLIER_10_CONFIG				((u32)0x00200000)
#define RCC_PLL_MULTIPLIER_11_CONFIG				((u32)0x00240000)
#define RCC_PLL_MULTIPLIER_12_CONFIG				((u32)0x00280000)
#define RCC_PLL_MULTIPLIER_13_CONFIG				((u32)0x002C0000)
#define RCC_PLL_MULTIPLIER_14_CONFIG				((u32)0x00300000)
#define RCC_PLL_MULTIPLIER_15_CONFIG				((u32)0x00340000)
#define RCC_PLL_MULTIPLIER_16_CONFIG				((u32)0x00380000)
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
void RCC_voidSet_HSI_Status(u8 Copy_u8State)
{
	if (Copy_u8State == RCC_ENABLE_CLOCK)
	{
	/*CR Register value will be ORed with RCC_HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= RCC_HSI_ON_MASK;
	}
	else if (Copy_u8State==RCC_DISABLE_CLOCK)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit														*/
	RCC_CR &= ~RCC_HSI_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of HSI, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
u8 RCC_u8Get_HSI_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & RCC_HSI_READY_MASK)
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
will take input from user which represents Copy_u8State 
and return nothing */
void RCC_voidSet_HSE_Status(u8 Copy_u8State)
{

	if (Copy_u8State == RCC_ENABLE_CLOCK)
	{
	/*CR Register value will be ORed with RCC_HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= RCC_HSE_ON_MASK;
	}
	else if (Copy_u8State==RCC_DISABLE_CLOCK)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit												*/
	RCC_CR &= ~RCC_HSE_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of HSE, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
u8 RCC_u8Get_HSE_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & RCC_HSE_READY_MASK)
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
void RCC_voidSet_PLL_Status(u8 Copy_u8State)
{
	if (Copy_u8State == RCC_ENABLE_CLOCK)
	{
	/*CR Register value will be ORed with RCC_HSI_ON_MASK to enable only
	this bit														*/
	RCC_CR |= RCC_PLL_ON_MASK;
	}
	else if (Copy_u8State==RCC_DISABLE_CLOCK)
	{
	/*CR Register value will be ANDed with complement HSI_OFF_MASK to disable
	this bit														*/
	RCC_CR &= ~RCC_PLL_ON_MASK;
	}
}

/*Description: This API will be used by
the user to check status of PLL, it will take 
no inputs and return the enum value
that either represents OK or NOK*/
u8 RCC_u8Get_PLL_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (RCC_CR & RCC_PLL_READY_MASK)
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
void RCC_voidSW_Select_Clock(u32 Copy_u8Clock)
{
	/*This local variable will be used to save current Copy_u8State of CFGR
	so that we will do the operation on it and then save its Copy_u8State
	again in the CFGR*/
	u32 Local_u32CFGRValue;

	/*Clear The value retrived from the registers so that it will be ready for values to be written on it*/
	Local_u32CFGRValue = RCC_CFGR;
	Local_u32CFGRValue &= ~RCC_SW_CLEAR_MASK;
	
	if (Copy_u8Clock == RCC_HSI)
	{
		Local_u32CFGRValue |= RCC_SW_HSI_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
	else if (Copy_u8Clock == RCC_HSE)
	{
		Local_u32CFGRValue |= RCC_SW_HSE_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
	else if (Copy_u8Clock == RCC_PLL)
	{
		Local_u32CFGRValue |= RCC_SW_PLL_CLOCK;
		RCC_CFGR=Local_u32CFGRValue;
	}
}

/*Description: This API will be used by
the user to get current working system clock
Input: None
Return: The clock currently selected*/
u8 RCC_u8Get_SWS_Status()
{
	/*The CR value will be ANDed with the ready mask. If it returns 
	a value, it means that it is ready. If it returns zero, then it is not*/
	if (!(RCC_CFGR & RCC_SWS_HSI_MASK))
	{
		return RCC_SWS_HSI;
	}
	
	else if (RCC_CFGR & RCC_SWS_HSE_MASK)
	{
		return RCC_SWS_HSE;
	}
	else if (RCC_CFGR & RCC_SWS_PLL_MASK)
	{
		return RCC_SWS_PLL;
	}
}

/*Description: This API will be used by
the user to enable ports clock
INPUT: Desired Peripheral Name
Return: Status of operation (OK or NOK)					*/
u8 RCC_u8Enable_Peripheral_Clock(u8 Copy_u8Peripheral)
	{
		switch (Copy_u8Peripheral)
	{
		case PORTA:
			RCC_APB2ENR |= PORTA_MASK;
			return STATUS_OK;
		case PORTB:
			RCC_APB2ENR |= PORTB_MASK;
			return STATUS_OK;
		case PORTC:
			RCC_APB2ENR |= PORTC_MASK;
			return STATUS_OK;
		case PORTD:
			RCC_APB2ENR |= PORTD_MASK;
			return STATUS_OK;
		case PORTE:
			RCC_APB2ENR |= PORTE_MASK;
			return STATUS_OK;
		case PORTF:
			RCC_APB2ENR |= PORTF_MASK;
			return STATUS_OK;
		case PORTG:
			RCC_APB2ENR |= PORTG_MASK;
			return STATUS_OK;
		case PORTH:
			RCC_APB2ENR |= PORTH_MASK;
			return STATUS_OK;
		/*If a wrong port was chosen, return error status*/
		default:
			return STATUS_NOK;
	}
	}

/*Description: This API will be used by
the user to disable ports clock
INPUT: Desired Peripheral Name
Return: Status of operation (OK or NOK)					*/
u8 RCC_u8Disable_Peripheral_Clock(u8 Copy_u8Peripheral)
	{
		switch (Copy_u8Peripheral)
	{
		case PORTA:
			RCC_APB2ENR &= ~PORTA_MASK;
			return STATUS_OK;
		case PORTB:
			RCC_APB2ENR &=~ PORTB_MASK;
			return STATUS_OK;
		case PORTC:
			RCC_APB2ENR &= ~PORTC_MASK;
			return STATUS_OK;
		case PORTD:
			RCC_APB2ENR &= ~PORTD_MASK;
			return STATUS_OK;
		case PORTE:
			RCC_APB2ENR &= ~PORTE_MASK;
			return STATUS_OK;
		case PORTF:
			RCC_APB2ENR &= ~PORTF_MASK;
			return STATUS_OK;
		case PORTG:
			RCC_APB2ENR &= ~PORTG_MASK;
			return STATUS_OK;
		case PORTH:
			RCC_APB2ENR &= ~PORTH_MASK;
			return STATUS_OK;
		/*If a wrong port was chosen, return error status*/
		default:
			return STATUS_NOK;
	}
	}

	
/*Description: This API will be used to determine configuration
of MCO
Input: Desired clock
Return: State of operation (OK or NOK)
*/
u8 RCC_u8MCO_Clock (u8 Copy_u8Clock)
{
	/*Operations will be done first on local variable, then the value will be transferred to the register
	This is done because sometimes hardware restrictions can make conflicts*/
	u32 Local_u32CFGRValue;
	Local_u32CFGRValue = RCC_CFGR;
	
	/*Clear Values inside the register*/
	Local_u32CFGRValue &= RCC_MCO_CLEAR;

	/*According to user input, write the desired value in the local variable
	then transfer it to the register`*/
	if (Copy_u8Clock == RCC_MCO_NOCLOCK)
	{
		Local_u32CFGRValue |= RCC_MCO_NOCLOCK_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	
	else if (Copy_u8Clock == RCC_MCO_HSI)
	{
		Local_u32CFGRValue |= RCC_MCO_HSI_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	
	else if (Copy_u8Clock == RCC_MCO_HSE)
	{
		Local_u32CFGRValue |= RCC_MCO_HSE_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	
	else if (Copy_u8Clock == RCC_MCO_PLL_DIVIDED_2)
	{
		Local_u32CFGRValue |= RCC_MCO_PLL_DIVIDED_2_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	
	/*If nothing was executed properly, return that status is not ok*/
	return STATUS_NOK;
}

/*Description: This API will be used to determine configuration for the PLL clock
Inputs: 1) Source Clock
			2) HSE Divider (Choose no divider in case HSE was not chosen)
			3) PLL Multiplier
Return: Error Status*/
u8 RCC_u8PLL_Config (u8 Copy_u8SourceClock, u8 Copy_u8HSEDivider, u8 Copy_u8PLLMultiplier)
{
	/*Since configurations cannot be performed if PLL is enabled, the first thing to do will 
	be disabling the PLL and choosing another SW if it is the currently active SW*/
	u8 Local_u8ActiveSW;
	/*This variable will hold the value in CFGR and operations will be done on it*/
	u32 Local_u32CFGRValue;
	/*The return of this function indicates the current active clock*/
	Local_u8ActiveSW = RCC_u8Get_SWS_Status();
	/*If current active system clock is PLL, activate HSI and choose it as system clock so that we can be able to stop it*/
	if (Local_u8ActiveSW == RCC_SWS_PLL)
	{
		RCC_voidSet_HSI_Status(RCC_ENABLE_CLOCK);
		RCC_voidSW_Select_Clock(RCC_HSI);
	}
	/*Disable PLL*/
	RCC_voidSet_PLL_Status(RCC_DISABLE_CLOCK);
	
	/*Transfer register value in local variable just in case of hardware constraints
	and delete the value inside PLL*/
	Local_u32CFGRValue = RCC_CFGR;
	Local_u32CFGRValue &= RCC_PLL_CLEAR;
	
	/*Choose PLL source according to user input*/
	if (Copy_u8SourceClock == RCC_PLL_SOURCE_HSI2)
	{
		Local_u32CFGRValue &= RCC_PLL_SOURCE_HSI2_CONFIG;
	}
	else if (Copy_u8SourceClock == RCC_PLL_SOURCE_HSE)
	{
		Local_u32CFGRValue |= RCC_PLL_SOURCE_HSE_CONFIG;
	}
	
	/*Choose HSE divider*/
	if (Copy_u8HSEDivider == RCC_PLL_HSE_NO_DIVIDER)
	{
		Local_u32CFGRValue &= RCC_PLL_HSE_NO_DIVIDER_CONFIG;
	}
	else if (Copy_u8HSEDivider == RCC_PLL_HSE_DIVIDER)
	{
		Local_u32CFGRValue |= RCC_PLL_HSE_DIVIDER_CONFIG;
	}
	
	/*Choose PLL Multiplier*/
	if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_2)
	{
		Local_u32CFGRValue &= RCC_PLL_MULTIPLIER_2_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_3)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_3_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_4)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_4_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_5)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_5_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_6)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_6_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_7)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_7_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_8)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_8_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_9)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_9_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_10)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_10_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_11)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_11_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_12)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_12_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_13)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_13_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_14)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_14_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_15)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_15_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	else if (Copy_u8PLLMultiplier == RCC_PLL_MULTIPLIER_16)
	{
		Local_u32CFGRValue |= RCC_PLL_MULTIPLIER_16_CONFIG;
		RCC_CFGR = Local_u32CFGRValue;
		return STATUS_OK;
	}
	
	/*If an invalid multiplier was used, return not ok status*/
	return STATUS_NOK;
}

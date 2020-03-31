/*This driver is for controlling STM32  RCC*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/***************************************/
/*Author: Mahmoud Hamdy ****************/
/*Date	: 31/03/2020********************/
/***************************************/

#include "STD_TYPES.h"

/*Changelog from version 2.0
1) Added UART1 peripheral to list of peripherals
2) Added "RCC_PERIPHERALS" prefix to peripherals for easier access from autocomplete*/

/*Change log from version 1.1
1) Functions now work by passing mask as a parameters
*/
/*Changelog from version 1.0
*1) Changed ENUMs for return status to #define
  2) Added Header Guard
  3) Added RCC Prefix to macros for better use
  4) Added Casting for macros
  5) Added "extern" modifier for functions just in case a compiler ever needs it
  6) Added return type to function names
  7) Added new APIs for controlling MCO and PLL
*/


/*These macros will be used to define return status of SWS function*/
#define RCC_SWS_HSI						(u8)0
#define RCC_SWS_HSE						(u8)1
#define RCC_SWS_PLL						(u8)2


/********Clock Controls********/
#define RCC_ENABLE_HSI					RCC_HSI_ON_MASK
#define RCC_DISABLE_HSI				~RCC_HSI_ON_MASK
#define RCC_ENABLE_HSE					RCC_HSE_ON_MASK
#define RCC_DISABLE_HSE				~RCC_HSE_ON_MASK
#define RCC_ENABLE_PLL					RCC_PLL_ON_MASK
#define RCC_DISABLE_PLL					~RCC_PLL_ON_MASK
#define RCC_HSI_STATUS 				RCC_HSI_READY_MASK
#define RCC_HSE_STATUS 				HSE_READY_MASK
#define RCC_PLL_STATUS  				RCC_PLL_READY_MASK
	
/*SW Controls*/
#define RCC_SW_HSI					RCC_SW_HSI_CLOCK_MASK
#define RCC_SW_HSE					RCC_SW_HSE_CLOCK_MASK
#define RCC_SW_PLL						RCC_SW_PLL_CLOCK_MASK
	
/*MCO Controls*/
#define RCC_MCO_NOCLOCK					RCC_MCO_NOCLOCK_CONFIG
#define RCC_MCO_HSI							RCC_MCO_HSI_CONFIG
#define RCC_MCO_HSE							RCC_MCO_HSE_CONFIG
#define RCC_MCO_PLL_DIVIDED_2			RCC_MCO_PLL_DIVIDED_2_CONFIG
	
/*PLL Controls*/
/*Source Clock*/
#define RCC_PLL_SOURCE_HSI2			((u32)0xFFFEFFFF)
#define RCC_PLL_SOURCE_HSE				((u32)0x00010000)
/*HSE Divider*/
#define RCC_PLL_HSE_NO_DIVIDER		(u8)0
#define RCC_PLL_HSE_DIVIDER				(u8)1
/*PLL Multiplier*/
#define RCC_PLL_MULTIPLIER_2			(u8)0
#define RCC_PLL_MULTIPLIER_3			(u8)1
#define RCC_PLL_MULTIPLIER_4			(u8)2
#define RCC_PLL_MULTIPLIER_5			(u8)3
#define RCC_PLL_MULTIPLIER_6			(u8)4
#define RCC_PLL_MULTIPLIER_7			(u8)5
#define RCC_PLL_MULTIPLIER_8			(u8)6
#define RCC_PLL_MULTIPLIER_9			(u8)7
#define RCC_PLL_MULTIPLIER_10			(u8)8
#define RCC_PLL_MULTIPLIER_11			(u8)9
#define RCC_PLL_MULTIPLIER_12			(u8)10
#define RCC_PLL_MULTIPLIER_13			(u8)11
#define RCC_PLL_MULTIPLIER_14			(u8)12
#define RCC_PLL_MULTIPLIER_15			(u8)13
#define RCC_PLL_MULTIPLIER_16			(u8)14

/***************************/
/********Peripherals**********/
#define RCC_PERIPHERALS_PORTA 		PORTA_MASK
#define RCC_PERIPHERALS_PORTB 		PORTB_MASK
#define RCC_PERIPHERALS_PORTC 		PORTC_MASK
#define RCC_PERIPHERALS_PORTD 		PORTD_MASK
#define RCC_PERIPHERALS_PORTE 		PORTE_MASK
#define RCC_PERIPHERALS_PORTF 		PORTF_MASK
#define RCC_PERIPHERALS_PORTG 		PORTG_MASK
#define RCC_PERIPHERALS_PORTH 		PORTH_MASK
#define RCC_PERIPHERALS_USART1 	USART1_MASK

/*WARNING: Don't change anything in this section unless you are using a different microcontroller*/
/*********************************************************/
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
#define RCC_SW_HSI_CLOCK_MASK						((u32)0x0)
#define RCC_SW_HSE_CLOCK_MASK						((u32)0x1)
#define RCC_SW_PLL_CLOCK_MASK						((u32)0x2)
#define RCC_SW_CLEAR_MASK								((u32)0x3)

#define RCC_SWS_HSI_MASK								((u32)0x1)
#define RCC_SWS_HSE_MASK								((u32)0x4)
#define RCC_SWS_PLL_MASK								((u32)0x8)

#define RCC_MCO_CLEAR										((u32)0xF0FFFFFF)
#define RCC_MCO_NOCLOCK_CONFIG					((u32)0x03000000)
#define RCC_MCO_HSI_CONFIG								((u32)0x05000000)
#define RCC_MCO_HSE_CONFIG							((u32)0x06000000)
#define RCC_MCO_PLL_DIVIDED_2_CONFIG			((u32)0x07000000)

#define RCC_PLL_CLEAR									((u32)0xFFC0FFFF)
#define RCC_PLL_SOURCE_HSI2_MASK				((u32)0xFFFEFFFF)
#define RCC_PLL_SOURCE_HSE_MASK				((u32)0x00010000)

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
#define USART1_MASK		((u32)0x4000)
/*********************************************************/

/*Description: This API will either enable or disable the desired clock according to parameters passed
Parameters: Desired Status (u32)
Return: None
*/
extern void RCC_voidSetClockStatus(u32 Copy_u32DesiredClockStatus);

/*Description: This API will get the status of a clock whether it is enabled or disabled
Parameters: Desired Clock (u32)
Return: Status of clock*/
extern u8 RCC_u8GetClockStatus(u32 Copy_u32DesiredClock);

/*Description: This API will be used by
the user to select HSI as the System Clock 
Parameters: Desired Clock (u32)
Return: None*/
extern void RCC_voidSWSelectClock(u32 Copy_u32Clock);

/*Description: This API will be used by
the user to get current working clock, it 
will not take input from user and returns
the state as u8								*/
extern u8 RCC_u8GetSWSStatus();

/*Description: This API will be used by
the user to enable ports clock
INPUT: Desired Peripheral Name (u32)
Return: None*/
extern void RCC_voidEnablePeripheralClock(u32 Copy_u32Peripheral);

/*Description: This API will be used by
the user to disable ports clock
INPUT: Desired Peripheral Name(u32)
Return: None*/
extern void RCC_voidDisablePeripheralClock(u32 Copy_u32Peripheral);


/*Description: This API will be used to determine configuration
of MCO
Input: Desired clock (u32)
Return: None
*/
extern void RCC_voidMCOClock (u32 Copy_u32Clock);

/*Description: This API will be used to determine configuration for the PLL clock
Inputs: 1) Source Clock
			2) HSE Divider (Choose no divider in case HSE was not chosen)
			3) PLL Multiplier
Return: void*/
extern void RCC_voidPLLConfig (u32 Copy_u32SourceClock, u32 Copy_u32HSEDivider, u32 Copy_u32PLLMultiplier);


#endif

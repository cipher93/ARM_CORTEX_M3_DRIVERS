/*This driver is for controlling STM32  RCC*/

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/***************************************/
/*Author: Mahmoud Hamdy ****************/
/*Date	: 29/02/2020********************/
/***************************************/

#include "STD_TYPES.h"

/*Changelog from version 1.0
*1) Changed ENUMs for return status to #define
  2) Added Header Guard
  3) Added RCC Prefix to macros for better use
  4) Added Casting for macros
  5) Added "extern" modifier for functions just in case a compiler ever needs it
  6) Added return type to function names
  7) Added new APIs for controlling MCO and PLL
*/



/*These macros will be used to define return status of a function*/
#define STATUS_OK					(u8)0
#define STATUS_NOK				(u8)1

/*These macros will be used to define return status of SWS function*/
#define RCC_SWS_HSI						(u8)0
#define RCC_SWS_HSE						(u8)1
#define RCC_SWS_PLL						(u8)2


/********Clock Controls********/
/*Use one of the following Parameters:
ENABLE--> To enable a clock
DISABLE --> To disable a clock
HSI -->	Choose HSI as system Clock
HSE --> Choose HSE as system clock
PLL --> Choose PLL as system clock*/
#define RCC_ENABLE_CLOCK 		(u8)1
#define RCC_DISABLE_CLOCK		(u8)0
#define RCC_HSI 			(u8)0
#define RCC_HSE			(u8)1
#define RCC_PLL			(u8)2

/*MCO Controls*/
#define RCC_MCO_NOCLOCK					(u8)0
#define RCC_MCO_HSI							(u8)1
#define RCC_MCO_HSE							(u8)2
#define RCC_MCO_PLL_DIVIDED_2			(u8)3
	
/*PLL Controls*/
/*Source Clock*/
#define RCC_PLL_SOURCE_HSI2			(u8)0
#define RCC_PLL_SOURCE_HSE				(u8)1
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
#define PORTA 		(u8)0
#define PORTB 		(u8)1
#define PORTC 		(u8)2
#define PORTD 		(u8)3
#define PORTE 		(u8)4
#define PORTF 		(u8)5
#define PORTG 		(u8)6
#define PORTH 		(u8)7

/*Description: This API will be used by
the user to enable or disable HSI, it 
will take input from user which represents state 
and return nothing */
extern void RCC_voidSet_HSI_Status(u8 Copy_u8State);

/*Description: This API will be used by
the user to check status of HSI, it 
will not take input from user and returns
the state as u8*/
extern u8 RCC_u8Get_HSI_Status();

/*Description: This API will be used by
the user to enable HSE, it will take 
no inputs and return nothing		 */
extern void RCC_voidSet_HSE_Status(u8 Copy_u8State);

/*Description: This API will be used by
the user to check status of HSE, it 
will not take input from user and returns
the state as u8*/
extern u8 RCC_u8Get_HSE_Status();


/*Description: This API will be used by
the user to enable HSE, it will take 
no inputs and return nothing		 */
extern void RCC_voidSet_PLL_Status(u8 Copy_u8State);

/*Description: This API will be used by
the user to check status of HSE, it 
will not take input from user and returns
the state as u8*/
extern u8 RCC_u8Get_PLL_Status();

/*Description: This API will be used by
the user to select HSI as the System Clock */
extern void RCC_voidSW_Select_Clock(u32 Copy_u32Clock);

/*Description: This API will be used by
the user to get current working clock, it 
will not take input from user and returns
the state as u8								*/
extern u8 RCC_u8Get_SWS_Status();

/*Description: This API will be used by
the user to enable ports clock
INPUT: Desired Peripheral Name
Return: Status of operation (OK or NOK)					*/
extern u8 RCC_u8Enable_Peripheral_Clock(u8 Copy_u8Peripheral);

/*Description: This API will be used by
the user to disable ports clock
INPUT: Desired Peripheral Name
Return: Status of operation (OK or NOK)					*/
extern u8 RCC_u8Disable_Peripheral_Clock(u8 Copy_u8Peripheral);


/*Description: This API will be used to determine configuration
of MCO
Input: Desired clock
Return: State of operation (OK or NOK)*/
extern u8 RCC_u8MCO_Clock (u8 Copy_u8Clock);

/*Description: This API will be used to determine configuration for the PLL clock
Inputs: 1) Source Clock
			2) HSE Divider (Choose no divider in case HSE was not chosen)
			3) PLL Multiplier
Return: Error Status*/
extern u8 RCC_u8PLL_Config (u8 Copy_u8SourceClock, u8 Copy_u8HSEDivider, u8 Copy_u8PLLMultiplier);


#endif

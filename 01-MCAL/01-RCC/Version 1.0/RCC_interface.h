/***************************************/
/*Author: Mahmoud Hamdy ****************/
/*Date	: 15/01/2020********************/
/***************************************/

/*This driver is for controlling STM32  RCC*/


/*This enum will be used for the return status of ready functions*/
typedef enum{
	STATUS_OK,
	STATUS_NOK
}status_enum;

/*This enum will be used for the return status of SWS function*/
typedef enum{
	SWS_HSI,
	SWS_HSE,
	SWS_PLL
}sws_enum;
/********Clock Controls********/
/*Use one of the following Parameters:
ENABLE--> To enable a clock
DISABLE --> To disable a clock
HSI -->	Choose HSI as system Clock
HSE --> Choose HSE as system clock
PLL --> Choose PLL as system clock*/
#define ENABLE 		1
#define DISABLE		0
#define HSI 		10
#define HSE			11
#define PLL			12
/***************************/
/********Peripherals**********/
#define PORTA 		0
#define PORTB 		1
#define PORTC 		2
#define PORTD 		3
#define PORTE 		4
#define PORTF 		5
#define PORTG 		6
#define PORTH 		7

/*Description: This API will be used by
the user to enable or disable HSI, it 
will take input from user which represents state 
and return nothing */
void RCC_set_HSI_Status(u8 state);

/*Description: This API will be used by
the user to check status of HSI, it 
will not take input from user and returns
the state as u8*/
status_enum RCC_get_HSI_Status();

/*Description: This API will be used by
the user to enable HSE, it will take 
no inputs and return nothing		 */
void RCC_set_HSE_Status(u8 state);

/*Description: This API will be used by
the user to check status of HSE, it 
will not take input from user and returns
the state as u8*/
status_enum RCC_get_HSE_Status();


/*Description: This API will be used by
the user to enable HSE, it will take 
no inputs and return nothing		 */
void RCC_set_PLL_Status(u8 state);

/*Description: This API will be used by
the user to check status of HSE, it 
will not take input from user and returns
the state as u8*/
status_enum RCC_get_PLL_Status();

/*Description: This API will be used by
the user to select HSI as the System Clock */
void RCC_SW_Select_Clock(u32 clock);

/*Description: This API will be used by
the user to get current working clock, it 
will not take input from user and returns
the state as u8								*/
sws_enum RCC_get_SWS_Status();

/*Description: This API will be used by
the user to enable ports clock					*/
void RCC_Enable_Peripheral_Clock(u8 Copy_u8Peripheral);

/*Description: This API will be used by
the user to disbale ports clock					*/
void RCC_Disable_Peripheral_Clock(u8 Copy_u8Peripheral);


/*****************************************************/
/*Author  : Mahmoud Hamdy							*/
/*Version : V01			 							*/
/*Date	  :2020-03-18								*/
/*****************************************************/
#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

#include "SYSTICK_interface.h"

/*This configuration parameter is used to determine clock source.
 * The available options are:
 * SYSTICK_CLK_AHB --> Sets the SYSTICK clock to AHB
 * SYSTICK_CLK_AHB8--> Sets the SYSTICK clock to AHB/8
 * Note: If a wrong value was used, the default value will be used which is:SYSTICK_CLK_AHB8 */
#define		SYSTICK_SOURCE_CLK_CONFIG			SYSTICK_CLK_AHB

/*This configuration parameter is used to set interrupt.
 * The available options are:
 * SYSTICK_INTERRUPT_ENABLE --> Enables Interrupt on clock overflow
 * SYSTICK_INTERRUPT_DISABLE--> Disables Interrupt on clock overflow
 * Note: If a wrong value was used, the default value will be used which is:SYSTICK_INTERRUPT_DISABLE */
#define		SYSTICK_INTERRUPT_CONFIG			SYSTICK_INTERRUPT_ENABLE


/*This configuration parameter is used to set threshold value for the systick
 * The available options are:
 * Any value between (0x01) and (0x00FFFFFF)
 * Note: If a wrong value was used, the system will misbehave */
#define		SYSTICK_RELOAD_VALUE			0x00FFFFFF

#endif

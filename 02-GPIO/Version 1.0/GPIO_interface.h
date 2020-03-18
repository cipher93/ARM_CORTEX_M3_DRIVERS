/*****************************************************/
/*Author  : Mahmoud Hamdy							*/
/*Version : V01			 							*/
/*Date	  :2020-03-01								*/
/*****************************************************/
#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*Libraries*/
#include "STD_TYPES.h"

/*Macros*/
/*Ports*/
#define GPIO_PORT_A						(u8)0
#define GPIO_PORT_B						(u8)1
#define GPIO_PORT_C						(u8)2
#define GPIO_PORT_D						(u8)3
#define GPIO_PORT_E						(u8)4
#define GPIO_PORT_F						(u8)5
#define GPIO_PORT_G						(u8)6
#define GPIO_PORT_H						(u8)7
/*Pins*/
#define GPIO_PIN0							(u8)0
#define GPIO_PIN1							(u8)1
#define GPIO_PIN2							(u8)2
#define GPIO_PIN3							(u8)3
#define GPIO_PIN4							(u8)4
#define GPIO_PIN5							(u8)5
#define GPIO_PIN6							(u8)6
#define GPIO_PIN7							(u8)7
#define GPIO_PIN8							(u8)8
#define GPIO_PIN9							(u8)9
#define GPIO_PIN10							(u8)10
#define GPIO_PIN11							(u8)11
#define GPIO_PIN12							(u8)12
#define GPIO_PIN13							(u8)13
#define GPIO_PIN14							(u8)14
#define GPIO_PIN15							(u8)15

/*Modes*/
/*Speed*/
#define GPIO_SPEED_INPUT				(u8)0
#define GPIO_SPEED_OUTPUT_10		(u8)1
#define GPIO_SPEED_OUTPUT_2		(u8)2
#define GPIO_SPEED_OUTPUT_50		(u8)3
/*Modes*/
#define GPIO_MODE_INPUT_ANALOG							(u8)0
#define GPIO_MODE_INPUT_FLOATING						(u8)1
#define GPIO_MODE_INPUT_PULL								(u8)2

/*OUTPUT*/
#define GPIO_MODE_OUTPUT_PUSHPULL					(u8)3
#define GPIO_MODE_OUTPUT_OPENDRAIN					(u8)4
#define GPIO_MODE_OUTPUT_AF_PUSHPULL				(u8)5
#define GPIO_MODE_OUTPUT_AF_OPENDRAIN			(u8)6

/*Create New Struct Type which represents GPIO pin and its parameters*/
typedef struct{
u8 port;
u8 pin;
u8 speed;
u8 mode;
}GPIO_t;


/*APIs*/
/*Description: This API will be used to configure specific pin on a specific port
Input: Pointer to desired GPIO struct
Return: None*/
extern void GPIO_voidConfigurePin(GPIO_t* DesiredGPIO);

/*Description: This API will be used to get value of a specific pin
Input: Pointer to desired GPIO struct
Return: Pin Status (The value inside IDR) as (u16)
*/
extern u16 GPIO_u16GetPinStatus (GPIO_t* DesiredGPIO);

/*Description: This API will be used to write desired value on a pin through the ODR register
Parameters: Desired pin (pointer to struct), Desired value to be written (u8)
Return: None*/
extern void GPIO_voidWriteOutput (GPIO_t* DesiredGPIO, u8 Copy_u8DesiredValue);
#endif

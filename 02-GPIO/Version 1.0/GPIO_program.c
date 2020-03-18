/*****************************************************/
/*Author  : Mahmoud Hamdy							               */
/*Version : V01			 							                   */
/*Date	  :2020-03-01								*/
/*****************************************************/

#include "GPIO_interface.h"


/*Base Addresses*/
#define GPIO_PORTA_BASE_ADDRESS 					(u32)0x40010800
#define GPIO_PORTB_BASE_ADDRESS 					(u32)0x40010C00
#define GPIO_PORTC_BASE_ADDRESS 					(u32)0x40011000
#define GPIO_PORTD_BASE_ADDRESS 					(u32)0x40014000
#define GPIO_PORTE_BASE_ADDRESS 					(u32)0x40018000
#define GPIO_PORTF_BASE_ADDRESS 					(u32)0x40011C00
#define GPIO_PORTG_BASE_ADDRESS 					(u32)0x40012000
#define GPIO_PORTH_BASE_ADDRESS 					(u32)0x40012400
	

/*PORT Registers*/
/*PORTA*/
#define GPIO_PORTA_CRL										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTA_CRH										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTA_IDR										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTA_ODR										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTA_BSR										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTA_BRR										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTA_LCK										*((u32*)(GPIO_PORTA_BASE_ADDRESS + (u32)0x18))

/*PORTB*/
#define GPIO_PORTB_CRL										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTB_CRH										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTB_IDR										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTB_ODR										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTB_BSR										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTB_BRR										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTB_LCK										*((u32*)(GPIO_PORTB_BASE_ADDRESS + (u32)0x18))
	
/*PORTC*/
#define GPIO_PORTC_CRL										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTC_CRH										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTC_IDR										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTC_ODR										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTC_BSR										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTC_BRR										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTC_LCK										*((u32*)(GPIO_PORTC_BASE_ADDRESS + (u32)0x18))
	
/*PORTD*/
#define GPIO_PORTD_CRL										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTD_CRH										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTD_IDR										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTD_ODR										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTD_BSR										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTD_BRR										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTD_LCK										*((u32*)(GPIO_PORTD_BASE_ADDRESS + (u32)0x18))
	
/*PORTE*/
#define GPIO_PORTE_CRL										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTE_CRH										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTE_IDR										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTE_ODR										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTE_BSR										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTE_BRR										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTE_LCK										*((u32*)(GPIO_PORTE_BASE_ADDRESS + (u32)0x18))
	
/*PORTF*/
#define GPIO_PORTF_CRL										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTF_CRH										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTF_IDR										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTF_ODR										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTF_BSR										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTF_BRR										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTF_LCK										*((u32*)(GPIO_PORTF_BASE_ADDRESS + (u32)0x18))
	
/*PORTG*/
#define GPIO_PORTG_CRL										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTG_CRH										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTG_IDR										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTG_ODR										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTG_BSR										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTG_BRR										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTG_LCK										*((u32*)(GPIO_PORTG_BASE_ADDRESS + (u32)0x18))
	
/*PORTH*/
#define GPIO_PORTH_CRL										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x00))
#define GPIO_PORTH_CRH										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x04))
#define GPIO_PORTH_IDR										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x08))
#define GPIO_PORTH_ODR										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x0C))
#define GPIO_PORTH_BSR										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x10))
#define GPIO_PORTH_BRR										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x14))
#define GPIO_PORTH_LCK										*((u32*)(GPIO_PORTH_BASE_ADDRESS + (u32)0x18))


/*Modes*/
/*INPUT*/
#define GPIO_MODE_INPUT_ANALOG_MASK							(u32)0b0011
#define GPIO_MODE_INPUT_FLOATING_MASK						(u32)0b0100
#define GPIO_MODE_INPUT_PULL_MASK							(u32)0b1000

/*OUTPUT*/
#define GPIO_MODE_OUTPUT_PUSHPULL_MASK					(u32)0b0011
#define GPIO_MODE_OUTPUT_OPENDRAIN_MASK					(u32)0b0100
#define GPIO_MODE_OUTPUT_AF_PUSHPULL_MASK				(u32)0b1000
#define GPIO_MODE_OUTPUT_AF_OPENDRAIN_MASK				(u32)0b1100

/*Speed*/
#define GPIO_SPEED_INPUT_MASK							(u32)0b1100
#define GPIO_SPEED_OUTPUT_10_MASK					(u32)0b0001
#define GPIO_SPEED_OUTPUT_2_MASK						(u32)0b0010
#define GPIO_SPEED_OUTPUT_50_MASK					(u32)0b0011

	
/*Shift Macros*/
/*These macros will be used to shift the mode and speed bits to its specific pin inside the register*/
#define GPIO_PIN0_SHIFT_MASK										(u8)0
#define GPIO_PIN1_SHIFT_MASK										(u8)4
#define GPIO_PIN2_SHIFT_MASK										(u8)8
#define GPIO_PIN3_SHIFT_MASK										(u8)12
#define GPIO_PIN4_SHIFT_MASK										(u8)16
#define GPIO_PIN5_SHIFT_MASK										(u8)20
#define GPIO_PIN6_SHIFT_MASK										(u8)24
#define GPIO_PIN7_SHIFT_MASK										(u8)28

/*Pin clear Mask*/
#define GPIO_PIN0_CLEAR_MASK										(u32)0xFFFFFFF0
#define GPIO_PIN1_CLEAR_MASK										(u32)0xFFFFFF0F
#define GPIO_PIN2_CLEAR_MASK										(u32)0xFFFFF0FF
#define GPIO_PIN3_CLEAR_MASK										(u32)0xFFFF0FFF
#define GPIO_PIN4_CLEAR_MASK										(u32)0xFFF0FFFF
#define GPIO_PIN5_CLEAR_MASK										(u32)0xFF0FFFFF
#define GPIO_PIN6_CLEAR_MASK										(u32)0xF0FFFFFF
#define GPIO_PIN7_CLEAR_MASK										(u32)0x0FFFFFFF
	
/*Pins Read/write Mask*/
/*These masks will be used with the following registers
IDR: Reading a specific Pin
BSRR: Setting a specific pin
BRR: Resetting a specific pin
*/
#define GPIO_PIN0_RW_MASK										(u32)0x00000001
#define GPIO_PIN1_RW_MASK										(u32)0x00000002
#define GPIO_PIN2_RW_MASK										(u32)0x00000004
#define GPIO_PIN3_RW_MASK										(u32)0x00000008
#define GPIO_PIN4_RW_MASK										(u32)0x00000010
#define GPIO_PIN5_RW_MASK										(u32)0x00000020
#define GPIO_PIN6_RW_MASK										(u32)0x00000040
#define GPIO_PIN7_RW_MASK										(u32)0x00000080
#define GPIO_PIN8_RW_MASK										(u32)0x00000100
#define GPIO_PIN9_RW_MASK										(u32)0x00000200
#define GPIO_PIN10_RW_MASK										(u32)0x00000400
#define GPIO_PIN11_RW_MASK										(u32)0x00000800
#define GPIO_PIN12_RW_MASK										(u32)0x00001000
#define GPIO_PIN13_RW_MASK										(u32)0x00002000
#define GPIO_PIN14_RW_MASK										(u32)0x00004000
#define GPIO_PIN15_RW_MASK										(u32)0x00008000


#define GPIO_PINS_PER_REGISTER									(u8)8

/*Functions*/
/*Description: This API will be used to configure specific pin on a specific port
Input: Pointer to desired GPIO struct
Return: None*/
void GPIO_voidConfigurePin(GPIO_t* DesiredGPIO)
{
	/*This variable will hold the value that we want to write inside the register*/
	u32 Local_u32DesiredConfiguration;

	/*Check desired speed and write it inside the variable, which will be ORed in the next step with the mode*/
	if ((DesiredGPIO->speed) == GPIO_SPEED_INPUT)
	{
		Local_u32DesiredConfiguration = GPIO_SPEED_INPUT_MASK;
	}
	else if ((DesiredGPIO->speed) == GPIO_SPEED_OUTPUT_10)
	{
		Local_u32DesiredConfiguration = GPIO_SPEED_OUTPUT_10_MASK;
	}
	else if ((DesiredGPIO->speed)==GPIO_SPEED_OUTPUT_2)
	{
		Local_u32DesiredConfiguration = GPIO_SPEED_OUTPUT_2_MASK;
	}
	else if ((DesiredGPIO->speed)==GPIO_SPEED_OUTPUT_50)
	{
		Local_u32DesiredConfiguration = GPIO_SPEED_OUTPUT_50_MASK;
	}
	
	/*Check desired mode and OR it with the variable*/
	/*Input Modes*/
	if ((DesiredGPIO->mode)==GPIO_MODE_INPUT_ANALOG)
	{
		Local_u32DesiredConfiguration &= GPIO_MODE_INPUT_ANALOG_MASK;
	}
	else if ((DesiredGPIO->mode)==GPIO_MODE_INPUT_FLOATING)
	{
		Local_u32DesiredConfiguration |= GPIO_MODE_INPUT_FLOATING_MASK;
	}
	else if ((DesiredGPIO->mode)==GPIO_MODE_INPUT_PULL)
	{
		Local_u32DesiredConfiguration |= GPIO_MODE_INPUT_PULL_MASK;
	}
	/*Output Modes*/
	else if ((DesiredGPIO->mode)==GPIO_MODE_OUTPUT_PUSHPULL)
	{
		Local_u32DesiredConfiguration &= GPIO_MODE_OUTPUT_PUSHPULL_MASK;
	}
	else if ((DesiredGPIO->mode)==GPIO_MODE_OUTPUT_OPENDRAIN)
	{
		Local_u32DesiredConfiguration |= GPIO_MODE_OUTPUT_OPENDRAIN_MASK;
	}
	else if ((DesiredGPIO->mode)==GPIO_MODE_OUTPUT_AF_PUSHPULL)
	{
		Local_u32DesiredConfiguration |= GPIO_MODE_OUTPUT_AF_PUSHPULL_MASK;
	}
	else if ((DesiredGPIO->mode)==GPIO_MODE_OUTPUT_AF_OPENDRAIN)
	{
		Local_u32DesiredConfiguration |= GPIO_MODE_OUTPUT_AF_OPENDRAIN_MASK;
	}
	

	/*Go to specific port according to user choice*/
	if ((DesiredGPIO->port)==GPIO_PORT_A)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTA_CRL = (GPIO_PORTA_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTA_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTA_CRH = (GPIO_PORTA_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTA_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_B)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTB_CRL = (GPIO_PORTB_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTB_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTB_CRH = (GPIO_PORTB_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTB_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_C)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTC_CRL = (GPIO_PORTC_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTC_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTC_CRH = (GPIO_PORTC_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTC_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_D)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTD_CRL = (GPIO_PORTD_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTD_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTD_CRH = (GPIO_PORTD_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTD_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_E)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTE_CRL = (GPIO_PORTE_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTE_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTE_CRH = (GPIO_PORTE_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTE_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_F)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTF_CRL = (GPIO_PORTF_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTF_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTF_CRH = (GPIO_PORTF_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTF_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_G)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTG_CRL = (GPIO_PORTG_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTG_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTG_CRH = (GPIO_PORTG_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTG_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_H)
	{
		/*If pin number is less than pin #8, then we will write in CRL shifted by the pin mask predefined above*/
		if ((DesiredGPIO->pin)<GPIO_PIN8)
		{
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTH_CRL = (GPIO_PORTH_CRL & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTH_CRL |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
		/*If pin number is greater than pin #8, then we will write in CRH shifted by the pin mask predefined above
		after removing 8 from pin number so that it starts at 0 again*/
		else
		{
			/*Remove the number of pins per register so that it will be considered as pin 0 in high register*/
			(DesiredGPIO->pin) = (DesiredGPIO->pin)-GPIO_PINS_PER_REGISTER;
		
			if ((DesiredGPIO->pin)==GPIO_PIN0)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN0_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN0_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN1)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN1_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN1_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN2)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN2_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN2_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN3)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN3_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN3_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN4)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN4_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN4_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN5)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN5_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN5_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN6)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN6_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN6_SHIFT_MASK);
			}
			else if ((DesiredGPIO->pin)==GPIO_PIN7)
			{
				GPIO_PORTH_CRH = (GPIO_PORTH_CRH & GPIO_PIN7_CLEAR_MASK);
				GPIO_PORTH_CRH |= (Local_u32DesiredConfiguration<<GPIO_PIN7_SHIFT_MASK);
			}
		}
	}
}

/*Description: This API will be used to get value of a specific pin through the IDR register
Input: Desired port (u8), desired pin (u8)
Return: Pin Status (The value inside IDR)
*/
u16 GPIO_u16GetPinStatus (GPIO_t* DesiredGPIO)
{
	/*First, check port in the struct*/
	if ((DesiredGPIO->port)==GPIO_PORT_A)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTA_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_B)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTB_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_C)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTC_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_D)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTD_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_E)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTE_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_F)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTF_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_G)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTG_IDR & GPIO_PIN15_RW_MASK);
		}
	}
	else if ((DesiredGPIO->port)==GPIO_PORT_H)
	{
		/*According to pin number inside the struct, return result of the value inside the register*/
		if ((DesiredGPIO->pin) == GPIO_PIN0)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN0_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN1)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN1_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN2)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN2_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN3)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN3_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN4)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN4_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN5)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN5_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN6)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN6_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN7)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN7_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN8)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN8_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN9)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN9_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN10)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN10_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN11)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN11_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN12)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN12_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN13)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN13_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN14)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN14_RW_MASK);
		}
		/*According to pin number inside the struct, return result of the value inside the register*/
		else if ((DesiredGPIO->pin) == GPIO_PIN15)
		{
			return (GPIO_PORTH_IDR & GPIO_PIN15_RW_MASK);
		}
	}
}

/*Description: This API will be used to write desired value on a pin through the ODR register
Parameters: Desired pin (pointer to struct), Desired value to be written (u8)
Return: None*/
void GPIO_voidWriteOutput (GPIO_t* DesiredGPIO, u8 Copy_u8DesiredValue)
{
	
}

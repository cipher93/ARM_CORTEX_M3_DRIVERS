/*
 * WIFI_program.c
 *
 *  Created on: Jun 6, 2020
 *      Author: Mahmoud
 *      Version: 1.0
 */

#include "WIFI_interface.h"
#include "HUART_interface.h"
#include <string.h>
#include "Delay_interface.h"




/*This static variable will hold the address for the initialized object of UART peripheral used for WIFI
 * If it is null (meaning uninitialized), then no function will be carried out
 * */
/*This static variable will hold the address for the initialized object of UART peripheral used for displaying output
 * If it is null (meaning uninitialized), then no function will be carried out
 * */
static UART_GPIO_t Static_UART_PERIPHERAL = {.BaseAddress = NULL};
static UART_GPIO_t Static_OUTPUT_PERIPHERAL = {.BaseAddress = NULL};


/*This static variable will hold the response*/
static volatile u8 static_u8Response=0;
/*This variable will contain the previous character before the one we are currently receiving*/
static volatile u8 static_u8PreviousChar=0;
/*This is the flag that will keep us sending and receiving until the end of the data*/
static volatile u8 static_u8ReceiveFlag=1;
/*This static variable will be used as a flag so that we know whether the data incoming should be saved inside a variable or not*/
static volatile u8 static_u8DataToArray=0;
/*This static variable will be used to store incoming data*/
static volatile u8 static_u8DataReceivedArray[2048]={0};
/*This static variable will be used as iterator for array that will be used to save data*/
static volatile u16 static_u16DataArrayIterator=0;

/*This static variable will be used as a flag to prompt start receiving data inside the array after the desired char is received ':'*/
static volatile u8 static_u8StartSavingData=0;

/*This callback will send the received data to the screen*/
void callBackRX (void)
{
	/*If display is specified (address is not null), we are free to send char to them*/
	if (Static_OUTPUT_PERIPHERAL.BaseAddress!=NULL)
	{
		/*Send character that has been received*/
		HUART_u8SendAsync(Static_OUTPUT_PERIPHERAL, &static_u8Response, sizeof(static_u8Response));
	}

	/*If data to array flag is on, send data to flag too*/
	if (static_u8DataToArray==1)
	{
		if (static_u8StartSavingData)
		{
			if (static_u16DataArrayIterator<sizeof(static_u8DataReceivedArray))
			{
				if (static_u8Response=='<')
				{
					static_u8StartSavingData=0;
				}
				if (static_u8Response!=' ' && static_u8Response!='\n'&& static_u8Response!='<')
				{
					static_u8DataReceivedArray[static_u16DataArrayIterator]=static_u8Response;
					static_u16DataArrayIterator++;
				}
			}

			/*We check for end of receiving through the word "CLOSED", we will check for the last two chars of the word*/
			if (static_u8PreviousChar=='C' && static_u8Response=='L')
			{
				static_u8ReceiveFlag=0;
			}
			else
			{
				/*Save the last received character in the previous char to make comparison later for receiving flag*/
				static_u8PreviousChar=static_u8Response;
			}
		}
		if ((static_u8Response==':') | (static_u8Response=='>'))
		{
			static_u8StartSavingData=1;
		}

	}
	/*Do the check according to whether send flag is set or reset
	 * It case it is set, we check for CLOSED, otherwise we check for OK*/
	else
	{
		if ((static_u8PreviousChar=='O' && static_u8Response=='K'))
		{
			static_u8ReceiveFlag=0;
		}
		else
		{
			/*Save the last received character in the previous char to make comparison later for receiving flag*/
			static_u8PreviousChar=static_u8Response;
		}
	}
}


/*Description: This static function will be used to handle sending request and receiving its response
 * parameters: Data to send (u8*)
 * Return: void*/
static void WIFI_voidHandleRequest (u8* Copy_u8Request)
{
	/*Send data to WIFI peripheral*/
	HUART_u8SendAsync(Static_UART_PERIPHERAL, Copy_u8Request, strlen(Copy_u8Request));

	/*Enter the loop for sending and receiving data from UART*/
	while(static_u8ReceiveFlag)
	{
		/*Receive Response*/
		HUART_u8ReceiveAsync(Static_UART_PERIPHERAL, &static_u8Response, sizeof(static_u8Response));
	}
}


/*Description: This API will be used to initialize WIFI module on specified UART
 * parameters: UART peripheral used for WIFI (UART_GPIO_t)
 * Return: Error Status*/
u8 WIFI_u8Init (UART_GPIO_t UART_Peripheral)
{
	/*This local variable will hold error status for the current function*/
	u8 Local_u8Status = STATUS_NOK;
	/*This local variable will be sent to wifi module so that it will be reset*/
	u8 Local_u8Send[]="AT+RST\r\n";
	/*Initialization will be done by calling initialize function of HUART*/
	Local_u8Status= HUART_u8Init(UART_Peripheral, 115200, UART_STOP_BIT1, UART_PARITY_DISABLED);
	/*If initialization was successful, save uart address in the static variable*/
	if (Local_u8Status == STATUS_OK)
	{
		Static_UART_PERIPHERAL = UART_Peripheral;
		/*Send reset to the Module*/
		HUART_u8SendSync(Static_UART_PERIPHERAL, Local_u8Send, strlen(Local_u8Send), 1);
	}
	/*This delay is needed for initialization to be done*/
	delay_ms(10000);
	/*Return Status*/
	return Local_u8Status;
}

/*Description: This API will be used to set UART peripheral that will be used to display output
 * parameters: UART peripheral used for output (UART_GPIO_t)
 * Return: void*/
void WIFI_u8SetOutput (UART_GPIO_t Copy_UART_Peripheral)
{
	Static_OUTPUT_PERIPHERAL=Copy_UART_Peripheral;
}

/*Description: This API will be used to send AT command to the module
 * parameters: Desired Command
 * Return: Error Status*/
u8 WIFI_u8SendCommand (u8* Copy_u8DesiredCommand)
{
	/*This local variable will hold status of function*/
	u8 Local_u8Status = STATUS_NOK;

	/*Reset receive flag if it has not been initialized*/
	static_u8ReceiveFlag=1;

	/*If wifi peripheral has been initialized, proceed with the code*/
	if (Static_UART_PERIPHERAL.BaseAddress!=NULL)
	{
		/*Set callback function*/
		HUART_u8SetRXCallBack(callBackRX, Static_UART_PERIPHERAL.BaseAddress);
		/*Send data using static send request*/
		WIFI_voidHandleRequest(Copy_u8DesiredCommand);
		/*Return request as OK because the previous function contained while loop*/
		Local_u8Status=STATUS_OK;
	}
	/*Return status*/
	return Local_u8Status;
}

/*Description: This API will be used to connect to a specific WIFI access point
 * parameters: Access point name (u8*), password(u8*)
 * Return: Error Status*/
u8 WIFI_u8ConnectToAccessPoint (u8* Copy_u8SSID, u8* Copy_u8Password)
{
	/*This local variable will hold the status of the function*/
	u8 Local_u8Status = STATUS_NOK;
	/*These local arrays will hold the data that will be sent as command*/
	u8 Local_u8SendPart1[]="AT+CWJAP_CUR=\"";
	u8 Local_u8SendPart2[]="\",\"";
	u8 Local_u8SendPart3[]="\"\r\n";
	/*Reset receive flag if it has not been initialized*/
	static_u8ReceiveFlag=1;

	/*If wifi peripheral has been initialized, proceed with the code*/
	if (Static_UART_PERIPHERAL.BaseAddress!=NULL)
	{
		/*Set Callback function*/
		HUART_u8SetRXCallBack(callBackRX, Static_UART_PERIPHERAL.BaseAddress);

		HUART_u8SendSync(Static_UART_PERIPHERAL, Local_u8SendPart1, strlen(Local_u8SendPart1),1);
		/*Wait until we reach the point where we should send the name*/
		HUART_u8SendSync(Static_UART_PERIPHERAL, Copy_u8SSID, strlen(Copy_u8SSID),1);
		/*Send part between name and password*/
		HUART_u8SendSync(Static_UART_PERIPHERAL, Local_u8SendPart2, strlen(Local_u8SendPart2),1);
		/*Send Password*/
		HUART_u8SendSync(Static_UART_PERIPHERAL, Copy_u8Password, strlen(Copy_u8Password),1);
		/*Send last part of command*/
		HUART_u8SendSync(Static_UART_PERIPHERAL, Local_u8SendPart3, strlen(Local_u8SendPart3),1);

		/*Enter the loop for sending and receiving data from UART*/
		while(static_u8ReceiveFlag)
		{
			/*Receive Response*/
			HUART_u8ReceiveAsync(Static_UART_PERIPHERAL, &static_u8Response, sizeof(static_u8Response));
		}
		/*Since we reached here, set status as ok*/
		Local_u8Status=STATUS_OK;
	}
	/*Return status*/
	return Local_u8Status;
}


/*Description: This API will be used to receive data
 * parameters: Desired Command
 * Return: Error Status*/
u8 WIFI_u8ReceiveData (u8* Copy_u8DesiredCommand)
{
	/*This local variable will hold status of function*/
	u8 Local_u8Status = STATUS_NOK;
	/*This local array will hold the data that will be sent*/
	u8 Local_u8SendConnectionType[]="AT+CIPMUX=0\r\n";
	u8 Local_u8SendStartConnection[]="AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n";
	u8 Local_u8SendSize[]="AT+CIPSEND=90\r\n";
	//u8 Local_u8SendRequest[]="GET https://api.thingspeak.com/apps/thinghttp/send_request?api_key=Y4JOXUDQZBLGOMHJ\r\nHost:api.thingspeak.com\r\n\r\n\r\n\r\n\r\n";


	/*Reset receive flag if it has not been initialized*/
	//static_u8ReceiveFlag=1;

	/*If wifi peripheral has been initialized, proceed with the code*/
	if (Static_UART_PERIPHERAL.BaseAddress!=NULL)
	{

		HUART_u8SetRXCallBack(callBackRX, Static_UART_PERIPHERAL.BaseAddress);
		/*Send first part to WIFI peripheral, which specifies the number of connections we will be using (which is 1)*/
		WIFI_u8SendCommand(Local_u8SendConnectionType);
		delay_ms(1000);

		/*Reset flag again and send following data*/
		//static_u8ReceiveFlag=1;
		/*Send second part to WIFI peripheral, which is to connect to specific server*/
		WIFI_u8SendCommand(Local_u8SendStartConnection);
		delay_ms(1000);

		/*Reset flag again and send following data*/
		//static_u8ReceiveFlag=1;
		/*Send third part to WIFI peripheral, which is to specify size of command*/
		WIFI_u8SendCommand(Local_u8SendSize);

		delay_ms(1000);

		/*Reset flag again and send following data*/
		//static_u8ReceiveFlag=1;
		/*Set data to array flag*/
		static_u8DataToArray=1;
		/*Send final part to WIFI peripheral, which is the request*/
		WIFI_u8SendCommand(Copy_u8DesiredCommand);
		/*Set data to array flag*/
		static_u8DataToArray=0;

		/*The last two chars in the buffer now contain C and L, so we need to make them equal to null*/
		static_u8DataReceivedArray[static_u16DataArrayIterator-1]=0;
		static_u8DataReceivedArray[static_u16DataArrayIterator-2]=0;

		/*Since we reached here, set status as ok*/
		Local_u8Status=STATUS_OK;
	}

	/*Return status*/
	return Local_u8Status;
}

/*
 * app.c
 *
 * Created: 8/25/2021 3:22:28 PM
 *  Author: Marco
 */ 

#include "app.h"

uint8_t gau8_DataSending[10];

E_STATUS APP_Init()
{
	GIE_voidEnable();
	DIO_SetPinDirection(PortD, PIN1, OUTPUT);
	DIO_SetPortDirection(PortC, OUTPUT_PORT);
	configs.modes.uartEnable = ONE;
	BCM_Init(&configs);
	for (uint8_t i = 1; i <= 10; i++)
	{
		gau8_DataSending[i-1] = i;
	}
	BCM_SetData(gau8_DataSending);
	BCM_SetReciever(2);
	BCM_SetSize(10);
	return E_OK;
}

E_STATUS APP_Update()
{

	BCM_TxMainFunction();
	return E_OK;
}
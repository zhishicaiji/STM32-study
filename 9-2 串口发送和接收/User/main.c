#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"

uint8_t Rx_Data;
int main(void){
	OLED_Init();
	Serial_Init();
	OLED_ShowString(1, 1, "RxData:");
	
	while(1){
		if (Serial_GetRxFlag() == 1){
			Rx_Data = Serial_GetRxData();
			Serial_SendByte(Rx_Data);
			OLED_ShowHexNum(1, 8, Rx_Data, 2);
		}
		
	}
}

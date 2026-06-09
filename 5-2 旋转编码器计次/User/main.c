#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Encoder.h"

int16_t num = 0;

int main(void){
	OLED_Init();
	Encoder_Init();
	OLED_ShowString(1, 1, "num:");
	
	while(1){
		num += Encoder_Get();
		OLED_ShowSignedNum(1, 5, num, 5);
	}
}

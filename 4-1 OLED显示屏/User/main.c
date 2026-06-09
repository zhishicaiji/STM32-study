#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"


int main(void){
	OLED_Init();

	OLED_ShowChar(1, 1, 'A');
	OLED_ShowString(2, 1, "Hello, World!");
	OLED_ShowNum(3, 1, 12345678, 7);
	OLED_ShowSignedNum(3, 8, -66, 2);
	OLED_ShowHexNum(4, 1, 0xAA55, 4);
	OLED_ShowBinNum(4, 1, 0xAA55, 16);
	while(1){
		
		
	}
}

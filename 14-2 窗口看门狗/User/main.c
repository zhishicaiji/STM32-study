#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Key.h"

int main(void){
	OLED_Init();
	Key_Init();
	OLED_ShowString(1, 1, "WWDG TEST");
	
	if (RCC_GetFlagStatus(RCC_FLAG_WWDGRST) == SET){
		OLED_ShowString(2, 1, "WWDGRST");			//OLED闪烁IWDGRST字符串
		Delay_ms(500);
		OLED_ShowString(2, 1, "       ");
		Delay_ms(100);
		
		RCC_ClearFlag();
	}
	else {
		OLED_ShowString(3, 1, "RST");				//OLED闪烁RST字符串
		Delay_ms(500);
		OLED_ShowString(3, 1, "   ");
		Delay_ms(100);
	}
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);
	WWDG_SetPrescaler(WWDG_Prescaler_8);
	WWDG_SetWindowValue(0x40 | 21);
	WWDG_Enable(0x40 | 54);
	
	while(1){
		Key_GetNum();
//		
//		OLED_ShowString(4, 1, "FEED");				//OLED闪烁FEED字符串
//		Delay_ms(20);								//喂狗间隔为200+600=800ms
//		OLED_ShowString(4, 1, "    ");
		Delay_ms(31);
		
		WWDG_SetCounter(0x40 | 54);
	}
}

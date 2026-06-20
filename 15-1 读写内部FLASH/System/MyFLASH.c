#include "stm32f10x.h"                  // Device header

uint32_t MyFLASH_ReadWord(uint32_t Address){
	return *(__IO uint32_t *)Address; 
}

uint16_t MyFLASH_ReadHalfWord(uint32_t Address){
	return *(__IO uint16_t *)Address; 
}

uint8_t MyFLASH_ReadByte(uint32_t Address){
	return *(__IO uint8_t *)Address; 
}

void MyFLASH_EraseAllPages(){
	FLASH_Unlock();
	FLASH_EraseAllPages();
	FLASH_Lock();
}

void MyFLASH_ErasePage(uint32_t PageAddress){
	FLASH_Unlock();
	FLASH_ErasePage(PageAddress);
	FLASH_Lock();
}

void MyFLASH_ProgramWord(uint32_t Address, uint32_t Data)
{
	FLASH_Unlock();							//解锁
	FLASH_ProgramWord(Address, Data);		//编程字
	FLASH_Lock();							//加锁
}

void MyFLASH_ProgramHalfWord(uint32_t Address, uint16_t Data)
{
	FLASH_Unlock();							//解锁
	FLASH_ProgramHalfWord(Address, Data);	//编程半字
	FLASH_Lock();							//加锁
}


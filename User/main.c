#include "stm32f10x.h"                  // Device header
#include "TIM2.h"
#include "SysTick.h"

int i;

int main(void)
{
	SysTick_Init();
	TIM2_Init();
	while(1)
	{
		for(i=0;i<150;i+=1)
		{
			Servo_SetAngle(4, i);			
			Delay_ms(10);		
		}
		for(i=150;i>1;i-=1)
		{
			Servo_SetAngle(4, i);			
			Delay_ms(10);		
		}
//		Servo_SetAngle(3, 0);
//		Delay_ms(1000);
	}
}

#include "stm32f10x.h"                  // Device header

static u32 TimingDelay;

void SysTick_Init(void)
{
	if (SysTick_Config(SystemCoreClock / 1000000))
	{
		while (1);
	}
}

void TimingDelay_Decrement(void)
{
	if (TimingDelay != 0x00)
	{
		TimingDelay --;
	}
}

void Delay_us(uint32_t ntime)	//1usһ����λ
{
	TimingDelay = ntime;
	// ʹ�ܵδ�ʱ��  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
	while (TimingDelay != 0);
	//�ر�SysTick��ʱ��
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}

void Delay_ms(uint32_t ntime)	//1usһ����λ
{
	TimingDelay = ntime * 1000;
	// ʹ�ܵδ�ʱ��  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;
	while (TimingDelay != 0);
	//�ر�SysTick��ʱ��
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}


void SysTick_Delay_Us(uint32_t Us)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock / 1000000);
	for (i = 0; i < Us; i ++)
	{
		while (!((SysTick->CTRL) & (1 << 16)));
	}
}

void SysTick_Delay_Ms(uint32_t Ms)
{
	uint32_t i;
	SysTick_Config(SystemCoreClock / 1000);
	for (i = 0; i < Ms; i ++)
	{
		while (!((SysTick->CTRL) & (1 << 16)));
	}
}

void SysTick_Delay_S(uint32_t S)
{
	uint32_t i;
	for (i = 0; i < S; i ++)
	{
		SysTick_Delay_Ms(1000);
	}
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
	TimingDelay_Decrement( );
}

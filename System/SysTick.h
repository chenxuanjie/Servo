#ifndef __SysTick_H__
#define __SysTick_H__

void SysTick_Init(void);
void TimingDelay_Decrement(void);
void Delay_us(uint32_t ntime);	
void Delay_ms(uint32_t ntime);	
void SysTick_Delay_Us(uint32_t us);
void SysTick_Delay_Ms(uint32_t Ms);
void SysTick_Delay_S(uint32_t S);


#endif

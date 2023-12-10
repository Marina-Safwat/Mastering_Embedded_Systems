// toggle led 
// cortex M4
// by Marina Safwat
// 3/12/2023

#include <stdint.h>

#define SYSCTL_RCGC2_R_BASE 0x400FE000
#define GPIO_PORTF_BASE 0x40025000

#define SYSCTL_RCGC2_R (*(volatile uint32_t*)(SYSCTL_RCGC2_R_BASE + 0x108))
#define GPIO_PORTF_DIR_R (*(volatile uint32_t*)(GPIO_PORTF_BASE + 0x400))
#define GPIO_PORTF_DATA_R (*(volatile uint32_t*)(GPIO_PORTF_BASE + 0x3FC))
#define GPIO_PORTF_DEN_R (*(volatile uint32_t*)(GPIO_PORTF_BASE + 0x51C))

#define SETBIT(reg,n) reg|=(1<<n)
#define CLRBIT(reg,n) reg&=~(1<<n)

int main(void)
{
	volatile uint32_t delay_count;
	SYSCTL_RCGC2_R = 0x00000020;
	for(delay_count = 0;delay_count<2000;delay_count++);
	SETBIT(GPIO_PORTF_DIR_R,3);
	SETBIT(GPIO_PORTF_DEN_R,3);
	while(1)
	{
		SETBIT(GPIO_PORTF_DATA_R,3);
		for(delay_count = 0;delay_count<2000;delay_count++);
		CLRBIT(GPIO_PORTF_DATA_R,3);
		for(delay_count = 0;delay_count<2000;delay_count++);
	}
	return 0;
}
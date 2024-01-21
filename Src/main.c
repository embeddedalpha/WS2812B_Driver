#include "main.h"
#include "GPIO.h"





#define high 135
#define low 68
volatile uint16_t array[100][24];

void DMA_Trigger(void);
void Timer_Init();
void Timer_Trigger(void);
void DMA_Init(void);



void led_color(int led_no,uint32_t red, uint32_t green, uint32_t blue)
{
	uint32_t green1 = green;
	uint32_t red1 = red;
	uint32_t blue1 = blue;

	uint32_t color = (green1 << 16) | (red1 << 8) | (blue1 << 0);
	for(int i = 23 ; i >= 0; i--)
	{
		if((color % 2)==0){array[led_no][i] = low;}
		if((color % 2)==1){array[led_no][i] = high;}
		color = color >> 1;
	}

}

void led_nop(int led_no)
{
	for(int i = 0 ; i <= 23; i++)
	{
			array[led_no][i] = 0;
	}
}


int main(void)
{




	MCU_Clock_Setup();
	Delay_Config();

	GPIO_Pin_Init(GPIOA, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.TIM_1);


	Timer_Init();
	DMA_Init();



	for(int i =0; i < 5; i++)
	{
		led_color(i,0xFF, 0x67, 0x1f);
	}

	led_nop(5);
	led_nop(6);

	DMA_Trigger();
	Timer_Trigger();







    /* Loop forever */
	for(;;)
	{




	}
}

void DMA_Trigger(void)
{
	DMA2_Stream1 ->NDTR = 24*(5+2);
	DMA2_Stream1 -> M0AR = (uint32_t)&array;
	DMA2_Stream1 -> PAR = (uint32_t)&TIM1->CCR1;
	DMA2_Stream1 -> CR |= DMA_SxCR_EN;
}

void DMA_Init(void)
{
	//DMA INIT
	RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
	DMA2_Stream1 -> CR |= DMA_SxCR_CHSEL_2 | DMA_SxCR_CHSEL_1; //CHANNEL 6
	DMA2_Stream1 -> CR |= DMA_SxCR_MSIZE_0; //16 BITS
	DMA2_Stream1 -> CR |= DMA_SxCR_PSIZE_0; //16 BITS
	DMA2_Stream1 -> CR |= DMA_SxCR_MINC; //MEMORY INCREMENT MODE
	DMA2_Stream1 -> CR |= DMA_SxCR_CIRC; //CIRCULAR MODE
	DMA2_Stream1 -> CR |= DMA_SxCR_DIR_0; //MEMORY TO PERIPHERAL
	DMA2_Stream1 -> CR |= DMA_SxCR_TCIE | DMA_SxCR_HTIE | DMA_SxCR_TEIE | DMA_SxCR_DMEIE;
}

void Timer_Trigger(void)
{
	TIM1 -> CR1 |= TIM_CR1_CEN;
}

void Timer_Init()
{
	RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1 -> PSC = 0;
	TIM1 -> ARR = 210;
	TIM1 -> CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;
	TIM1 -> CCMR1 |= TIM_CCMR1_OC1PE;
	TIM1 -> BDTR |= TIM_BDTR_BKP | TIM_BDTR_MOE;
	TIM1 -> CCER |= TIM_CCER_CC1E;
	TIM1 -> EGR |= TIM_EGR_UG;
	TIM1 -> DMAR = 1;
	TIM1 -> DIER |= TIM_DIER_CC1DE;
}

#include "main.h"
#include "GPIO.h"
#include "DMA.h"


DMA_Config DMA_WS2812B;




#define high 135
#define low 68
volatile uint16_t array[100][24];

void DMA_Trigger1(void);
void Timer_Init();
void Timer_Trigger(void);
void DMA_Init1(void);



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


	DMA_WS2812B.controller = DMA2;
	DMA_WS2812B.stream = DMA2_Stream1;
	DMA_WS2812B.channel = 6;
	DMA_WS2812B.circular_mode = DMA_Circular_Mode.Enable;
//	DMA_WS2812B.flow_control = DMA_Flow_Control.Peripheral_Control;
	DMA_WS2812B.interrupts = DMA_Interrupts.Half_Transfer_Complete | DMA_Interrupts.Transfer_Complete |
			                 DMA_Interrupts.Direct_Mode_Error | DMA_Interrupts.Transfer_Error;
	DMA_WS2812B.memory_data_size = DMA_Memory_Data_Size.half_word;
	DMA_WS2812B.peripheral_data_size = DMA_Peripheral_Data_Size.half_word;
	DMA_WS2812B.priority_level = DMA_Priority_Level.Very_high;
	DMA_WS2812B.transfer_direction = DMA_Transfer_Direction.Memory_to_peripheral;


	GPIO_Pin_Init(GPIOA, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.TIM_1);


	Timer_Init();
	DMA_Clock_Enable(&DMA_WS2812B);
	DMA_Init(&DMA_WS2812B);


	for(int i =0; i < 5; i++)
	{
		led_color(i,00, 255, 0x80);
	}

	led_nop(5);
	led_nop(6);

	DMA_WS2812B.memory_address = (uint32_t)&array;
	DMA_WS2812B.peripheral_address = (uint32_t)&(TIM1->CCR1);
	DMA_WS2812B.buffer_length = (24*(5+2));
	DMA_Set_Target(&DMA_WS2812B);
	DMA_Set_Trigger(&DMA_WS2812B);

	Timer_Trigger();











    /* Loop forever */
	for(;;)
	{




	}
}

void DMA_Trigger1(void)
{
	DMA2_Stream1 ->NDTR = 24*(5+2);
	DMA2_Stream1 -> M0AR = (uint32_t)&array;
	DMA2_Stream1 -> PAR = (uint32_t)&TIM1->CCR1;
	DMA2_Stream1 -> CR |= DMA_SxCR_EN;
}

void DMA_Init1(void)
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
//
void Timer_Trigger(void)
{
	TIM1 -> CR1 |= TIM_CR1_CEN;
}
//
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

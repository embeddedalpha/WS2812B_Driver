/*
 * DMA.c
 *
 *  Created on: Nov 16, 2023
 *      Author: kunal
 */


#include "DMA.h"


void DMA_Clock_Enable(DMA_Config *config)
{
	if(config->controller == DMA1) RCC -> AHB1ENR |= RCC_AHB1ENR_DMA1EN;
	if(config->controller == DMA2) RCC -> AHB1ENR |= RCC_AHB1ENR_DMA2EN;
}
//

void DMA_Clock_Disable(DMA_Config *config)
{

	if(config->controller == DMA1) RCC -> AHB1ENR &= ~RCC_AHB1ENR_DMA1EN;
	if(config->controller == DMA2) RCC -> AHB1ENR &= ~RCC_AHB1ENR_DMA2EN;
}
//

void DMA_Reset(DMA_Config *config)
{
	if(config->controller == DMA1) RCC -> AHB1RSTR |= RCC_AHB1RSTR_DMA1RST;
	if(config->controller == DMA2) RCC -> AHB1RSTR |= RCC_AHB1RSTR_DMA2RST;
}
//

void DMA_Init(DMA_Config *config)
{
	DMA_Clock_Enable(config);
	config -> stream -> CR |= config -> channel << DMA_SxCR_CHSEL_Pos;
	config -> stream -> CR |= config -> circular_mode;
	config -> stream -> CR |= config -> flow_control;
	config -> stream -> CR |= config -> priority_level;
	config -> stream -> CR |= config -> memory_data_size;
	config -> stream -> CR |= config -> peripheral_data_size;
	config -> stream -> CR |= config -> transfer_direction;
	config -> stream -> CR |= config -> interrupts;
	config -> stream -> CR |= DMA_SxCR_MINC;
}

void DMA_Set_Target(DMA_Config *config)
{
	config -> stream -> NDTR = config -> buffer_length;
	config -> stream -> M0AR = (uint32_t)config->memory_address;
	config -> stream -> PAR = (uint32_t)config->peripheral_address;

}

//void DMA_Trigger(DMA_Config *config)
//{
//	config -> stream -> CR = DMA_SxCR_EN;
//	if(config->flow_control == DMA_Flow_Control.Peripheral_Control)
//	{
//		if((config->stream == SPI_DMA_Stream.SPI1_RX) ||
//		   (config->stream == SPI_DMA_Stream.SPI1_TX))
//		{
//			SPI1 -> CR1 |= SPI_CR1_SPE;
//		}
//		else if((config->stream == SPI_DMA_Stream.SPI2_RX) ||
//		   (config->stream == SPI_DMA_Stream.SPI2_TX))
//		{
//			SPI2 -> CR1 |= SPI_CR1_SPE;
//		}
//		else if((config->stream == SPI_DMA_Stream.SPI3_RX) ||
//		   (config->stream == SPI_DMA_Stream.SPI3_TX))
//		{
//			SPI3 -> CR1 |= SPI_CR1_SPE;
//		}
///*********************************************************************/
//		else if((config->stream == USART_DMA_Stream.USART1_RX) ||
//		   (config->stream == USART_DMA_Stream.USART1_TX))
//		{
//			USART1 -> CR1 |= USART_CR1_UE;
//		}
//		else if((config->stream == USART_DMA_Stream.USART2_RX) ||
//		   (config->stream == USART_DMA_Stream.USART2_TX))
//		{
//			USART2 -> CR1 |= USART_CR1_UE;
//		}
//		else if((config->stream == USART_DMA_Stream.USART3_RX) ||
//		   (config->stream == USART_DMA_Stream.USART3_TX))
//		{
//			USART3 -> CR1 |= USART_CR1_UE;
//		}
//		else if((config->stream == USART_DMA_Stream.UART4_RX) ||
//		   (config->stream == USART_DMA_Stream.UART4_TX))
//		{
//			UART4 -> CR1 |= USART_CR1_UE;
//		}
//		else if((config->stream == USART_DMA_Stream.UART5_RX) ||
//		   (config->stream == USART_DMA_Stream.UART5_TX))
//		{
//			UART5 -> CR1 |= USART_CR1_UE;
//		}
//		else if((config->stream == USART_DMA_Stream.USART6_RX) ||
//		   (config->stream == USART_DMA_Stream.USART6_TX))
//		{
//			USART6 -> CR1 |= USART_CR1_UE;
//		}
///*********************************************************************/
//		else if((config->stream == I2C_DMA_Stream.I2C1_RX) ||
//		   (config->stream == I2C_DMA_Stream.I2C1_TX))
//		{
//			I2C1 -> CR1 |= I2C_CR1_PE;
//		}
//		else if((config->stream == I2C_DMA_Stream.I2C2_RX) ||
//		   (config->stream == I2C_DMA_Stream.I2C2_TX))
//		{
//			I2C2 -> CR1 |= I2C_CR1_PE;
//		}
//		else if((config->stream == I2C_DMA_Stream.I2C3_RX) ||
//		   (config->stream == I2C_DMA_Stream.I2C3_TX))
//		{
//			I2C3 -> CR1 |= I2C_CR1_PE;
//		}
///*********************************************************************/
//	}
//
//}

void DMA_Set_Trigger(DMA_Config *config)
{
	config -> stream -> CR |= DMA_SxCR_EN;
}




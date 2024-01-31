/*
 * DMA_Defs_Stream.h
 *
 *  Created on: Nov 17, 2023
 *      Author: kunal
 */

#ifndef DMA_DEFS_STREAM_H_
#define DMA_DEFS_STREAM_H_

#include "main.h"

static const struct SPI_DMA_Stream
{
	DMA_Stream_TypeDef *SPI1_RX;
	uint32_t SPI1_DMA_Channel;
	DMA_Stream_TypeDef *SPI1_TX;

	DMA_Stream_TypeDef *SPI2_RX;
	uint32_t SPI2_DMA_Channel;
	DMA_Stream_TypeDef *SPI2_TX;

	DMA_Stream_TypeDef *SPI3_RX;
	uint32_t SPI3_DMA_Channel;
	DMA_Stream_TypeDef *SPI3_TX;

}SPI_DMA_Stream = {DMA2_Stream0,3,DMA2_Stream3,
				   DMA1_Stream3,0,DMA1_Stream4,
				   DMA1_Stream2,0,DMA1_Stream7};

static const struct I2C_DMA_Stream
{
	DMA_Stream_TypeDef *I2C1_RX;
	uint32_t I2C1_DMA_Channel;
	DMA_Stream_TypeDef *I2C1_TX;

	DMA_Stream_TypeDef *I2C2_RX;
	uint32_t I2C2_DMA_Channel;
	DMA_Stream_TypeDef *I2C2_TX;

	DMA_Stream_TypeDef *I2C3_RX;
	uint32_t I2C3_DMA_Channel;
	DMA_Stream_TypeDef *I2C3_TX;

}I2C_DMA_Stream = {DMA1_Stream5,1,DMA1_Stream6,
				   DMA1_Stream2,2,DMA1_Stream7,
				   DMA1_Stream2,3,DMA1_Stream4};

static const struct USART_DMA_Stream
{
	DMA_Stream_TypeDef *USART1_RX;
	uint32_t USART1_DMA_Channel;
	DMA_Stream_TypeDef *USART1_TX;

	DMA_Stream_TypeDef *USART2_RX;
	uint32_t USART2_DMA_Channel;
	DMA_Stream_TypeDef *USART2_TX;

	DMA_Stream_TypeDef *USART3_RX;
	uint32_t USART3_DMA_Channel;
	DMA_Stream_TypeDef *USART3_TX;

	DMA_Stream_TypeDef *UART4_RX;
	uint32_t UART4_DMA_Channel;
	DMA_Stream_TypeDef *UART4_TX;

	DMA_Stream_TypeDef *UART5_RX;
	uint32_t UART5_DMA_Channel;
	DMA_Stream_TypeDef *UART5_TX;

	DMA_Stream_TypeDef *USART6_RX;
	uint32_t USART6_DMA_Channel;
	DMA_Stream_TypeDef *USART6_TX;

}USART_DMA_Stream = {
					DMA2_Stream5,4,DMA2_Stream7,
					DMA1_Stream5,4,DMA1_Stream6,
					DMA1_Stream1,4,DMA1_Stream3,
					DMA1_Stream2,4,DMA1_Stream4,
					DMA1_Stream0,4,DMA1_Stream7,
					DMA2_Stream2,4,DMA2_Stream6
};




#endif /* DMA_DEFS_STREAM_H_ */

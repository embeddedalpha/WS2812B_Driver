/*
 * DMA_Defs_Config.h
 *
 *  Created on: Nov 17, 2023
 *      Author: kunal
 */

#ifndef DMA_DEFS_CONFIG_H_
#define DMA_DEFS_CONFIG_H_

#include "main.h"

static const struct DMA_Flow_Control
{
	uint32_t DMA_Control;
	uint32_t Peripheral_Control;

}DMA_Flow_Control = {0 << 5, 1 << 5};

static const struct DMA_Transfer_Direction
{
	uint32_t Peripheral_to_memory;
	uint32_t Memory_to_peripheral;
	uint32_t Memory_to_memory;

}DMA_Transfer_Direction = {0 << 6, 1 << 6, 2 << 6, };

static const struct DMA_Priority_Level
{
	uint32_t Low;
	uint32_t Medium;
	uint32_t High;
	uint32_t Very_high;

}DMA_Priority_Level = {0 << 16, 1 << 16, 2 << 16, 3<< 16 };

static const struct DMA_Peripheral_Data_Size
{
	uint32_t byte;
	uint32_t half_word;
	uint32_t word;
}DMA_Peripheral_Data_Size={0 << 11, 1 << 11, 2 << 11};

static const struct DMA_Memory_Data_Size
{
	uint32_t byte;
	uint32_t half_word;
	uint32_t word;
}DMA_Memory_Data_Size={0 << 13, 1 << 13, 2 << 13};

static const struct DMA_Circular_Mode
{
	uint32_t Enable;
	uint32_t Disable;
}DMA_Circular_Mode={1 << 8, 0 << 8};

static const struct DMA_Interrupts
{
	uint32_t Transfer_Complete;
	uint32_t Half_Transfer_Complete;
	uint32_t Transfer_Error;
	uint32_t Direct_Mode_Error;
	uint32_t Disable;

}DMA_Interrupts = {1 << 4, 1 << 3, 1 << 2, 1 << 1, 0 };


#endif /* DMA_DEFS_CONFIG_H_ */

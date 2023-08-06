/*
 * stm32f401ccu6_gpio.c
 *
 *  Created on: Jun 26, 2023
 *      Author: Mr. Tactical
 */


#include "stm32f401ccu6_gpio.h"

//Peripheral Clock setup

/******************************************************************
 * @fn			-GPIO_PeriClockControl
 *
 * @brief		-This function enable or disable peripheral clock for the given GPIO port
 * @param[in]	-Base address of gpio peripheral
 * @param[in]	-ENABLE or DISABLE macros
 *
 * @return		- none
 *
 * @note		-none
 *
 */

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnorDi)
{

	if(EnorDi == ENABLE)
	{
				if(pGPIOx == GPIOA)
				{
					GPIOA_PCLK_EN();
				}
				else if(pGPIOx == GPIOB)
				{
					GPIOB_PCLK_EN();
				}
				else if(pGPIOx == GPIOC)
						{
							GPIOC_PCLK_EN();
						}
				else if(pGPIOx == GPIOD)
						{
							GPIOD_PCLK_EN();
						}
				else if(pGPIOx == GPIOE)
						{
							GPIOE_PCLK_EN();
						}
				else if(pGPIOx == GPIOH)
						{
							GPIOH_PCLK_EN();
						}

	// Disable of GPIO

				else {if(pGPIOx == GPIOA)
							{
								GPIOA_PCLK_DI();
							}
					else if(pGPIOx == GPIOB)
							{
								GPIOB_PCLK_DI();
							}
					else if(pGPIOx == GPIOC)
							{
								GPIOC_PCLK_DI();
							}
					else if(pGPIOx == GPIOD)
							{
								GPIOD_PCLK_DI();
							}
					else if(pGPIOx == GPIOE)
							{
								GPIOE_PCLK_DI();
							}
					else if(pGPIOx == GPIOH)
							{
								GPIOH_PCLK_DI();
							}



	  }

	}

}

//Init and De-init

/******************************************************************
 * @fn			-GPIO_Init
 *
 * @brief		-This function enable or disable peripheral clock for the given GPIO port
 * @param[in]	-Base address of gpio peripheral
 * @param[in]	-ENABLE or DISABLE macros
 *
 * @return		- none
 *
 * @note		-none
 *
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. configure the pin of gpio pin
	if (pGPIOHandle->GPIO_PinConfig. <= GPIO_MODE_ANALOG)
	{

	}else
	{

	}
	//2. configure the speed
	//3. configure pupd setting
	//4. configure the optype
	//5. configure the alt functionality

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}

//Data read and write

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}
void GPIO_ToggelOutputPin(GPIO_RegDef_t *pGPIOx, uint16_t PinNumber)
{

}


//IRQ Configuration and ISR handling

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IQRPriority, uint8_t EnorDi)
{

}
void GPIO_IRQHandling(uint16_t PinNumber)
{

}

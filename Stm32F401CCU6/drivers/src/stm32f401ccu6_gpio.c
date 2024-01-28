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

		else{
					if(pGPIOx == GPIOA)
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
	uint32_t temp=0;
	//1. configure the pin of gpio pin
	if (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing bits
		pGPIOHandle->pGPIOx->MODER |= temp; // setting

	}else
	{

	}
	temp = 0;
	//2. configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing bits
	pGPIOHandle->pGPIOx->OSPEEDR = temp;
	//3. configure pupd setting
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= (0x3 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing bits
	pGPIOHandle->pGPIOx->PUPDR = temp;

	//4. configure the optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << ( 2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= (0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber); //clearing bits
	pGPIOHandle->pGPIOx->OTYPER = temp;

	temp = 0;
	//5. configure the alt functionality
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		uint32_t temp1, temp2;

		temp1 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2 )); //clearing
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2 ));

	}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{


				if(pGPIOx == GPIOA)
						{
						GPIOA_REG_RESET();
						}
				else if(pGPIOx == GPIOB)
						{
						GPIOB_REG_RESET();
						}
				else if(pGPIOx == GPIOC)
						{
					GPIOC_REG_RESET();
						}
				else if(pGPIOx == GPIOD)
						{
					GPIOD_REG_RESET();
						}
				else if(pGPIOx == GPIOE)
						{
					GPIOE_REG_RESET();
						}
				else if(pGPIOx == GPIOH)
						{
					GPIOH_REG_RESET();
						}


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

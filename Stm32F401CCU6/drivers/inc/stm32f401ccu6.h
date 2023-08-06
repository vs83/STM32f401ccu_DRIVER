/*
 * stm32f401ccu6.h
 *
 *  Created on: Jun 24, 2023
 *      Author: Mr. VIKASH SINGH
 */

#ifndef INC_STM32F401CCU6_H_
#define INC_STM32F401CCU6_H_
#include <stdint.h>
#define __vo volatile


//Some Generic macros

#define ENABLE 			1
#define DISABLE 		0
#define SET 			ENABLE
#define RESET 			DISABLE
#define GPIO_PIN_SET	SET
#define GPIO_PIN_RESET	RESET

// Base addresses of Flash and SRAM memories

#define FLASH_BASEADDR      0x08000000U       // Base address of Flash memory
#define SRAM1_BASEADDR		0x20000000U       // Base address of SRAM1
#define ROM_BASEADDR		0x1FFF0000U       // Base address of ROM
#define SRAM_BASEADDR		SRAM1_BASEADDR    // Base address of SRAM
#define OPT_BASEADDR		0x1FFF7800U       // Base address of OTP(one time programmable)


// Base addresses of AHBx and APBx Bus Peripheral

#define PERIPH_BASEADDR			0x40000000U
#define APB1PERIPH_BASEADDR		PERIPH_BASEADDR	 // Base address of APB1 peripheral
#define APB2PERIPH_BASEADDR		0x40010000U      // Base address of APB2 peripheral
#define AHB1PERIPH_BASEADDR		0x40020000U      // Base address of AHB1 peripheral
#define AHB2PERIPH_BASEADDR		0x50000000U	     // Base address of AHB2 peripheral

// Base addresses of peripherals which are hanging on AHB1 bus


#define GPIOA_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR		(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR		(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR		(AHB1PERIPH_BASEADDR + 0x1C00)
#define CRC_BASEADDR		(AHB1PERIPH_BASEADDR + 0x3000)
#define RCC_BASEADDR		(AHB1PERIPH_BASEADDR + 0x3800)
#define DMA1_BASEADDR		(AHB1PERIPH_BASEADDR + 0x6000)
#define DMA2_BASEADDR		(AHB1PERIPH_BASEADDR + 0x6400)


// Base addresses of peripherals which are hanging on APB1 bus

#define TIM2_BASEADDR			(APB1PERIPH_BASEADDR + 0x0000)
#define TIM3_BASEADDR		 	(APB1PERIPH_BASEADDR + 0x0400)
#define TIM4_BASEADDR			(APB1PERIPH_BASEADDR + 0x0800)
#define TIM5_BASEADDR			(APB1PERIPH_BASEADDR + 0x0C00)
#define RTC_BKP_BASEADDR	    (APB1PERIPH_BASEADDR + 0x2800)
#define WWDG_BASEADDR			(APB1PERIPH_BASEADDR + 0x2C00)
#define IWDG_BASEADDR			(APB1PERIPH_BASEADDR + 0x3000)
#define I2S2EXT_BASEADDR		(APB1PERIPH_BASEADDR + 0x3400)
#define SPI2_I2S2_BASEADDR		(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_I2S3_BASEADDR		(APB1PERIPH_BASEADDR + 0x3C00)
#define I2S3EXT_BASEADDR		(APB1PERIPH_BASEADDR + 0x4000)
#define USART2_BASEADDR			(APB1PERIPH_BASEADDR + 0x4400)
#define I2C1_BASEADDR			(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR			(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR			(APB1PERIPH_BASEADDR + 0x5C00)
#define PWR_BASEADDR			(APB1PERIPH_BASEADDR + 0x7000)

// Base addresses of peripherals which are hanging on AHB2 bus

#define USB_OTG_FS_BASEADDR	(AHB2PERIPH_BASEADDR + 0x0000)

// Base addresses of peripherals which are hanging on APB2 bus

#define TIM1_BASEADDR		(APB2PERIPH_BASEADDR + 0x0000)
#define USART1_BASEADDR		(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR		(APB2PERIPH_BASEADDR + 0x1400)
#define ADC1_BASEADDR		(APB2PERIPH_BASEADDR + 0x2000)
#define SDIO_BASEADDR		(APB2PERIPH_BASEADDR + 0x2C00)
#define SPI1_BASEADDR		(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR		(APB2PERIPH_BASEADDR + 0x3400)
#define SYSCFG_BASEADDR		(APB2PERIPH_BASEADDR + 0x3800)
#define EXTI_BASEADDR		(APB2PERIPH_BASEADDR + 0x3C00)
#define TIM9_BASEADDR		(APB2PERIPH_BASEADDR + 0x4000)
#define TIM10_BASEADDR		(APB2PERIPH_BASEADDR + 0x4400)
#define TIM11_BASEADDR		(APB2PERIPH_BASEADDR + 0x4800)


//Peripheral registers of GPIOx

typedef struct
{
	__vo uint32_t MODER;	//GPIO port mode register
	__vo uint32_t OTYPER;	//GPIO port output type register
	__vo uint32_t OSPEEDR;	//GPIO port output speed register
	__vo uint32_t PUPDR;    //GPIO port pull-up/pull-down register
	__vo uint32_t IDR;		//GPIO port input data register
	__vo uint32_t ODR;		//GPIO port output data register
	__vo uint32_t BSRR;		//GPIO port bit set/reset register
	__vo uint32_t LCKR;		//GPIO port configuration lock register
	__vo uint32_t AFR[2];	// AFR[0] : GPIO alternate function low register, AFR[1] : GPIO alternate function high register

}GPIO_RegDef_t;



//////////////////////////


typedef struct
{
	__vo uint32_t CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t Reserved1;
	__vo uint32_t Reserved2;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t Reserved3;
	__vo uint32_t Reserved4;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t Reserved5;
	__vo uint32_t Reserved6;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	__vo uint32_t Reserved7;
	__vo uint32_t Reserved8;
	__vo uint32_t AHB1LPENR;
	__vo uint32_t AHB2LPENR;
	__vo uint32_t Reserved9;
	__vo uint32_t Reserved10;
	__vo uint32_t APB1LPENR;
	__vo uint32_t APB2LPENR;
	__vo uint32_t Reserved11;
	__vo uint32_t Reserved12;
	__vo uint32_t BDCR;
	__vo uint32_t CSR;
	__vo uint32_t Reserved13;
	__vo uint32_t Reserved14;
	__vo uint32_t SSCGR;
	__vo uint32_t PLLI2SCFGR;
	__vo uint32_t DCKCFGR;



}RCC_RegDef_t;


// Peripherals definitions

#define GPIOA                  ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB                  ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC                  ((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD                  ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE                  ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH                  ((GPIO_RegDef_t*)GPIOH_BASEADDR)


#define RCC 				   ((RCC_RegDef_t*)RCC_BASEADDR)


// Clock enable Macros for GPIOx peripherals

#define GPIOA_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()		(RCC-> AHB1ENR |= (1 << 7))

// Clock enable Macros for I2Cx peripherals


#define I2C1_PCLK_EN()		(RCC-> APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()		(RCC-> APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()		(RCC-> APB1ENR |= (1 << 23))




// Clock enable Macros for SPIx peripherals

#define SPI1_PCLK_EN()		(RCC-> APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()		(RCC-> APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()		(RCC-> APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()		(RCC-> APB2ENR |= (1 << 13))

// Clock enable Macros for UARTx peripherals

#define USART1_PCLK_EN()		(RCC-> APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()		(RCC-> APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()		(RCC-> APB2ENR |= (1 << 5))

// Clock enable Macros for SYSCFG peripherals


// Clock disable Macros for GPIOx peripherals


#define GPIOA_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()		(RCC-> AHB1ENR &= ~(1 << 7))


// Clock disable Macros for I2Cx peripherals


#define I2C1_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 23))



// Clock enable Macros for SPIx peripherals

#define SPI1_PCLK_DI()		(RCC-> APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()		(RCC-> APB2ENR &= ~(1 << 13))



// Clock enable Macros for UARTx peripherals

#define USART1_PCLK_DI()		(RCC-> APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()		(RCC-> APB1ENR &= ~(1 << 17))
#define USART6_PCLK_DI()		(RCC-> APB2ENR &= ~(1 << 5))



#endif /* INC_STM32F401CCU6_H_ */

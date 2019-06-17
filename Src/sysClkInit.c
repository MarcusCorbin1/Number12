#include <stm32L475xx.h>
void sysClkInit (void)
{
// turn on 32.768 kHz external crystal oscillator
	RCC->BDCR 	= RCC_BDCR_LSEON + RCC_BDCR_RTCSEL_0 + RCC_BDCR_LSEDRV_1 +
	          	RCC_BDCR_LSCOSEL + RCC_BDCR_LSCOEN; 
	while(!(RCC->BDCR & RCC_BDCR_LSERDY)); // wait for 32-kHz clock to stabilize	
// turn on MSI and set it to 48-MHz
	RCC->CR 	= 	RCC_CR_MSION + RCC_CR_MSIRGSEL + RCC_CR_MSIPLLEN + 
					RCC_CR_MSIRANGE_11; 
	while(!(RCC->CR & RCC_CR_MSIRDY));
// Configure PLL -- (N = 10, M = 3, P = Q = R = 2)
	RCC->PLLCFGR = RCC_PLLCFGR_PLLREN + RCC_PLLCFGR_PLLQEN + RCC_PLLCFGR_PLLPEN +
			RCC_PLLCFGR_PLLN_1 + RCC_PLLCFGR_PLLN_3 + RCC_PLLCFGR_PLLM_1 + 
			RCC_PLLCFGR_PLLM_0 + RCC_PLLCFGR_PLLSRC_MSI; 
	RCC->PLLSAI1CFGR = RCC_PLLSAI1CFGR_PLLSAI1N_3 + RCC_PLLSAI1CFGR_PLLSAI1N_1 + 
			RCC_PLLSAI1CFGR_PLLSAI1QEN + RCC_PLLSAI1CFGR_PLLSAI1PEN + 
			RCC_PLLSAI1CFGR_PLLSAI1REN; 
	RCC->PLLSAI2CFGR = RCC_PLLSAI2CFGR_PLLSAI2N_3 + RCC_PLLSAI2CFGR_PLLSAI2N_1 + 
			RCC_PLLSAI2CFGR_PLLSAI2REN + RCC_PLLSAI2CFGR_PLLSAI2PEN;
// turn on PLL, PLLSAI1, & PLLSAI2
	RCC->CR |= RCC_CR_PLLON + RCC_CR_PLLSAI1ON + RCC_CR_PLLSAI2ON; 
// wait for PLLs to be ready
	while(!(RCC->CR & RCC_CR_PLLRDY));
	while(!(RCC->CR & RCC_CR_PLLSAI1RDY));
	while(!(RCC->CR & RCC_CR_PLLSAI2RDY));
// Select SYSCLK for MCO & select PLL as SYSCLK, HCLK, APB1, APB2 clocks not divided
	RCC->CFGR = RCC_CFGR_MCOPRE_DIV8 + RCC_CFGR_MCOSEL_0 + RCC_CFGR_SW_PLL; 
	RCC->AHB1ENR  = RCC_AHB1ENR_TSCEN + RCC_AHB1ENR_CRCEN + RCC_AHB1ENR_FLASHEN + 
				RCC_AHB1ENR_DMA2EN + RCC_AHB1ENR_DMA1EN; 
	RCC->AHB2ENR  = RCC_AHB2ENR_RNGEN + RCC_AHB2ENR_ADCEN + RCC_AHB2ENR_OTGFSEN + 
				RCC_AHB2ENR_GPIOHEN + RCC_AHB2ENR_GPIOGEN + RCC_AHB2ENR_GPIOFEN + 
				RCC_AHB2ENR_GPIOEEN + RCC_AHB2ENR_GPIODEN + RCC_AHB2ENR_GPIOCEN + 
				RCC_AHB2ENR_GPIOBEN + RCC_AHB2ENR_GPIOAEN; 
	RCC->AHB3ENR  = RCC_AHB3ENR_QSPIEN + RCC_AHB3ENR_FMCEN; 
	RCC->APB1ENR1 = RCC_APB1ENR1_LPTIM1EN + RCC_APB1ENR1_OPAMPEN + 
				RCC_APB1ENR1_DAC1EN + RCC_APB1ENR1_PWREN + 
				RCC_APB1ENR1_CAN1EN + RCC_APB1ENR1_I2C3EN + 
				RCC_APB1ENR1_I2C2EN + RCC_APB1ENR1_I2C1EN +
				RCC_APB1ENR1_UART5EN + RCC_APB1ENR1_UART4EN + 
				RCC_APB1ENR1_USART3EN + RCC_APB1ENR1_USART2EN + 
				RCC_APB1ENR1_SPI3EN + RCC_APB1ENR1_SPI2EN + 
				RCC_APB1ENR1_WWDGEN + RCC_APB1ENR1_TIM7EN + 
				RCC_APB1ENR1_TIM6EN + RCC_APB1ENR1_TIM5EN + 
				RCC_APB1ENR1_TIM4EN + RCC_APB1ENR1_TIM3EN + 
				RCC_APB1ENR1_TIM2EN;
	RCC->APB1ENR2 = RCC_APB1ENR2_LPTIM2EN + RCC_APB1ENR2_SWPMI1EN + 
				RCC_APB1ENR2_LPUART1EN;
	RCC->APB2ENR  = RCC_APB2ENR_DFSDM1EN + RCC_APB2ENR_SAI2EN + RCC_APB2ENR_SAI1EN + 
				RCC_APB2ENR_TIM17EN + RCC_APB2ENR_TIM16EN + RCC_APB2ENR_TIM15EN +
				RCC_APB2ENR_USART1EN + RCC_APB2ENR_TIM8EN + RCC_APB2ENR_SPI1EN +
				RCC_APB2ENR_TIM1EN + RCC_APB2ENR_SDMMC1EN + RCC_APB2ENR_FWEN +
				RCC_APB2ENR_SYSCFGEN;
	RCC->AHB1SMENR = RCC_AHB1SMENR_TSCSMEN + RCC_AHB1SMENR_CRCSMEN + 
				RCC_AHB1SMENR_SRAM1SMEN + RCC_AHB1SMENR_FLASHSMEN + 
				RCC_AHB1SMENR_DMA2SMEN + RCC_AHB1SMENR_DMA1SMEN; 
	RCC->AHB2SMENR = RCC_AHB2SMENR_SRAM2SMEN; 
	RCC->AHB3SMENR = 0; // disable clock input during sleep mode
	RCC->APB1SMENR1 = RCC_APB1SMENR1_PWRSMEN; 
	RCC->APB1SMENR2 = 0; 
	RCC->APB2SMENR = RCC_APB2SMENR_SYSCFGSMEN; 
	RCC->CCIPR = RCC_CCIPR_DFSDM1SEL + RCC_CCIPR_ADCSEL + RCC_CCIPR_CLK48SEL + 						
				RCC_CCIPR_SAI2SEL_0 + RCC_CCIPR_SAI1SEL_0; // LPTIM2..USART1 use PCLK as clock
}


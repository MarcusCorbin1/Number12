#include <stm32L475xx.h>
// ----------------------------------------------------------------------------------------------------------------
// This function creates a 50 us delay assuming that the clock
// input to the TIM7 is 80 MHz.
// ----------------------------------------------------------------------------------------------------------------
void delay50us(void)
{
	TIM7->PSC 	= 0; 	// set clock  input prescaler to 1
	TIM7->ARR 	= 4000;  	// set up the clock count for 50 us delay
	TIM7->CNT 	= 0; 	// force TIM7 to count up from 0
	TIM7->EGR 	= TIM_EGR_UG; 	// update ARR value
	TIM7->SR 	= 0; 	// clear the UIF flag
	TIM7->CR1 	= TIM_CR1_ARPE + TIM_CR1_CEN; // enable TIM7 and ARR auto reload
	while(!(TIM7->SR & TIM_SR_UIF)); // wait until UIF flag is set
}
// ---------------------------------------------------------------------------------------------------------------------------------------------
// This function creates a delay that is a multiple of 1 ms assuming that the clock
// input to the TIM7 is 80 MHz.
// ---------------------------------------------------------------------------------------------------------------------------------------------
void delayby1ms(uint16_t k)
{
	TIM7->PSC 	= 79; 	// set clock  input prescaler to 80
	TIM7->ARR 	= 1000; 	// set up the clock count for 1 ms delay
	TIM7->CNT 	= 0; 	// force TIM7 to count up from 0
	TIM7->EGR 	= TIM_EGR_UG; 	// update ARR value
	TIM7->SR 	= 0; 	// clear the UIF flag
	TIM7->CR1 	= TIM_CR1_ARPE + TIM_CR1_CEN; // enable TIM7 and ARR auto reload
	while (k){ // stay here until multiple count is decremented to 0
		while (!(TIM7->SR & TIM_SR_UIF));
		TIM7->SR = 0; 	// clear UIF flag to 0
		k--;
	}	
}
// ---------------------------------------------------------------------------------------------------------------------------------------------
// This function creates a delay that is a multiple of 1o ms assuming that the clock
// input to the TIM7 is 80 MHz.
// ---------------------------------------------------------------------------------------------------------------------------------------------
void delayby10ms(uint16_t k)
{
	TIM7->PSC 	= 79; 	// set clock  input prescaler to 80
	TIM7->ARR 	= 10000; 	// set up the clock count for 10 ms delay
	TIM7->CNT 	= 0; 	// force TIM7 to count up from 0
	TIM7->EGR 	= TIM_EGR_UG; 	// update ARR value
	TIM7->SR 	= 0; 	// clear the UIF flag
	TIM7->CR1 	= TIM_CR1_ARPE + TIM_CR1_CEN; // enable TIM7 and ARR auto reload
	while(k){ // stay here until multiple count is decremented to 0
		while(!(TIM7->SR & TIM_SR_UIF));
		TIM7->SR = 0; 	// clear UIF flag to 0
		k--;
	}	
}
// --------------------------------------------------------------------------------------------------------------------------------------------
// This function creates a delay that is a multiple of 100 ms assuming that the clock
// input to the TIM7 is 80 MHz.
// --------------------------------------------------------------------------------------------------------------------------------------------
void delayby100ms(uint16_t k)
{
	TIM7->PSC 	= 159; 	// set clock  input prescaler to 160
	TIM7->ARR 	= 50000; 	// set up the clock count for 100 ms delay
	TIM7->CNT 	= 0; 	// force TIM7 to count up from 0
	TIM7->EGR 	= TIM_EGR_UG; 	// update ARR value
	TIM7->SR 	= 0; 	// clear the UIF flag
	TIM7->CR1 	= TIM_CR1_ARPE + TIM_CR1_CEN; // enable TIM7 and ARR auto reload
	while(k){ // stay here until multiple count is decremented to 0
		while(!(TIM7->SR & TIM_SR_UIF));
		TIM7->SR = 0; 	// clear UIF flag to 0
		k--;
	}
}
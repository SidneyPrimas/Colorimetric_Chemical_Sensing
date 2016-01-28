#include <stdbool.h>
#include <stdlib.h>
#include "nrf.h"
#include "nrf_gpio.h"
#include "custom_pin_config.h"
#include "ltc2492_driver.h"
#include "nrf_delay.h"
#include "custom_simple_uart.h"


/**
 * @brief Function for configuring: pin 0 for input, pin 8 for output, 
 * and configures GPIOTE to give an interrupt on pin change.
 */
static void gpio_init(void)
{
	//INIT LED0: Initial state is off. 
	nrf_gpio_cfg_output(LED_0);
	nrf_gpio_cfg_output(LED_1);
	nrf_gpio_pin_write(LED_0, 1);
	
	//INIT BUTTON
	nrf_gpio_cfg_input(BUTTON_0, NRF_GPIO_PIN_NOPULL);

}


static void interrupt_init(void)  {
	// Enable interrupt:
    NVIC_EnableIRQ(GPIOTE_IRQn);
    NRF_GPIOTE->CONFIG[0] =  (GPIOTE_CONFIG_POLARITY_Toggle << GPIOTE_CONFIG_POLARITY_Pos)
                           | (0 << GPIOTE_CONFIG_PSEL_Pos)  
                           | (GPIOTE_CONFIG_MODE_Event << GPIOTE_CONFIG_MODE_Pos);
    NRF_GPIOTE->INTENSET  = GPIOTE_INTENSET_IN0_Set << GPIOTE_INTENSET_IN0_Pos;	
}


/** @brief Function for handling the GPIOTE interrupt which is triggered on pin 0 change.
 */
void GPIOTE_IRQHandler(void)
{
    // Event causing the interrupt must be cleared.
    if ((NRF_GPIOTE->EVENTS_IN[0] == 1) && 
        (NRF_GPIOTE->INTENSET & GPIOTE_INTENSET_IN0_Msk))
    {
        NRF_GPIOTE->EVENTS_IN[0] = 0;
    }
    nrf_gpio_pin_toggle(LED_0);
}


/**
 * @brief Function for application main entry.
 */
int main(void)
{
    gpio_init();
	interrupt_init();
	LTC2492_Init();
	nrf_gpio_pin_set(LED_1);
	
	simple_uart_config(RTS_PIN_NUMBER, TX_PIN_NUMBER, CTS_PIN_NUMBER, RX_PIN_NUMBER, HWFC);
	
	
	int size = 128; 
	double storage[128];
	memset(storage, 0, sizeof(*storage) * size);
	//double * storage = malloc(sizeof(*storage) * size ); 
	int i = 0; 
    while (true)
    {	
		
		nrf_delay_ms(150); 
		
		nrf_gpio_pin_toggle(LED_1);
		uint32_t output = SPI0_LTC2492_Read();
		
		uint8_t chuncks_8bit[4];
		chuncks_8bit[0] = (output & 0xFF000000) >> 24; ;
		chuncks_8bit[1] = (output & 0x00FF0000) >> 16; 
		chuncks_8bit[2] = (output & 0x0000FF00) >> 8; 
		chuncks_8bit[3] = (output & 0x000000FF) >> 0; 
		
		int count; 
		for (count = 0; count < 4; count++) {
			simple_uart_put(chuncks_8bit[count]);
		}
		
		
		
		storage[i] = output; 
		i++; 
		
		if (i == 128) {
			i = 0; 
		}
		
			
	}
	
		
}

/**
  ******************************************************************************
  * @file    ltc2492_driver.c 
  * @author  Sidney Primas
  * @version V1.0.0
  * @date   	01/24/2016
  * @brief   Driver for LTC2492
  ******************************************************************************
**/

/* Includes ------------------------------------------------------------------*/
#include "ltc2492_driver.h"
#include "math.h"
#define LTC2492_OUTPUT_VALUE_MASK (0xFFFFFE0U)
#define LTC2492_OUTPUT_SIGN_MASK (0x1UL << 28)

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint32_t *spi0_base_address;
volatile int debug; 
/* Private function prototypes -----------------------------------------------*/

//INITIALIZE SPI
int LTC2492_Init(){
	//Calls function from customer_spi_master.c to initalize SPI. 
	//Variables taken from spi_master header and spi_master_config. 
	bool lsb_first = false; 
	//spi0_base_addres is a private variable. 
	spi0_base_address = spi_master_init(SPI0, SPI_MODE0, lsb_first);
	
	

	//SPI0_LTC2492_Write(0xB0,0x00); 
	debug = SPI0_LTC2492_Read();


  
  return 1;
	
}



uint32_t SPI0_LTC2492_Read(void) {

	uint16_t transfer_size = 4;
	//Clear memory for arrays to be sent/received. 
	uint8_t tx_data[4];
	uint8_t rx_data[4]; 
	memset(&tx_data, 0, sizeof(tx_data));
	memset(&rx_data, 0, sizeof(rx_data));
	
	//Pass an array as tx and rx (wich is already a pointer to a location in the data)
	spi_master_tx_rx(spi0_base_address, transfer_size, tx_data, rx_data);
	
	uint32_t output_data = (rx_data[0] << 24 | rx_data[1] << 16 | rx_data[2] << 8 | rx_data[3] );
	
	bool is_neg = (output_data & LTC2492_OUTPUT_SIGN_MASK) >> 28; 
	
	int32_t measured_value = 0;
	if (is_neg) {
		measured_value = -1*(((~output_data & LTC2492_OUTPUT_VALUE_MASK ) >> 5));
	} else if(!is_neg) {
		measured_value = (output_data & LTC2492_OUTPUT_VALUE_MASK ) >> 5;
	}
	
	//double output = 3.3*(measured_value/(pow(2,24))); 
  
  return measured_value;
}


void SPI0_LTC2492_Write(uint8_t input1, uint8_t input2){
		
		//Bytes to be transferred. 
		uint16_t transfer_size = 2;
		//Clear memory for arrays to be sent/received. 
		uint8_t tx_data[2];
		uint8_t rx_data[2]; 
		memset(&tx_data, 0, sizeof(tx_data));
		memset(&rx_data, 0, sizeof(rx_data));
	
		//Initialize the tx variabe with byte1 => address and byte2 => value. 
		tx_data[0] = input1;
		tx_data[1] = input2; 
	
		//Pass a pointer to the tx and rx variables. 
		spi_master_tx_rx(spi0_base_address, transfer_size, tx_data, rx_data);
}

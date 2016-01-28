/**
  ******************************************************************************
  * @file    ltc2492_driver.h
  * @author  Sidney Primas
  * @version V1.0.0
  * @date    01/24/2016
  * @brief   Driver for LTC2492
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/    
#ifndef __LTC2492_DRIVER_H
#define __LTC2492_DRIVER_H

/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "nrf_gpio.h"
#include "custom_pin_config.h"
#include "spi_master_config.h"
#include "custom_spi_master.h"


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/


///////INTERRUPTs/////////
//Interrupt Enable Register
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
/**
  * @brief  Initializes SPI0 to communicate with LTC2492
  * @param  None
  * @retval None
  */
int LTC2492_Init(void);  //Initialize LTC2492



/**
  * @brief  SPI0_Read  Reads value from an ADXL345 Register
  * @param  Address of register to read value from. 
  * @retval Returns the value located in register
  */
uint32_t SPI0_LTC2492_Read(void); //Read value

/**
  * @brief  SPI0_Write Writes one word via the SPI bus.
  * @param  Register address, and value to be written to register. 
  * @retval None
  */
void SPI0_LTC2492_Write(uint8_t input1, uint8_t input2); //Write value

#endif /* __LTC2492_DRIVER_H */


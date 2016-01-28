/**
  ******************************************************************************
  * @file    custon_pin_config.h
  * @author  Sidney Primas
  * @version V1.0.0
  * @date    01/24/2016
  * @brief   Configuring Pins for NRF51 for nrf6310 Prototype Pin Configuration 
  ******************************************************************************
  */
#ifndef CUSTOM_PIN_CONFIG_H__
#define CUSTOM_PIN_CONFIG_H__

#include "nrf_gpio.h"

#define LED_0          8
#define LED_1          9
#define LED_2          10
#define LED_3          11

#define BUTTON_0       0
#define BUTTON_1       1
#define BUTTON_2       2
#define BUTTON_3       3

//UART 
#define RX_PIN_NUMBER  16    // UART RX pin number.
#define TX_PIN_NUMBER  17    // UART TX pin number.
#define CTS_PIN_NUMBER 18    // UART Clear To Send pin number. Not used if HWFC is set to false
#define RTS_PIN_NUMBER 19    // Not used if HWFC is set to false
#define HWFC           false // UART hardware flow control


#endif  // CUSTOM_PIN_CONFIG_H__

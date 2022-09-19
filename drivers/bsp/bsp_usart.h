/*
 * @brief :   
 * @date :  2022-02-xx
 * @version : v1.0.0
 * @copyright(c) 2020 : OptoMedic company Co.,Ltd. All rights reserved
 * @Change Logs:   
 * @date         author         notes:  
 */
/**
  ******************************************************************************
  * @file    usart.h
  * @brief   This file contains all the function prototypes for
  *          the usart.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

#define ENABLE_UART1 	1
#define ENABLE_UART2 	0
#define ENABLE_UART3 	0
#define ENABLE_UART4 	0
#define ENABLE_UART5 	0
#define ENABLE_UART6 	0
#define ENABLE_UART7 	0
#define ENABLE_UART8 	0

// #define ALL_COM	(void*)255

// #define USART_BUF_LEN 2560

// #define USART1_BUF_SIZE 1024

#define _GPIO_Pin(n)  GPIO_PIN_##n
#define GPIO_Pin(n)  _GPIO_Pin(n)

#define _GPIO(n)		GPIO##n
#define GPIO(n)		_GPIO(n)

//´®¿Ú1ÅäÖÃ
#define U1_Tx_Port			A
#define U1_Tx_PinNum 		9
#define U1_Rx_Port			A
#define U1_Rx_PinNum 		10

#define U1_Tx_GPIO			GPIO(U1_Tx_Port)
#define U1_Tx_GPIO_Pin		GPIO_Pin(U1_Tx_PinNum)
#define U1_Rx_GPIO			GPIO(U1_Rx_Port)
#define U1_Rx_GPIO_Pin		GPIO_Pin(U1_Rx_PinNum)

//´®¿Ú2ÅäÖÃ
#define U2_Tx_Port			A
#define U2_Tx_PinNum 		2
#define U2_Rx_Port			A
#define U2_Rx_PinNum 		3

#define U2_Tx_GPIO			GPIO(U2_Tx_Port)
#define U2_Tx_GPIO_Pin		GPIO_Pin(U2_Tx_PinNum)
#define U2_Rx_GPIO			GPIO(U2_Rx_Port)
#define U2_Rx_GPIO_Pin		GPIO_Pin(U2_Rx_PinNum)

//´®¿Ú3ÅäÖÃ
#define U3_Tx_Port			B
#define U3_Tx_PinNum 		10
#define U3_Rx_Port			B
#define U3_Rx_PinNum 		11

#define U3_Tx_GPIO			GPIO(U3_Tx_Port)
#define U3_Tx_GPIO_Pin		GPIO_Pin(U3_Tx_PinNum)
#define U3_Rx_GPIO			GPIO(U3_Rx_Port)
#define U3_Rx_GPIO_Pin		GPIO_Pin(U3_Rx_PinNum)

//´®¿Ú4ÅäÖÃ
#define U4_Tx_Port			A
#define U4_Tx_PinNum 		0
#define U4_Rx_Port			A
#define U4_Rx_PinNum 		1

#define U4_Tx_GPIO			GPIO(U4_Tx_Port)
#define U4_Tx_GPIO_Pin		GPIO_Pin(U4_Tx_PinNum)
#define U4_Rx_GPIO			GPIO(U4_Rx_Port)
#define U4_Rx_GPIO_Pin		GPIO_Pin(U4_Rx_PinNum)

//´®¿Ú5ÅäÖÃ
#define U5_Tx_Port			C
#define U5_Tx_PinNum 		12
#define U5_Rx_Port			D
#define U5_Rx_PinNum 		2

#define U5_Tx_GPIO			GPIO(U5_Tx_Port)
#define U5_Tx_GPIO_Pin		GPIO_Pin(U5_Tx_PinNum)
#define U5_Rx_GPIO			GPIO(U5_Rx_Port)
#define U5_Rx_GPIO_Pin		GPIO_Pin(U5_Rx_PinNum)

//´®¿Ú6ÅäÖÃ
#define U6_Tx_Port			C
#define U6_Tx_PinNum 		6
#define U6_Rx_Port			C
#define U6_Rx_PinNum 		7

#define U6_Tx_GPIO			GPIO(U6_Tx_Port)
#define U6_Tx_GPIO_Pin		GPIO_Pin(U6_Tx_PinNum)
#define U6_Rx_GPIO			GPIO(U6_Rx_Port)
#define U6_Rx_GPIO_Pin		GPIO_Pin(U6_Rx_PinNum)

#define U7_Tx_Port			F
#define U7_Tx_PinNum 		7
#define U7_Rx_Port			F
#define U7_Rx_PinNum 		6

#define U7_Tx_GPIO			GPIO(U7_Tx_Port)
#define U7_Tx_GPIO_Pin		GPIO_Pin(U7_Tx_PinNum)
#define U7_Rx_GPIO			GPIO(U7_Rx_Port)
#define U7_Rx_GPIO_Pin		GPIO_Pin(U7_Rx_PinNum)

#define U8_Tx_Port			E
#define U8_Tx_PinNum 		1
#define U8_Rx_Port			E
#define U8_Rx_PinNum 		0

#define U8_Tx_GPIO			GPIO(U8_Tx_Port)
#define U8_Tx_GPIO_Pin		GPIO_Pin(U8_Tx_PinNum)
#define U8_Rx_GPIO			GPIO(U8_Rx_Port)
#define U8_Rx_GPIO_Pin		GPIO_Pin(U8_Rx_PinNum)


#if ENABLE_UART1
extern UART_HandleTypeDef huart1;
#endif

#if ENABLE_UART2
extern UART_HandleTypeDef huart2;
#endif

#if ENABLE_UART3
extern UART_HandleTypeDef huart3;
#endif

#if ENABLE_UART4
extern UART_HandleTypeDef huart4;
#endif

#if ENABLE_UART5
extern UART_HandleTypeDef huart5;
#endif

#if ENABLE_UART6
extern UART_HandleTypeDef huart6;
#endif

#if ENABLE_UART7
extern UART_HandleTypeDef huart7;
#endif

#if ENABLE_UART8
extern UART_HandleTypeDef huart8;
#endif

int BSP_USART_Init(void);

void USART1_SendBytes(uint8_t *buf, uint16_t len);

#ifdef __cplusplus
}
#endif

#endif /* __USART_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

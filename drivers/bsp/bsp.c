/*
 * @brief :   
 * @date :  2022-02-xx
 * @version : v1.0.0
 * @copyright(c) 2020 : OptoMedic company Co.,Ltd. All rights reserved
 * @Change Logs:   
 * @date         author         notes:  
 */
#include "bsp.h"
#include <rtthread.h>

int BSP_Init(void)
{
    BSP_USART_Init();
    BSP_LED_Init();
}
INIT_BOARD_EXPORT(BSP_Init);
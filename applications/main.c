/*
 * Copyright (c) 2006-2019, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-11-05     yangjie      First edition
 */

#include "stm32f1xx_hal.h"
#include <rtthread.h>
#include "bsp.h"
#include "stdio.h"
#include "string.h"

void usr_thread_init(void);

int main(void)
{
    uint8_t buf[] = "stm32 rtt nano demo\r\n";

    USART1_SendBytes(buf, strlen(buf));

    float test = 2.50;

    printf("float %f\r\n", test);  // ∏°µ„ ˝¥Ú”°≤‚ ‘

    usr_thread_init();

    while (1)
    {
        BSP_LED2_Ctrl(1);
        rt_thread_mdelay(500);
        BSP_LED2_Ctrl(0);
        rt_thread_mdelay(500);
    }
}


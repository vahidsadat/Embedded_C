/*
 * uart.h
 *
 *  Created on: Jul 22, 2021
 *      Author: vahid
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f4xx.h"
void uart2_rx_interrupt_init(void);

void uart2_tx_init(void);
void uart2_rxtx_init(void);
char uart2_read(void);

#define SR_RXNE		(1U<<5)


#endif /* UART_H_ */

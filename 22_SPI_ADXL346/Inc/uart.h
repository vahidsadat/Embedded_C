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
void dma1_stream6_init(uint32_t src, uint32_t dst, uint32_t len);

#define HISR_TCIF6		(1U<<21)
#define SR_RXNE		(1U<<5)
#define HIFCR_CTCIF6		(1U<<26)

#endif /* UART_H_ */

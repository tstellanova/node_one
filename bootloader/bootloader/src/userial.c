//
// Created by Aero on 1/27/17.
//

#include <stm32.h>


uint8_t*    _uart2TxBuf[120] = {};
size_t      _uart2TxAvail = 0;


static void doUart2Cycle(void)
{
    //TODO lock buffer before sending?
    if (_uart2TxAvail > 0) {
        for(uint8_t i=0; i<_uart2TxAvail; i++) {
            USART2->DR = _uart2TxBuf[i];
            while (!(USART2->SR & USART_FLAG_TXE));
        }
        _uart2TxAvail = 0;
    }
}

void USART2_init(void)
{

}

//
//void USART2_init(void)
//{
//    /* USART configuration structure for USART1 */
//    USART_InitTypeDef usart1_init_struct;
//    /* Bit configuration structure for GPIOA PIN9 and PIN10 */
//    GPIO_InitTypeDef gpioa_init_struct;
//
//    /* Enalbe clock for USART1, AFIO and GPIOA */
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO |
//                           RCC_APB2Periph_GPIOA, ENABLE);
//
//    /* GPIOA PIN9 alternative function Tx */
//    gpioa_init_struct.GPIO_Pin = GPIO_Pin_9;
//    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
//    gpioa_init_struct.GPIO_Mode = GPIO_Mode_AF_PP;
//    GPIO_Init(GPIOA, &gpioa_init_struct);
//    /* GPIOA PIN9 alternative function Rx */
//    gpioa_init_struct.GPIO_Pin = GPIO_Pin_10;
//    gpioa_init_struct.GPIO_Speed = GPIO_Speed_50MHz;
//    gpioa_init_struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
//    GPIO_Init(GPIOA, &gpioa_init_struct);
//
//    /* Enable USART2 */
//    USART_Cmd(USART2, ENABLE);
//
//    usart1_init_struct.USART_BaudRate = 57600;
//    usart1_init_struct.USART_WordLength = USART_WordLength_8b;
//    usart1_init_struct.USART_StopBits = USART_StopBits_1;
//    usart1_init_struct.USART_Parity = USART_Parity_No ;
//    usart1_init_struct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
//    usart1_init_struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
//
//    /* Configure USART1 */
//    USART_Init(USART1, &usart1_init_struct);
//    /* Enable RXNE interrupt */
//    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
//    /* Enable USART1 global interrupt */
//    NVIC_EnableIRQ(USART1_IRQn);
//}

void USART2_write(uint8_t* buf, uint8_t len)
{
    doUart2Cycle();

    //TODO memcpy to _uart2TxBuf

}
#include "stm32f4xx.h"

volatile uint32_t ticks = 0;
uint32_t tmp;

void SysTick_Handler(void) {
    SysTick->CTRL &= ~0x01;
    ticks++;
}

void EXTI0_IRQHandler(void) {
    ticks += 10;
}

int main() {
    tmp = 0x1B;

    NVIC_SetPriorityGrouping(5);

    NVIC_SetPriority(6,  0x80 >> 4);
    NVIC_SetPriority(-1, 0x40 >> 4);

    NVIC_EnableIRQ(6);

    SysTick->LOAD = tmp;
    SysTick->CTRL = 0x07;

    NVIC_SetPendingIRQ(6);

    while (1) {}
}

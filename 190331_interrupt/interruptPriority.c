#include "stm32f4xx.h"

volatile uint32_t ticks = 0;

void EXTI0_IRQHandler(void) {  // INT1 Handler
    NVIC_SetPendingIRQ(7);     // generate the interrupt INT2
    NVIC_SetPendingIRQ(8);     // generate the interrupt INT3
    NVIC_SetPendingIRQ(9);     // generate the interrupt INT4
}

void EXTI1_IRQHandler(void) {  // INT2 Handler
    ticks += 11;
}

void EXTI2_IRQHandler(void) {  // INT3 Handler
    ticks += 12;
}

void EXTI3_IRQHandler(void) {  // INT4 Handler
    ticks += 13;
}

int main() {
    NVIC_SetPriorityGrouping(5);

    NVIC_SetPriority(6, 0x60 >> 4);   // priority of INT1 = 0x60
    NVIC_SetPriority(7, 0x40 >> 4);   // priority of INT2 = 0x40
    NVIC_SetPriority(8, 0x80 >> 4);   // priority of INT3 = 0x80
    NVIC_SetPriority(9, 0x20 >> 4);   // priority of INT4 = 0x20

    NVIC_EnableIRQ(6);     // set INT1 enable
    NVIC_EnableIRQ(7);     // set INT2 enable
    NVIC_EnableIRQ(8);     // set INT3 enable
    NVIC_EnableIRQ(9);     // set INT4 enable

    NVIC_SetPendingIRQ(6);     // generate the interrupt INT1

    while (1) {}
}

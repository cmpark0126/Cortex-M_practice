#include "stm32f4xx.h"

volatile uint32_t ticks = 0;
uint32_t tmp;

void myDelay(uint32_t loop) {
  while (loop > 0) {
    loop--;
  }
}

void SysTick_Handler(void) {
  ticks++;
  tmp = SysTick->CTRL;
  myDelay(100);
}

int main() {
  tmp = SystemCoreClock/2;

  SysTick->LOAD = tmp - 1;
  SysTick->CTRL = (0x01 | (0x01 << 1) | (0x01 << 2));

  while (1) {
  }

  return 0;
}

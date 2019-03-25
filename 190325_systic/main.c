#include "stm32f4xx.h"

volatile unit32_t ticks = 0;
unit32_t tmp;

void myDelay(unit32_t loop) {
  while (loop > 0) {
    loop--;
  }
}

void SysTick_Handler(void) {
  ticks++;
  tmp = Systick->CTRL;
  myDelay(100);
}

int main() {
  tmp = SystemCoreClock/2;

  Systick->LOAD = tmp - 1;
  SysTick->CTRL = (0x01 | (0x01 << 1) | (0x01 << 2));

  while (1) {
  }

  return 0;
}

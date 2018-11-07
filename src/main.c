#include "stm32f0xx.h"

#include <stdint.h>

/**
 * Bootloader entry point. This does several things:
 *
 * - Reads the loader information page out of the SPI flash.
 * - Upgrades the firmware currently loaded into on-board flash.
 * - Jumps to the firmware in flash.
 */
int main(int argc __attribute__((unused)),
		char* argv[] __attribute__((unused))) {
	// disable interrupts
	__disable_irq();

	// jump to firmware in flash
	volatile uint32_t *appVectors = (uint32_t *) 0x08001000;

	uint32_t initialSp = appVectors[0];
	uint32_t resetVector = appVectors[1];

    asm volatile(
    	" mov		sp, %0\n"
        " bx			%1\n"
		: : "r" (initialSp), "r" (resetVector)
    );

    // shouldn't get here
    return 0;
}

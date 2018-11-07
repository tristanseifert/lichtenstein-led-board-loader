#include "stm32f0xx.h"

#include "drivers/spi.h"

#include <stdint.h>

/**
 * Bootloader entry point. This does several things:
 *
 * - Reads the loader information page out of the SPI flash.
 * - Upgrades the firmware currently loaded into on-board flash.
 * - Jumps to the firmware in flash.
 */
__attribute__((noreturn)) void main(void) {
	// initialize the SPI driver
	spi_init();

	// disable all peripherals
	RCC->AHBENR = 0;
	RCC->APB2ENR = 0;
	RCC->APB1ENR = 0;

	// jump to firmware in flash
	volatile uint32_t *appVectors = (uint32_t *) 0x08001000;

	uint32_t initialSp = appVectors[0];
	uint32_t resetVector = appVectors[1];

    asm volatile(
    	" mov		sp, %0\n"
        " bx			%1\n"
		: : "r" (initialSp), "r" (resetVector)
    );

    // we literally cannot get back here
    while(1) {}
}

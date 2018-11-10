/*
 * loader_api.c
 *
 *  Created on: Nov 9, 2018
 *      Author: tristan
 */
#include "loader_api.h"

#include "drivers/spi_flash.h"

/**
 * Marks the currently booted version of the firmware as good.
 */
int loader_mark_fw_good(bootloader_flash_callbacks_t *callbacks) {
	return -1;
}



/**
 * Reads the loader information block from flash.
 */
int loader_read_info(bootloader_flash_callbacks_t *callbacks, bootloader_info_t *info) {
	return -1;
}

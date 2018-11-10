/*
 * loader_helpers.c
 *
 *  Created on: Nov 9, 2018
 *      Author: tristan
 */
#include "loader_helpers.h"

#include <string.h>

/// interface to the bootloader, in flash
static const bootloader_interface_t *kLoaderInfo = (bootloader_interface_t *) 0x08000fc0;

/// callbacks to use for all calls
static bootloader_flash_callbacks_t gCallbacks;


/**
 * Initializes the bootloader.
 */
void loader_init(bootloader_flash_callbacks_t *callbacks) {
	memcpy(&gCallbacks, callbacks, sizeof(bootloader_flash_callbacks_t));
}


/**
 * Marks the firmware as good.
 */
int loader_set_fw_good(void) {
	return kLoaderInfo->mark_fw_good(&gCallbacks);
}

/**
 * Reads out the bootloader info block.
 */
int loader_get_info(bootloader_info_t *info) {
	return kLoaderInfo->read_loader_info(&gCallbacks, info);
}

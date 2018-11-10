/*
 * loader_helpers.h
 *
 *  Created on: Nov 9, 2018
 *      Author: tristan
 */

#ifndef LOADER_HELPERS_H_
#define LOADER_HELPERS_H_

#include "bootloader.h"

/**
 * Initializes the bootloader.
 */
void loader_init(bootloader_flash_callbacks_t *callbacks);

/**
 * Marks the firmware as good.
 */
int loader_set_fw_good(void);

/**
 * Reads out the bootloader info block.
 */
int loader_get_info(bootloader_info_t *info);

#endif /* LOADER_HELPERS_H_ */

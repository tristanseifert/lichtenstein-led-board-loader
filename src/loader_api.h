/*
 * loader_api.h
 *
 *  Created on: Nov 9, 2018
 *      Author: tristan
 */

#ifndef LOADER_API_H_
#define LOADER_API_H_

#include "bootloader.h"

/**
 * Marks the currently booted version of the firmware as good.
 */
int loader_mark_fw_good(bootloader_flash_callbacks_t *callbacks);

/**
 * Reads the loader information block from flash.
 */
int loader_read_info(bootloader_flash_callbacks_t *callbacks, bootloader_info_t *info);

#endif /* LOADER_API_H_ */

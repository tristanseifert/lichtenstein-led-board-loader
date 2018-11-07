/*
 * info.c
 *
 * Provides the loader info structure.
 *
 *  Created on: Nov 6, 2018
 *      Author: tristan
 */
#include "bootloader.h"

#include <stddef.h>
#include <stdint.h>

/**
 * Bootloader information block, located towards the end of flash.
 */
__attribute__ ((section(".loaderinfo"),used)) static const bootloader_interface_t kLoaderInfo = {
	.version = 0x0010,

	.mark_fw_good = NULL,
	.read_loader_info = NULL,
};



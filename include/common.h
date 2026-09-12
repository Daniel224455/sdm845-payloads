//
// SPDX-FileCopyrightText: 2026 Daniel Grobert <danalexgro@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
//
#include "stdint.h"
#include "sahara.h"
#include "pbl_calls.h"

#define pbl_stack 0x1480fbb0UL
#define state     pbl_stack
#define boot_ufs 0
#define boot_ufs_and_sdcc 1
#define boot_sdcc 2
#define boot_qusb 3
#define boot_spi 4 // 5 too
#define str(x) #x
#define str2(x) str(x)
#define sahara_state (*(volatile uint32_t *)(uintptr_t)(0x1480b490))

#define swp(x) \
    (((x & 0x00000000000000FFULL) << 56) | \
     ((x & 0x000000000000FF00ULL) << 40) | \
     ((x & 0x0000000000FF0000ULL) << 24) | \
     ((x & 0x00000000FF000000ULL) << 8)  | \
     ((x & 0x000000FF00000000ULL) >> 8)  | \
     ((x & 0x0000FF0000000000ULL) >> 24) | \
     ((x & 0x00FF000000000000ULL) >> 40) | \
     ((x & 0xFF00000000000000ULL) >> 56))

#define read32(addr) \
    (*(volatile uint32_t *)(uintptr_t)(addr))

#define write32(addr, value) \
    (*(volatile uint32_t *)(uintptr_t)(addr) = (uint32_t)(value))

#define select_bdev(flash_status) \
    write32(state + 4, flash_status);

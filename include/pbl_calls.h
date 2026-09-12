//
// SPDX-FileCopyrightText: 2026 Daniel Grobert <danalexgro@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
//

#define pbl_reset_handler ((void (*)(void))0x300000)
#define pbl_is_fec_error ((void (*)(void))0x3096e0)
#define pbl_clear_general_purpose_registers ((void (*)(void))0x30213c)
#define pbl_hw_assert_ps_hold ((void (*)(void))0x310458)
#define apps_proc_init ((void (*)(void))0x3260ec) // function apparently takes param but none specified?
#define pbl_cold_boot ((void (*)(void))0x30de7c)
#define pbl_err_data_init ((void (*)(void))0x30e914)
#define pbl_memset(s, c, n) ((void (*)(void *, int32_t, uintptr_t))0x326024)((void *)(s), (int32_t)(c), (uintptr_t)(n))
#define pbl_misc_data_init ((void (*)(void))0x311460)
#define memcpy(dest, src, n) ((void *(*)(void *, void *, uintptr_t))0x325f40)((void *)(dest), (void *)(src), (uintptr_t)(n))
#define pbl_init_tmr ((void (*)(void))0x310af4)
#define pbl_init_prng ((void (*)(void))0x310a54)
#define pbl_get_speed_fuse ((void (*)(void))0x310604)
#define pbl_reset_sp(state) ((void (*)(uintptr_t))0x302214)((uintptr_t)(state))
#define mmu_init_page_table(state) ((void (*)(uintptr_t))0x310874)((uintptr_t)(state))
#define pbl_is_force_dload_disabled ((void (*)(void))0x310798)
#define pbl_is_boot_via_force_usb_boot_gpio ((void (*)(void))0x3107ac)
#define pbl_tmr_get_timestamp ((void (*)(void))0x3154bc)
#define pbl_flash_sdcc_sd_detect_on_port(state) ((void (*)(uintptr_t, uint32_t))0x30f48c)((uintptr_t)(state), (uint32_t)(port));
#define pbl_flashless_usb_detect(state) ((void (*)(uintptr_t))0x310168)((uintptr_t)(state))
#define pbl_ram_usb_init ((void (*)(void))0x311d60)
#define pbl_usb_bulk_init ((void (*)(void))0x3155ec)
#define pbl_clock_init_usb30 ((void (*)(void))0x30dac4)
#define pbl_sahara_detect_boot_data(state) ((void (*)(uintptr_t))0x311f10)((uintptr_t)(state))
#define pbl_flash_ufs_detect(state) ((void (*)(uintptr_t))0x30fc7c)((uintptr_t)(state))
#define pbl_ram_ufs_init ((void (*)(void))0x311d48)
#define pbl_flash_spi_detect(state) ((void (*)(uintptr_t))0x30f77c)((uintptr_t)(state)) // we have this thanks to Napali WP
#define pbl_ram_spi_init ((void (*)(void))0x311d30)
#define pbl_config_hw_spi ((void (*)(void))0x30e1ec)
// call the below with + 0x78 when using state
#define pbl_load_auth_elf_image(state) ((void (*)(uintptr_t))0x310bc4)((uintptr_t)(state))
#define pbl_cm_random_wait ((void (*)(void))0x30dde0)
#define pbl_cm_fault_detected ((void (*)(void))0x30dddc) // just a while (true); lmao
#define pbl_sahara_entry(state) ((void (*)(uintptr_t))0x31201c)((uintptr_t)(state)) 
#define pbl_get_expected_image ((void (*)(void))0x3102ac)
#define boot_sahara_entry(void) ((void (*)(uintptr_t))0x307fd8)((uintptr_t)(0x14810000))
#define pbl_invalidate_tlb ((void (*)(void))0x324948)
#define boot_sahara_init ((void (*)(void))0x308bd4)
#define boot_sahara_handle_hello ((void (*)(void))0x30853c)
#define boot_sahara_process_packets ((void (*)(void))0x308df8)
// PBL is 80% just authentication code. pointless to reverse when we can disable qsb
#define FUN_00306c28 (((uint32_t (*)(void))0x306c28))
#define FUN_00305c90(p1, p2) (((uintptr_t (*)(long **, uint32_t))0x305c90)((p1), (p2)))
// x3 (p4) is moved to x19 in function entry
#define FUN_00305cc0(p1, p2, p3, p4) (((uint32_t (*)(long *, int, long *, int))0x305cc0)((p1), (p2), (p3), (p4)))
#define FUN_00305610(p1, p2, p3, p4) (((uintptr_t (*)(unsigned long **, unsigned long *, long, unsigned long **))0x305610) ((p1), (p2), (p3), (p4)))
#define boot_sahara_handle_tx ((uint32_t (*)(uint8_t *, uint32_t, uint32_t *))0x308b40)
#define pbl_clean_and_invalidate_cache ((uint64_t (*)(uintptr_t, uintptr_t))0x32495c)

// apps_main_procs ftbl
#define pbl_state_init(state) ((void (*)(uintptr_t))0x30e984)((uintptr_t)(state))
#define pbl_cold_boot_hw_init(state) ((void (*)(uintptr_t))0x30df08)((uintptr_t)(state))
#define pbl_cache_init(state) ((void (*)(uintptr_t))0x30c184)((uintptr_t)(state))
#define pbl_data_init(state) ((void (*)(uintptr_t))0x30e4d4)((uintptr_t)(state))
#define pbl_hw_get_boot_option(state) ((void (*)(uintptr_t))0x3104e0)((uintptr_t)(state))
#define pbl_detect_bootable_media(state) ((void (*)(uintptr_t))0x30e58c)((uintptr_t)(state))
#define pbl_modify_page_table_attributes(state) ((void (*)(uintptr_t))0x311684)((uintptr_t)(state))
#define pbl_apps_load_auth_sbl(state) ((void (*)(uintptr_t))0x30b3d4)((uintptr_t)(state))
#define pbl_populate_share_data(state) ((void (*)(uintptr_t))0x311a40)((uintptr_t)(state))
#define pbl_exit(state) ((void (*)(uintptr_t))0x30e984)((uintptr_t)(state))
// apps_main_procs ftbl end

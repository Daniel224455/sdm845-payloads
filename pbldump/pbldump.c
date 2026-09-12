//
// SPDX-FileCopyrightText: 2026 Daniel Grobert <danalexgro@gmail.com>
// SPDX-License-Identifier: AGPL-3.0-or-later
//
#include <common.h>

#define DUMP_START 0x300000
#define DUMP_END 0x33C000

static void payload_sahara_send_rsp(const uint64_t *tx, int count)
{
  enum boot_sahara_bulk_error err_code = BULK_SUCCESS;

  enum boot_sahara_status status = SAHARA_STATUS_SUCCESS;
  struct payload_buf* pktbuf = 
    (struct payload_buf*)0x1480b498;

  // Setup packet
  for (int i = 0; i < count; i++)
      ((uint64_t*)pktbuf)[i] = swp(tx[i]);

  pbl_clean_and_invalidate_cache((uintptr_t)pktbuf, sizeof(struct payload_buf));

  do
  {          
    // Transmit packet
    boot_sahara_handle_tx((uint8_t *)pktbuf, sizeof(struct payload_buf), &err_code);
    status = SAHARA_STATUS_SUCCESS;
  } while (status != SAHARA_STATUS_SUCCESS);

  sahara_state = 0x1;
}

static void payload_sahara_dump_pbl(void)
{
  enum boot_sahara_bulk_error err_code = BULK_SUCCESS;

  enum boot_sahara_status status = SAHARA_STATUS_SUCCESS;
  struct sahara_packet_hello* packet_hello = 
    (struct sahara_packet_hello*)0x1480b498;

  // Setup packet
  packet_hello->command = 0;
  packet_hello->length = 0;
  packet_hello->version = 0;
  packet_hello->version_supported = 0;
  packet_hello->cmd_packet_length = 0;
  packet_hello->mode = 0;
  packet_hello->reserved0 = 0;
  packet_hello->reserved1 = 0;
  packet_hello->reserved2 = 0;
  packet_hello->reserved3 = 0;
  packet_hello->reserved4 = 0;
  packet_hello->reserved5 = 0;

  uint32_t src = DUMP_START;

  do
  {          
    if (src >= DUMP_END)
        break;
    memcpy(packet_hello, (void *)(uintptr_t)src, 0x400);    
    // Transmit packet
    boot_sahara_handle_tx((uint8_t *)packet_hello, sizeof(struct sahara_packet_hello), &err_code);
    src += 0x400;
    status = SAHARA_STATUS_SUCCESS;
  } while (status == SAHARA_STATUS_SUCCESS);
 
  sahara_state = 0x1;
}

__attribute__((section(".text.entry")))
void _entry(void)
{
  asm volatile(
      "mrs x0, sctlr_el3\n"
      "mov x1, #0x1000\n"
      "bic x0, x0, x1\n"
      "msr sctlr_el3, x0\n"
      "isb\n"
      "mov x0, #0xfbb0\n"
      "movk x0, #0x1480, lsl #16\n"
      "mov sp, x0\n"
      :
      :
      : "x0", "x1", "memory"
  );
  pbl_invalidate_tlb();

  // Clear sahara packet buffer
  pbl_memset(0x1480b498, 0, 0x400);

  payload_sahara_dump_pbl();

  static const uint64_t msg[] = {
    0x46696e6973686564ULL, // Finished
    0x2064756d70696e67ULL, //  dumping
    0x20426f6f74524f4dULL //  BootROM
  };

  payload_sahara_send_rsp(msg, sizeof(msg) / sizeof(msg[0]));

  pbl_cm_fault_detected();
  asm volatile (".ascii \"PBLDump\\n\"\n");
  asm volatile (".ascii \"Base: " str2(DUMP_START) "\\n\"\n");
  asm volatile (".ascii \"End: " str2(DUMP_END) "\\n\"\n");
}

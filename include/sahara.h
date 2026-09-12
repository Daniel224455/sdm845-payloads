enum boot_sahara_bulk_error
{
  BULK_SUCCESS               = 0x0,       /* success */
  BULK_ERR_PERM              = 0x1,       /* operation not permitted */
  BULK_ERR_NO_MEM            = 0x2,       /* out of heap memory */
  BULK_ERR_CANCEL            = 0x3,       /* transfer cancelled */
  BULK_ERR_SUSPENDED         = 0x4,       /* device is suspended */
  BULK_ERR_ENUMERATION       = 0x5,       /* enumeration failed */
  BULK_ERR_TIMEOUT           = 0x6,       /* operation timed out */
  BULK_ERR_BAD_PARAM         = 0x7,       /* bad parameter */
  BULK_ERR_UNKNOWN           = 0x8,       /* general error */
  BULK_ERR_READ              = 0x9,       /* read error */
  BULK_ERR_WRITE             = 0xA,       /* write error */
  BULK_ERR_CABLE_DISCONNECT  = 0xB,       /* usb cable disconnect error */
  BULK_LAST_ERROR            = 0x7FFFFFFF /* last error code */
};

/* Status codes for Sahara */
enum boot_sahara_status
{
  /* Success */
  SAHARA_STATUS_SUCCESS =                     0x00,

  /* Invalid command received in current state */
  SAHARA_NAK_INVALID_CMD =                    0x01,

  /* Protocol mismatch between host and target */
  SAHARA_NAK_PROTOCOL_MISMATCH =              0x02,

  /* Invalid target protocol version */
  SAHARA_NAK_INVALID_TARGET_PROTOCOL =        0x03,

  /* Invalid host protocol version */
  SAHARA_NAK_INVALID_HOST_PROTOCOL =          0x04,

  /* Invalid packet size received */
  SAHARA_NAK_INVALID_PACKET_SIZE =            0x05,

  /* Unexpected image ID received */
  SAHARA_NAK_UNEXPECTED_IMAGE_ID =            0x06,

  /* Invalid image header size received */
  SAHARA_NAK_INVALID_HEADER_SIZE =            0x07,

  /* Invalid image data size received */
  SAHARA_NAK_INVALID_DATA_SIZE =              0x08,

  /* Invalid image type received */
  SAHARA_NAK_INVALID_IMAGE_TYPE =             0x09,

  /* Invalid tranmission length */
  SAHARA_NAK_INVALID_TX_LENGTH =              0x0A,

  /* Invalid reception length */
  SAHARA_NAK_INVALID_RX_LENGTH =              0x0B,

  /* General transmission or reception error */
  SAHARA_NAK_GENERAL_TX_RX_ERROR =            0x0C,

  /* Error while transmitting READ_DATA packet */
  SAHARA_NAK_READ_DATA_ERROR =                0x0D,

  /* Cannot receive specified number of program headers */
  SAHARA_NAK_UNSUPPORTED_NUM_PHDRS =          0x0E,

  /* Invalid data length received for program headers */
  SAHARA_NAK_INVALID_PDHR_SIZE =              0x0F,

  /* Multiple shared segments found in ELF image */
  SAHARA_NAK_MULTIPLE_SHARED_SEG =            0x10,

  /* Uninitialized program header location */
  SAHARA_NAK_UNINIT_PHDR_LOC =                0x11,

  /* Invalid destination address */
  SAHARA_NAK_INVALID_DEST_ADDR =              0x12,

  /* Invalid data size receieved in image header */
  SAHARA_NAK_INVALID_IMG_HDR_DATA_SIZE =      0x13,

  /* Invalid ELF header received */
  SAHARA_NAK_INVALID_ELF_HDR =                0x14,

  /* Unknown host error received in HELLO_RESP */
  SAHARA_NAK_UNKNOWN_HOST_ERROR =             0x15,

  /* Timeout while receiving data */
  SAHARA_NAK_TIMEOUT_RX =                     0x16,

  /* Timeout while transmitting data */
  SAHARA_NAK_TIMEOUT_TX =                     0x17,

  /* Invalid mode received from host */
  SAHARA_NAK_INVALID_HOST_MODE =              0x18,

  /* Invalid memory read access */
  SAHARA_NAK_INVALID_MEMORY_READ =            0x19,

  /* Host cannot handle read data size requested */
  SAHARA_NAK_INVALID_DATA_SIZE_REQUEST =      0x1A,

  /* Memory debug not supported */
  SAHARA_NAK_MEMORY_DEBUG_NOT_SUPPORTED =     0x1B,

  /* Invalid mode switch */
  SAHARA_NAK_INVALID_MODE_SWITCH =            0x1C,

  /* Failed to execute command */
  SAHARA_NAK_CMD_EXEC_FAILURE =               0x1D,

  /* Invalid parameter passed to command execution */
  SAHARA_NAK_EXEC_CMD_INVALID_PARAM =         0x1E,

  /* Unsupported client command received */
  SAHARA_NAK_EXEC_CMD_UNSUPPORTED =           0x1F,

  /* Invalid client command received for data response */
  SAHARA_NAK_EXEC_DATA_INVALID_CLIENT_CMD =   0x20,

  /* Failed to authenticate hash table */
  SAHARA_NAK_HASH_TABLE_AUTH_FAILURE =        0x21,

  /* Failed to verify hash for a given segment of ELF image */
  SAHARA_NAK_HASH_VERIFICATION_FAILURE =      0x22,

  /* Failed to find hash table in ELF image */
  SAHARA_NAK_HASH_TABLE_NOT_FOUND =           0x23,

  /* Target failed to initialize */
  SAHARA_NAK_TARGET_INIT_FAILURE =            0x24,

  /* Failed to authenticate generic image */
  SAHARA_NAK_IMAGE_AUTH_FAILURE  =            0x25,  

  /* Invalid ELF hash table size.  Too bit or small. */
  SAHARA_NAK_INVALID_IMG_HASH_TABLE_SIZE =    0x26,

  /* Place all new error codes above this */
  SAHARA_NAK_LAST_CODE,

  SAHARA_NAK_MAX_CODE = 0x7FFFFFFF /* To ensure 32-bits wide */
};

struct sahara_packet_hello
{
  uint32_t command;                 /* command ID */
  uint32_t length;                  /* packet length incl command and length */
  uint32_t version;                 /* target protocol version number */
  uint32_t version_supported;       /* minimum protocol version number supported */
                                  /*   on target */
  uint32_t cmd_packet_length;       /* maximum packet size supported for command */
                                  /*   packets */
  uint32_t mode;                    /* expected mode of target operation */
  uint32_t reserved0;               /* reserved field */
  uint32_t reserved1;               /* reserved field */
  uint32_t reserved2;               /* reserved field */
  uint32_t reserved3;               /* reserved field */
  uint32_t reserved4;               /* reserved field */
  uint32_t reserved5;               /* reserved field */
  uint8_t  extra[0x400 - 0x30];
};

struct payload_buf
{
  uint8_t  data[0x400];
};

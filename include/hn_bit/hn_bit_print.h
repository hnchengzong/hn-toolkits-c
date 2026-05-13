#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#ifndef HN_BIN_NO_LEADING_ZEROS
#define HN_BIN_NO_LEADING_ZEROS 0x01
#endif

#ifndef HN_BIN_SPACE_4
#define HN_BIN_SPACE_4 0x02
#endif

#ifndef HN_BIN_SPACE_8
#define HN_BIN_SPACE_8 0x04
#endif

#ifndef HN_BIN_PREFIX_0B
#define HN_BIN_PREFIX_0B 0x08
#endif

#define hn_bit_print_bin(val, flags)                                           \
  _Generic((val),                                                              \
      uint8_t: hn_bit_print_bin8,                                              \
      uint16_t: hn_bit_print_bin16,                                            \
      uint32_t: hn_bit_print_bin32,                                            \
      uint64_t: hn_bit_print_bin64)((val), (flags))

#define hn_bit_bin_to_str(buf, buf_size, val, flags)                           \
  _Generic((val),                                                              \
      uint8_t: hn_bit_bin_to_str8,                                             \
      uint16_t: hn_bit_bin_to_str16,                                           \
      uint32_t: hn_bit_bin_to_str32,                                           \
      uint64_t: hn_bit_bin_to_str64)((buf), (buf_size), (val), (flags))

#define HN_BIN_BUF_SIZE(bits) ((bits) + ((bits) / 4) + ((bits) / 8) + 3)
#define hn_bit_println_bin(val, flags)                                         \
  do {                                                                         \
    hn_bit_print_bin((val), (flags));                                          \
    putchar('\n');                                                             \
  } while (0)

extern void hn_bit_print_bin8(uint8_t val, int flags);
extern void hn_bit_print_bin16(uint16_t val, int flags);
extern void hn_bit_print_bin32(uint32_t val, int flags);
extern void hn_bit_print_bin64(uint64_t val, int flags);

extern size_t hn_bit_bin_to_str8(char *buf, size_t buf_size, uint8_t val,
                                 int flags);
extern size_t hn_bit_bin_to_str16(char *buf, size_t buf_size, uint16_t val,
                                  int flags);
extern size_t hn_bit_bin_to_str32(char *buf, size_t buf_size, uint32_t val,
                                  int flags);
extern size_t hn_bit_bin_to_str64(char *buf, size_t buf_size, uint64_t val,
                                  int flags);
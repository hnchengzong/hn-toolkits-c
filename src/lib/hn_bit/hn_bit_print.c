#include "../include/hn_bit/hn_bit_print.h"
#include <stdio.h>
#include <string.h>

static inline size_t hn_bit_bin_to_str_generic(char *restrict buf,
                                               size_t buf_size, uint64_t val,
                                               int bits, int flags) {
  if (!buf || buf_size == 0)
    return 0;

  char *ptr = buf;
  const char *end = buf + buf_size - 1;
  bool leading_zero = true;
  int space_counter = 0;

  if (flags & HN_BIN_PREFIX_0B) {
    if (ptr + 2 > end)
      goto done; // 我使用了goto，因为它能统一处理，跳出多层嵌套。
    *ptr = '0';
    ptr++;
    *ptr = 'b';
    ptr++;
  }

  for (int i = bits - 1; i >= 0; i--) {
    uint64_t bit = (val >> i) & 1;

    if (leading_zero && bit == 0 && (flags & HN_BIN_NO_LEADING_ZEROS)) {
      if (i == 0) {
        if (ptr >= end)
          goto done;
        *ptr++ = '0';
      }
      continue;
    }

    leading_zero = false;

    if (space_counter > 0) {
      if ((flags & HN_BIN_SPACE_8) && (space_counter % 8 == 0)) {
        if (ptr >= end)
          goto done;
        *ptr = ' ';
        ptr++;
      } else if ((flags & HN_BIN_SPACE_4) && (space_counter % 4 == 0)) {
        if (ptr >= end)
          goto done;
        *ptr = ' ';
        ptr++;
      }
    }

    if (ptr >= end)
      goto done;
    *ptr = '0' + (char)bit;
    ptr++;
    space_counter++;
  }

done:
  *ptr = '\0';
  return (size_t)(ptr - buf);
}

size_t hn_bit_bin_to_str8(char *restrict buf, size_t buf_size, uint8_t val,
                          int flags) {
  return hn_bit_bin_to_str_generic(buf, buf_size, val, 8, flags);
}

size_t hn_bit_bin_to_str16(char *restrict buf, size_t buf_size, uint16_t val,
                           int flags) {
  return hn_bit_bin_to_str_generic(buf, buf_size, val, 16, flags);
}

size_t hn_bit_bin_to_str32(char *restrict buf, size_t buf_size, uint32_t val,
                           int flags) {
  return hn_bit_bin_to_str_generic(buf, buf_size, val, 32, flags);
}

size_t hn_bit_bin_to_str64(char *restrict buf, size_t buf_size, uint64_t val,
                           int flags) {
  return hn_bit_bin_to_str_generic(buf, buf_size, val, 64, flags);
}

static inline void hn_bit_print_bin_generic(uint64_t val, int bits, int flags) {
  char buf[HN_BIN_BUF_SIZE(64)];
  hn_bit_bin_to_str_generic(buf, sizeof(buf), val, bits, flags);
  fputs(buf, stdout);
}

void hn_bit_print_bin8(uint8_t val, int flags) {
  hn_bit_print_bin_generic(val, 8, flags);
  fprintf(stdout, "\n");
}

void hn_bit_print_bin16(uint16_t val, int flags) {
  hn_bit_print_bin_generic(val, 16, flags);
  fprintf(stdout, "\n");
}

void hn_bit_print_bin32(uint32_t val, int flags) {
  hn_bit_print_bin_generic(val, 32, flags);
  fprintf(stdout, "\n");
}

void hn_bit_print_bin64(uint64_t val, int flags) {
  hn_bit_print_bin_generic(val, 64, flags);
  fprintf(stdout, "\n");
}
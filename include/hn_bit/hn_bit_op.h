#pragma once

#include <stdbool.h>
#include <stdint.h>

#define hn_bit_set(val, n)                                                     \
  _Generic((val),                                                              \
      uint8_t: hn_bit_set8,                                                    \
      uint16_t: hn_bit_set16,                                                  \
      uint32_t: hn_bit_set32,                                                  \
      uint64_t: hn_bit_set64)((val), (n))

#define hn_bit_clr(val, n)                                                     \
  _Generic((val),                                                              \
      uint8_t: hn_bit_clr8,                                                    \
      uint16_t: hn_bit_clr16,                                                  \
      uint32_t: hn_bit_clr32,                                                  \
      uint64_t: hn_bit_clr64)((val), (n))

#define hn_bit_flip(val, n)                                                    \
  _Generic((val),                                                              \
      uint8_t: hn_bit_flip8,                                                   \
      uint16_t: hn_bit_flip16,                                                 \
      uint32_t: hn_bit_flip32,                                                 \
      uint64_t: hn_bit_flip64)((val), (n))

#define hn_bit_test(val, n)                                                    \
  _Generic((val),                                                              \
      uint8_t: hn_bit_test8,                                                   \
      uint16_t: hn_bit_test16,                                                 \
      uint32_t: hn_bit_test32,                                                 \
      uint64_t: hn_bit_test64)((val), (n))

uint8_t hn_bit_set8(uint8_t val, int n);
uint16_t hn_bit_set16(uint16_t val, int n);
uint32_t hn_bit_set32(uint32_t val, int n);
uint64_t hn_bit_set64(uint64_t val, int n);

uint8_t hn_bit_clr8(uint8_t val, int n);
uint16_t hn_bit_clr16(uint16_t val, int n);
uint32_t hn_bit_clr32(uint32_t val, int n);
uint64_t hn_bit_clr64(uint64_t val, int n);

uint8_t hn_bit_flip8(uint8_t val, int n);
uint16_t hn_bit_flip16(uint16_t val, int n);
uint32_t hn_bit_flip32(uint32_t val, int n);
uint64_t hn_bit_flip64(uint64_t val, int n);

bool hn_bit_test8(uint8_t val, int n);
bool hn_bit_test16(uint16_t val, int n);
bool hn_bit_test32(uint32_t val, int n);
bool hn_bit_test64(uint64_t val, int n);
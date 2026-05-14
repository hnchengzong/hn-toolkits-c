#pragma once

#include <stdbool.h>
#include <stdint.h>

#ifndef hn_bit_cond
#define hn_bit_cond(val, n)                                                    \
  _Generic((val),                                                              \
      uint8_t: hn_bit_cond8,                                                   \
      uint16_t: hn_bit_cond16,                                                 \
      uint32_t: hn_bit_cond32,                                                 \
      uint64_t: hn_bit_cond64)((val), (n))
#endif

// n为0则返回false。
bool hn_bit_cond8(uint8_t val, uint8_t n);
bool hn_bit_cond16(uint16_t val, uint16_t n);
bool hn_bit_cond32(uint32_t val, uint32_t n);
bool hn_bit_cond64(uint64_t val, uint64_t n);

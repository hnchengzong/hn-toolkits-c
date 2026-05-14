#include "../include/hn_bit/hn_bit_cond.h"

bool hn_bit_cond8(uint8_t val, uint8_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1U;
}

bool hn_bit_cond16(uint16_t val, uint16_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1U;
}

bool hn_bit_cond32(uint32_t val, uint32_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1UL;
}

bool hn_bit_cond64(uint64_t val, uint64_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1ULL;
}
#include "../include/hn_bit/hn_bit_op.h"
#include <stdint.h>
uint8_t hn_bit_set8(uint8_t val, uint8_t n) {
  if (n == 0)
    return val;
  return val | (1U << (n - 1));
}

uint16_t hn_bit_set16(uint16_t val, uint16_t n) {
  if (n == 0)
    return val;
  return val | (1U << (n - 1));
}

uint32_t hn_bit_set32(uint32_t val, uint32_t n) {
  if (n == 0)
    return val;
  return val | (1UL << (n - 1));
}

uint64_t hn_bit_set64(uint64_t val, uint64_t n) {
  if (n == 0)
    return val;
  return val | (1ULL << (n - 1));
}

uint8_t hn_bit_clr8(uint8_t val, uint8_t n) {
  if (n == 0)
    return val;
  return val & ~(1U << (n - 1));
}

uint16_t hn_bit_clr16(uint16_t val, uint16_t n) {
  if (n == 0)
    return val;
  return val & ~(1U << (n - 1));
}

uint32_t hn_bit_clr32(uint32_t val, uint32_t n) {
  if (n == 0)
    return val;
  return val & ~(1UL << (n - 1));
}

uint64_t hn_bit_clr64(uint64_t val, uint64_t n) {
  if (n == 0)
    return val;
  return val & ~(1ULL << (n - 1));
}

uint8_t hn_bit_flip8(uint8_t val, uint8_t n) {
  if (n == 0)
    return val;
  return val ^ (1U << (n - 1));
}

uint16_t hn_bit_flip16(uint16_t val, uint16_t n) {
  if (n == 0)
    return val;
  return val ^ (1U << (n - 1));
}

uint32_t hn_bit_flip32(uint32_t val, uint32_t n) {
  if (n == 0)
    return val;
  return val ^ (1UL << (n - 1));
}

uint64_t hn_bit_flip64(uint64_t val, uint64_t n) {
  if (n == 0)
    return val;
  return val ^ (1ULL << (n - 1));
}

bool hn_bit_test8(uint8_t val, uint8_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1U;
}

bool hn_bit_test16(uint16_t val, uint16_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1U;
}

bool hn_bit_test32(uint32_t val, uint32_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1UL;
}

bool hn_bit_test64(uint64_t val, uint64_t n) {
  if (n == 0)
    return false;
  return (val >> (n - 1)) & 1ULL;
}
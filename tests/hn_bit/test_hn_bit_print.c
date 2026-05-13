#include "../include/hn_bit/hn_bit_print.h"

int main(void) {
  const uint8_t a = 0xAB;
  const uint32_t b = 0xDEADBEEF;

  hn_bit_println_bin(a, HN_BIN_PREFIX_0B | HN_BIN_SPACE_4);
  hn_bit_println_bin(b, HN_BIN_SPACE_8);
  return 0;
}
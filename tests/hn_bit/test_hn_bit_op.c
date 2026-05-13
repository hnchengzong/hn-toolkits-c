#include "../include/hn_bit/hn_bit_op.h"
#include "hn_bit/hn_bit_print.h"

int main(void) {
  uint8_t a = 0;
  a = hn_bit_set(a, 0);
  hn_bit_print_bin8(a, 0);
  a = hn_bit_set(a, 3);
  hn_bit_print_bin8(a, 0);
  a = hn_bit_flip(a, 5);
  hn_bit_print_bin8(a, 0);
  a = hn_bit_clr(a, 3);
  hn_bit_print_bin8(a, 0);

  const uint32_t b = 0x12345678;
  hn_bit_print_bin32(b, 0);

  return 0;
}
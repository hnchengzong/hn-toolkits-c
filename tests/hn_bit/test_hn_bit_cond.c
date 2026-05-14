#include "../include/hn_base/hn_type.h"
#include "../include/hn_bit/hn_bit_cond.h"
#include <stdio.h>

int main(void) {
  const i8 a = 0b00000001;
  fprintf(stdout, "hn_bit_cond8(a, 0) = %d\n", hn_bit_cond8(a, 0));
  fprintf(stdout, "hn_bit_cond8(a, 1) = %d\n", hn_bit_cond8(a, 1));
  return 0;
}
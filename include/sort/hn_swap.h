#pragma once

#ifndef SWAP
#define SWAP(a, b)                                                             \
  do {                                                                         \
    typeof(a) ____tmp = (a);                                                   \
    (a) = (b);                                                                 \
    (b) = ____tmp;                                                             \
  } while (0)
#endif

#include <string.h>

static inline void swap(void *restrict a, void *restrict b,
                        size_t byte_length) {
  unsigned char buf[byte_length];
  memcpy(buf, a, byte_length);
  memcpy(a, b, byte_length);
  memcpy(b, buf, byte_length);
}

static inline void swap_int_xor(int *a, int *b) {
  if (a == b) {
    return;
  }
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
} /* performance may not be better because the compiler can optimize the swap
     function that uses a temp variable */
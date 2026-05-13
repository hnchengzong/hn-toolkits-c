#pragma once

#define SWAP(a, b)                                                             \
  do {                                                                         \
    typeof(a) ____tmp = (a);                                                   \
    (a) = (b);                                                                 \
    (b) = ____tmp;                                                             \
  } while (0)

#include <string.h>

static inline void swap(void *restrict a, void *restrict b,
                        size_t byte_length) {
  unsigned char buf[byte_length];
  memcpy(buf, a, byte_length);
  memcpy(a, b, byte_length);
  memcpy(b, buf, byte_length);
}
#include "../include/recursion/hanoi.h"

#include <stddef.h>
#include <stdio.h>
void hanoi(size_t n, char src, char temp, char dest) {
  if (n == 0) {
    return;
  }

  hanoi(n - 1, src, dest, temp);

  printf("move %zu: %c -> %c\n", n, src, dest);

  hanoi(n - 1, temp, src, dest);
}
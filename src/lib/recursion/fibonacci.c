#include "../include/recursion/fibonacci.h"
#include <stddef.h>

size_t fib_recur(size_t n) {
  if (n <= 2)
    return 1;
  return fib_recur(n - 1) + fib_recur(n - 2);
}

size_t fib_iter(size_t n) {
  if (n <= 2)
    return 1;

  size_t a = 1, b = 1, res;
  for (size_t i = 3; i <= n; ++i) {
    res = a + b;
    a = b;
    b = res;
  }
  return res;
}

size_t fib_seq(size_t a1, size_t a2, size_t n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return a1;
  if (n == 2)
    return a2;

  size_t current;
  for (size_t i = 3; i <= n; ++i) {
    current = a1 + a2;
    a1 = a2;
    a2 = current;
  }
  return a2;
}
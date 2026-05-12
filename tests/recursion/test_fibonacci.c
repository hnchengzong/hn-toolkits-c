#include "../include/recursion/fibonacci.h"
#include <stddef.h>
#include <stdio.h>
int main(void) {
  const size_t fib_n = 30;
  fprintf(stdout, "fibonacci(%zu) = %zu\n", fib_n, fib_recur(fib_n));
  fprintf(stdout, "fibonacci(%zu) = %zu\n", fib_n, fib_iter(fib_n));

  size_t n = 0;
  size_t a1 = 0;
  size_t a2 = 0;
  fprintf(stdout, "fibonacci(enter a1, a2, n): ");
  scanf("%zu %zu %zu", &a1, &a2, &n);
  fprintf(stdout, "fibonacci(%zu, %zu, %zu) = %zu\n", a1, a2, n,
          fib_seq(a1, a2, n));
}
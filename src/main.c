#include "foo.h"
#include <assert.h>
#include <stdio.h>

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  const auto x = 10, y = 20;
  const int z = add(1, 2);
  fprintf(stdout, "add(1, 2) = %d\n", z);

  return 0;
}

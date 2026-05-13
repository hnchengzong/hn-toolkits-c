#include "../include/hn_base/hn_base.h"
#include "../include/hn_base/hn_type.h"
#include <stdio.h>

int main(void) {
  const i8 a = -5;
  const i8 b = 255; // b=-1
  fprintf(stdout, "Min: %d, Max: %d\n", hn_min(a, b), hn_max(a, b));
  const u8 c = 255;
  fprintf(stdout, "u8: %u\n", c);
  const f32 e = -3.14;
  const f32 f = hn_abs(e);
  fprintf(stdout, "Abs: %f\n", f);
  const i16 arr[] = {1, 2, 3, 4, 5};
  fprintf(stdout, "sizeof(arr): %zu, sizeof(arr[0]): %zu\n", sizeof(arr),
          sizeof(arr[0]));
  fprintf(stdout, "Array length: %d\n", hn_array_len(arr));
  u64 x = 10;
  fprintf(stdout, "x: %lu\n", x);
  const u64 y = hn_clamp(x, 5, 20);
  fprintf(stdout, "Clamped: %d\n", y);
  return 0;
}

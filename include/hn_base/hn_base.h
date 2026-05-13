#pragma once

#define HN_PI 3.1415926535
#define HN_E 2.7182818284

#define hn_min(a, b) ((a) < (b) ? (a) : (b))
#define hn_max(a, b) ((a) > (b) ? (a) : (b))
#define hn_clamp(x, min, max) hn_min(hn_max((x), (min)), (max))
#define hn_abs(x) ((x) < 0 ? -(x) : (x))

#define hn_array_len(arr) (sizeof(arr) / sizeof((arr)[0]))
#define hn_offsetof(type, member) ((usize) & ((type *)0)->member)
#define hn_container_of(ptr, type, member)                                     \
  ((type *)((u8 *)(ptr) - hn_offsetof(type, member)))
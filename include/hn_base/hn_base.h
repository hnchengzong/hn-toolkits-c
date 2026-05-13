#pragma once

#ifndef HN_PI
#define HN_PI 3.1415926535
#endif

#ifndef HN_E
#define HN_E 2.7182818284
#endif

#ifndef hn_min
#define hn_min(a, b) ((a) < (b) ? (a) : (b))
#endif

#ifndef hn_max
#define hn_max(a, b) ((a) > (b) ? (a) : (b))
#endif

#ifndef hn_clamp
#define hn_clamp(x, min, max) hn_min(hn_max((x), (min)), (max))
#endif

#ifndef hn_abs
#define hn_abs(x) ((x) < 0 ? -(x) : (x))
#endif

#ifndef hn_array_len
#define hn_array_len(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif

#ifndef hn_offsetof
#define hn_offsetof(type, member) ((usize) & ((type *)0)->member)
#endif

#ifndef hn_container_of
#define hn_container_of(ptr, type, member)                                     \
  ((type *)((u8 *)(ptr) - hn_offsetof(type, member)))
#endif
#pragma once

#define swap(a, b)                                                             \
  do {                                                                         \
    typeof(a) _tmp = (a);                                                      \
    (a) = (b);                                                                 \
    (b) = _tmp;                                                                \
  } while (0)

extern void bubble_sort(int *arr, int length);
extern void selection_sort(int *arr, int length);
extern void insertion_sort(int *arr, int length);
extern void shell_sort(int *arr, int length);

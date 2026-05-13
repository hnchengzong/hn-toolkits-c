#include "../include/sort/sort.h"
#include <stdlib.h>

static void merge(int *restrict arr, int mid, int length, int *restrict temp) {
  int i = 0, j = mid, k = 0;
  while (i < mid && j < length) {
    if (arr[i] < arr[j])
      temp[k++] = arr[i++];
    else
      temp[k++] = arr[j++];
  }
  while (i < mid)
    temp[k++] = arr[i++];
  while (j < length)
    temp[k++] = arr[j++];
  for (i = 0; i < length; i++)
    arr[i] = temp[i];
}

static void merge_sort_core(int *restrict arr, int length, int *restrict temp) {
  if (length <= 1)
    return;
  int mid = length / 2;
  merge_sort_core(arr, mid, temp);
  merge_sort_core(arr + mid, length - mid, temp);
  merge(arr, mid, length, temp);
}

void merge_sort(int *restrict arr, int length) {
  if (length <= 1)
    return;
  int *temp = malloc(length * sizeof(int));
  merge_sort_core(arr, length, temp);
  free(temp);
}

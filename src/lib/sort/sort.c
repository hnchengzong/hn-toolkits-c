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
  int *restrict temp = malloc(length * sizeof(int));
  merge_sort_core(arr, length, temp);
  free(temp);
}

static void quick_sort_core(int *restrict arr, int left, int right) {
  if (left >= right)
    return;

  int pivot = arr[left];
  int l = left;
  int r = right;

  while (l < r) {
    while (l < r && arr[r] >= pivot)
      r--;
    arr[l] = arr[r];

    while (l < r && arr[l] <= pivot)
      l++;
    arr[r] = arr[l];
  }

  arr[l] = pivot;
  quick_sort_core(arr, left, l - 1);
  quick_sort_core(arr, l + 1, right);
}

void quick_sort(int *restrict arr, int length) {
  quick_sort_core(arr, 0, length - 1);
}

static void heap_adjust(int *restrict arr, int idx, int n) {
  int largest = idx;
  int left = idx * 2 + 1;
  int right = idx * 2 + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;
  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != idx) {
    int temp = arr[idx];
    arr[idx] = arr[largest];
    arr[largest] = temp;
    heap_adjust(arr, largest, n);
  }
}

void heap_sort(int *restrict arr, int length) {
  for (int i = length / 2 - 1; i >= 0; i--)
    heap_adjust(arr, i, length);

  for (int i = length - 1; i > 0; i--) {
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heap_adjust(arr, 0, i);
  }
}

#include "../include/sort/simple_sort.h"
#include "sort/hn_swap.h"

void bubble_sort(int *arr, int length) {
  for (auto i = 0; i < length; i++) {
    for (auto j = 0; j < length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        SWAP(arr[j], arr[j + 1]);
      }
    }
  }
}

void selection_sort(int *arr, int length) {
  for (auto i = 0; i < length - 1; i++) {
    int min = i;
    for (auto j = i + 1; j < length; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    SWAP(arr[i], arr[min]);
  }
}

void insertion_sort(int *arr, int length) {
  for (auto i = 1; i < length; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void shell_sort(int *arr, int length) {
  for (auto gap = length / 2; gap > 0; gap /= 2) {
    for (auto i = gap; i < length; i++) {
      int temp = arr[i];
      int j;
      for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}

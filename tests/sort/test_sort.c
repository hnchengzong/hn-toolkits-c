#include "../include/sort/sort.h"
#include <stdio.h>
#include <string.h>

int main(void) {
  int test_sort[] = {5,  2,  9,  1,  5,  6,  12, 75,  123,  25,
                     56, 78, 96, 34, 23, 49, 67, 99,  91,   67,
                     48, 34, 24, 46, 68, 89, 90, 234, 12344};
  const int length = sizeof(test_sort) / sizeof(test_sort[0]);

  char input[20] = "\0";
  fprintf(stdout, "Enter sort method (merge/quick): \n");
  scanf("%19s", input);

  if (strcmp(input, "merge") != 0 && strcmp(input, "quick") != 0 &&
      strcmp(input, "heap") != 0) {
    fprintf(stderr, "Unknown sort method: %s\n", input);
    return 1;
  }
  if (strcmp(input, "merge") == 0) {
    merge_sort(test_sort, length);
  }
  if (strcmp(input, "quick") == 0) {
    quick_sort(test_sort, length);
  }
  if (strcmp(input, "heap") == 0) {
    heap_sort(test_sort, length);
  }
  fprintf(stdout, "Sorted array: ");
  for (size_t i = 0; i < length; i++) {
    fprintf(stdout, "%d ", test_sort[i]);
  }
  fprintf(stdout, "\n");
}
#include "../include/sort/simple_sort.h"
#include <stdio.h>
#include <string.h>

int main() {

  const int test_sort[] = {5,  2,  9,  1,  5,  6,  12, 45, 123,
                           23, 56, 78, 90, 34, 23, 45, 67, 89,
                           90, 67, 45, 34, 23, 45, 67, 89, 90};
  const int length = sizeof(test_sort) / sizeof(test_sort[0]);

  char input[20] = "\0";
  fprintf(stdout,
          "Enter simple_sort method (bubble/selection/insertion/shell): \n");
  scanf("%19s", input);

  if (strcmp(input, "bubble") != 0 && strcmp(input, "selection") != 0 &&
      strcmp(input, "insertion") != 0 && strcmp(input, "shell") != 0) {
    fprintf(stderr, "Unknown sort method: %s\n", input);
    return 1;
  }
  if (strcmp(input, "bubble") == 0) {
    bubble_sort(test_sort, length);
  }
  if (strcmp(input, "selection") == 0) {
    selection_sort(test_sort, length);
  }
  if (strcmp(input, "insertion") == 0) {
    insertion_sort(test_sort, length);
  }
  if (strcmp(input, "shell") == 0) {
    shell_sort(test_sort, length);
  }

  fprintf(stdout, "Sorted array: ");
  for (size_t i = 0; i < length; i++) {
    fprintf(stdout, "%d ", test_sort[i]);
  }
  fprintf(stdout, "\n");
}
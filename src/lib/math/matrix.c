#include "../include/math/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

matrix_t *hn_matrix_create(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    return NULL;
  }
  matrix_t *mat = malloc(sizeof(matrix_t));
  if (!mat) {
    return NULL;
  }
  mat->rows = rows;
  mat->cols = cols;
  mat->data = malloc((size_t)rows * cols * sizeof(double));
  if (!mat->data) {
    free(mat);
    return NULL;
  }
  return mat;
}

void hn_matrix_free(matrix_t *restrict mat) {
  if (!mat) {
    return;
  }
  free(mat->data);
  free(mat);
}

double hn_matrix_get(const matrix_t *mat, int r, int c) {
  if (!mat || r < 0 || r >= mat->rows || c < 0 || c >= mat->cols) {
    return 0.0;
  }
  return mat->data[r * mat->cols + c];
}

int hn_matrix_set(matrix_t *mat, int r, int c, double val) {
  if (!mat || r < 0 || r >= mat->rows || c < 0 || c >= mat->cols) {
    return -1;
  }
  mat->data[r * mat->cols + c] = val;
  return 0;
}

int hn_matrix_print(const matrix_t *mat) {
  if (!mat) {
    return -1;
  }
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->cols; j++) {
      printf("%f ", hn_matrix_get(mat, i, j));
    }
    printf("\n");
  }
  return 0;
}

int hn_matrix_fill(matrix_t *mat, double val) {
  if (!mat) {
    return -1;
  }
  for (int i = 0; i < mat->rows; i++) {
    for (int j = 0; j < mat->cols; j++) {
      hn_matrix_set(mat, i, j, val);
    }
  }
  return 0;
}

int hn_matrix_copy(const matrix_t *restrict src, matrix_t *restrict dest) {
  if (!src || !dest) {
    return -1;
  }
  if (src->rows != dest->rows || src->cols != dest->cols) {
    return -1;
  }
  memcpy(dest->data, src->data,
         (size_t)(src->rows * src->cols) * sizeof(double));
  return 0;
}

int hn_matrix_add(matrix_t *a1, matrix_t *a2, matrix_t *dest) {
  if (!a1 || !a2 || !dest) {
    return -1;
  }
  if (a1->rows != a2->rows || a1->cols != a2->cols) {
    return -1;
  }
  if (dest->rows != a1->rows || dest->cols != a1->cols) {
    return -1;
  }
  int total = a1->rows * a1->cols;
  for (int i = 0; i < total; i++) {
    dest->data[i] = a1->data[i] + a2->data[i];
  }
  return 0;
}

int hn_matrix_sub(matrix_t *a1, matrix_t *a2, matrix_t *dest) {
  if (!a1 || !a2 || !dest) {
    return -1;
  }
  if (a1->rows != a2->rows || a1->cols != a2->cols) {
    return -1;
  }
  if (dest->rows != a1->rows || dest->cols != a1->cols) {
    return -1;
  }
  int total = a1->rows * a1->cols;
  for (int i = 0; i < total; i++) {
    dest->data[i] = a1->data[i] - a2->data[i];
  }
  return 0;
}

int hn_matrix_transpose(const matrix_t *restrict src, matrix_t *restrict dest) {
  if (!src || !dest) {
    return -1;
  }
  if (dest->rows != src->cols || dest->cols != src->rows) {
    return -1;
  }
  for (int i = 0; i < src->rows; i++) {
    for (int j = 0; j < src->cols; j++) {
      dest->data[j * dest->cols + i] = src->data[i * src->cols + j];
    }
  }
  return 0;
}

int hn_matrix_multiply(const matrix_t *a1, const matrix_t *a2, matrix_t *dest) {
  if (!a1 || !a2 || !dest) {
    return -1;
  }
  if (a1->cols != a2->rows) {
    return -1;
  }
  if (dest->rows != a1->rows || dest->cols != a2->cols) {
    return -1;
  }

  int m = a1->rows;
  int n = a1->cols;
  int p = a2->cols;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < p; j++) {
      double sum = 0.0;
      for (int k = 0; k < n; k++) {
        sum += a1->data[i * n + k] * a2->data[k * p + j];
      }
      dest->data[i * p + j] = sum;
    }
  }
  return 0;
}

int hn_matrix_determinant(const matrix_t *mat, double *out_det) {
  if (!mat || !out_det) {
    return -1;
  }
  if (mat->rows != mat->cols) {
    return -1;
  }

  int n = mat->rows;
  if (n == 1) {
    *out_det = mat->data[0];
    return 0;
  }

  double det = 0.0;
  int sign = 1;

  for (int col = 0; col < n; col++) {
    matrix_t sub;
    sub.rows = n - 1;
    sub.cols = n - 1;
    sub.data = malloc((size_t)(n - 1) * (n - 1) * sizeof(double));

    int sub_i = 0;
    for (int i = 1; i < n; i++) {
      int sub_j = 0;
      for (int j = 0; j < n; j++) {
        if (j == col)
          continue;
        sub.data[sub_i * (n - 1) + sub_j] = mat->data[i * n + j];
        sub_j++;
      }
      sub_i++;
    }

    double sub_det;
    hn_matrix_determinant(&sub, &sub_det);
    det += sign * mat->data[col] * sub_det;
    sign = -sign;
    free(sub.data);
  }

  *out_det = det;
  return 0;
}
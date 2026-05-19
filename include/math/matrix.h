#pragma once

typedef struct {
  int rows;
  int cols;
  double *restrict data;
} matrix_t;

extern matrix_t *hn_matrix_create(int rows, int cols);
extern void hn_matrix_free(matrix_t *restrict mat);
extern double hn_matrix_get(const matrix_t *mat, int r, int c);
extern int hn_matrix_set(matrix_t *mat, int r, int c, double val);
extern int hn_matrix_print(const matrix_t *mat);
extern int hn_matrix_fill(matrix_t *mat, double val);
extern int hn_matrix_copy(const matrix_t *restrict src,
                          matrix_t *restrict dest);
extern int hn_matrix_add(matrix_t *a1, matrix_t *a2, matrix_t *dest);
extern int hn_matrix_sub(matrix_t *a1, matrix_t *a2, matrix_t *dest);
extern int hn_matrix_transpose(const matrix_t *restrict src,
                               matrix_t *restrict dest);
extern int hn_matrix_multiply(const matrix_t *a1, const matrix_t *a2,
                              matrix_t *dest);
extern int hn_matrix_determinant(const matrix_t *mat, double *out_det);
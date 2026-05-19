#include "../include/math/matrix.h"
#include <stdio.h>

int main() {
  matrix_t *m1 = hn_matrix_create(2, 2);
  hn_matrix_fill(m1, 2.0);
  printf("Matrix m1:\n");
  hn_matrix_print(m1);

  matrix_t *m_copy = hn_matrix_create(2, 2);
  hn_matrix_copy(m1, m_copy);
  printf("\nCopied matrix:\n");
  hn_matrix_print(m_copy);

  matrix_t *m2 = hn_matrix_create(2, 2);
  hn_matrix_fill(m2, 3.0);
  matrix_t *res = hn_matrix_create(2, 2);

  hn_matrix_add(m1, m2, res);
  printf("\nm1 + m2:\n");
  hn_matrix_print(res);

  hn_matrix_sub(m1, m2, res);
  printf("\nm1 - m2:\n");
  hn_matrix_print(res);

  matrix_t *m3 = hn_matrix_create(2, 3);
  hn_matrix_set(m3, 0, 0, 1);
  hn_matrix_set(m3, 0, 1, 2);
  hn_matrix_set(m3, 0, 2, 3);
  hn_matrix_set(m3, 1, 0, 4);
  hn_matrix_set(m3, 1, 1, 5);
  hn_matrix_set(m3, 1, 2, 6);
  printf("\nMatrix 2x3:\n");
  hn_matrix_print(m3);

  matrix_t *m_trans = hn_matrix_create(3, 2);
  hn_matrix_transpose(m3, m_trans);
  printf("\nTransposed matrix:\n");
  hn_matrix_print(m_trans);

  matrix_t *m4 = hn_matrix_create(2, 2);
  hn_matrix_set(m4, 0, 0, 1);
  hn_matrix_set(m4, 0, 1, 0);
  hn_matrix_set(m4, 1, 0, 0);
  hn_matrix_set(m4, 1, 1, 1);
  hn_matrix_multiply(m1, m4, res);
  printf("\nm1 * identity matrix:\n");
  hn_matrix_print(res);

  matrix_t *m_det = hn_matrix_create(2, 2);
  hn_matrix_set(m_det, 0, 0, 1);
  hn_matrix_set(m_det, 0, 1, 2);
  hn_matrix_set(m_det, 1, 0, 3);
  hn_matrix_set(m_det, 1, 1, 4);
  double det;
  hn_matrix_determinant(m_det, &det);
  printf("\nDeterminant: %.2f\n", det);

  hn_matrix_free(m1);
  hn_matrix_free(m2);
  hn_matrix_free(m3);
  hn_matrix_free(m4);
  hn_matrix_free(m_copy);
  hn_matrix_free(res);
  hn_matrix_free(m_trans);
  hn_matrix_free(m_det);

  printf("\nAll tests passed!\n");
  return 0;
}
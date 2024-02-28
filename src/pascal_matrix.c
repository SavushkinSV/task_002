#include "pascal_matrix.h"

int main() {
  int matrix_size = 0;
  if (scanf("%d", &matrix_size) == 1 && matrix_size > 0 && matrix_size <= 10) {
    int **matrix = calloc_matrix(matrix_size);
    int *values = calloc(matrix_size * matrix_size, sizeof(int));
    int lines = calc_pascal_lines(matrix_size);
    calc_pascal(values, lines, matrix_size * matrix_size);
    fill_matrix(matrix, values, matrix_size);
    output_matrix(matrix, matrix_size);
    free_matrix(matrix, matrix_size);
    exit(EXIT_SUCCESS);
  } else {
    exception();
  }
}

int **calloc_matrix(int n) {
  int **matrix = calloc(n, sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrix[i] = calloc(n, sizeof(int));
  }
  return matrix;
}

void free_matrix(int **matrix, int n) {
  for (int i = 0; i < n; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

int calc_pascal_lines(int n) {
  int sum = 1;
  while (sum < n * n) {
    sum += sum;
  }
  return sum;
}

void calc_pascal(int *result, int lines, int matrix_size) {
  int counter = 0;
  for (int i = 1; i < lines + 1; i++) {
    for (int j = 0; j < i; j++) {
      if (counter < matrix_size) {
        if (j == 0 || j == i - 1) {
          result[counter] = 1;
        } else {
          result[counter] = result[counter - i] + result[counter - i + 1];
        }
        counter++;
      } else {
        break;
      }
    }
  }
}

void fill_matrix(int **matrix, int *values, int matrix_size) {
  for (int i = 0; i < matrix_size; i++) {
    for (int j = 0; j < matrix_size; j++) {
      matrix[i][j] = values[(int)(j + matrix_size * i)];
    }
  }
}

void output_matrix(int **matrix, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == size - 1 && j == size - 1) {
        printf("%d", matrix[i][j]);
      } else if (i != size - 1 && j == size - 1) {
        printf("%d\n", matrix[i][j]);
      } else {
        printf("%d ", matrix[i][j]);
      }
    }
  }
}

void exception() {
  fprintf(stderr, "Puck you, Verter!");
  exit(EXIT_FAILURE);
}
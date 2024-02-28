#include "pascal_triangle.h"

int main() {
  int lines = 0;
  if (scanf("%d", &lines) == 1 && lines > 0 &&
      lines <= 30) {
    int size = calc_size(lines);
    int *triangle = calloc(size, sizeof(int));
    calc_pascal(lines, triangle);
    int *result = calloc(lines, sizeof(int));
    fill_result(triangle, result, lines, size);
    output_pascal(result, lines);
    free(triangle);
    free(result);
    exit(EXIT_SUCCESS);
  } else {
    exception();
  }
}

int calc_size(int lines) {
  int size = 0;
  for (int i = 1; i < lines + 1; i++) {
    size += i;
  }
  return size;
}

void calc_pascal(int lines, int *result) {
  int counter = 0;
  for (int i = 1; i < lines + 1; i++) {
    for (int j = 0; j < i; j++) {
      if (j == 0 || j == i - 1) {
        result[counter] = 1;
      } else {
        result[counter] = result[counter - i] + result[counter - i + 1];
      }
      counter++;
    }
  }
}

void clear(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = 0;
  }
}

void fill_result(int *triangle, int *result, int size, int triangle_size) {
  for (int i = 0; i < size; i++) {
    result[i] = triangle[triangle_size - size + i];
  }
}

void output_pascal(int *result, int size) {
  for (int i = 0; i < size; i++) {
    if (i < size - 1) {
      printf("%d ", result[i]);
    } else {
      printf("%d", result[i]);
    }
  }
}

void exception() {
  fprintf(stderr, "Puck you, Verter!");
  exit(EXIT_FAILURE);
}
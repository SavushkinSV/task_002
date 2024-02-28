#ifndef PASCAL_MATRIX_H
#define PASCAL_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int **calloc_matrix(int n);
void free_matrix(int **matrix, int n);
int calc_pascal_lines(int n);
void calc_pascal(int *result, int lines, int matrix_size);
void fill_matrix(int **matrix, int *values, int matrix_size);
void output_matrix(int **matrix, int size);
void exception();

#endif
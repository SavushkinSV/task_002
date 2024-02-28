#ifndef PASCAL_TRIANGLE_H
#define PASCAL_TRIANGLE_H

#include <stdio.h>
#include <stdlib.h>

int calc_size(int lines);
void clear(int *arr, int size);
void calc_pascal(int lines, int *result);
void fill_result(int *triangle, int *result, int size, int triangle_size);
void exception();
void output_pascal(int *result, int size);

#endif
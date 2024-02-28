#include "pascal.h"

#include <stdio.h>
#include <stdlib.h>

/* Функция возвращает указатель на матрицу заданного размера */
int **getMatrix(int row, int col) {
    int **array_pointer = malloc(row * sizeof(int *));
    int *value_pointer = malloc(row * col * sizeof(int));
    for (int i = 0; i < row; i++) {
        array_pointer[i] = value_pointer + col * i;
    }

    return array_pointer;
}

/* Функция заполняет матрицу числами треугольника Паскаля */
void inputMatrixPascal(int **matrix, int row) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
        }
    }
}

/* Функция выводит матрицу в stdout */
void outputMatrix(int **matrix, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j != col - 1)
                printf("%d ", matrix[i][j]);
            else
                printf("%d", matrix[i][j]);
        }
        if (i != row - 1) printf("\n");
    }
}

/* Функция выводит заданную строку матрицы в stdout */
void outputRowMatrix(int **matrix, int row) {
    for (int j = 0; j < row; j++) {
        if (j != row - 1)
            printf("%d ", matrix[row - 1][j]);
        else
            printf("%d", matrix[row - 1][j]);
    }
}

/* Функция освобождает выделенную память */
void freeMatrix(int **matrix) {
    free(matrix[0]);
    free(matrix);
}

/* Функция возвращает следующий элемент треугольника Паскаля */
int getNextElementPascal(int **matrix) {
    static unsigned int n = 0;
    static unsigned int k = 0;
    if (k > n) {
        n++;
        k = 0;
    }
    int element = matrix[n][k];
    k++;
    return element;
}

/* Функция заполняет матрицу последовательно элементами треугольника Паскаля */
void inputMatrixResult(int **matrixPascal, int row, int col, int **matrixResult) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrixResult[i][j] = getNextElementPascal(matrixPascal);
        }
    }
}
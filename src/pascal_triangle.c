#include <stdio.h>
#include <stdlib.h>

int **getMatrix(int row, int col);
void inputMatrixPascal(int **matrix, int row);
void outputRowMatrix(int **matrix, int row);
void freeMatrix(int **matrix);

int main() {
    int n = 0;
    int **matrix = NULL;

    if (scanf("%d", &n) == 1 && n > 0) {
        matrix = getMatrix(n, n);
        inputMatrixPascal(matrix, n);
        outputRowMatrix(matrix, n);
        freeMatrix(matrix);
    } else {
        fprintf(stderr, "Puck you, Verter!");
        exit(-1);
    }

    return 0;
}

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
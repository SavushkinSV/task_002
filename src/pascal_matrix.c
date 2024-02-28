#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 30

int **getMatrix(int row, int col);
void inputMatrixPascal(int **matrix, int row);
void outputMatrix(int **matrix, int row, int col);
void freeMatrix(int **matrix);

int getNextElementPascal(int **matrix);
void inputMatrixResult(int **matrixPascal, int row, int col, int **matrixResult) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrixResult[i][j] = getNextElementPascal(matrixPascal);
        }
    }
}

int main() {
    int error = 0;
    int n = 0;
    int **matrixResult = NULL;
    int **matrixPascal = NULL;

    if (scanf("%d", &n) == 1 && n > 0) {
        matrixPascal = getMatrix(MAX_SIZE, MAX_SIZE);
        matrixResult = getMatrix(n, n);
        inputMatrixPascal(matrixPascal, MAX_SIZE);
        inputMatrixResult(matrixPascal, n, n, matrixResult);

        outputMatrix(matrixResult, n, n);
        freeMatrix(matrixResult);
        freeMatrix(matrixPascal);
    } else {
        fprintf(stderr, "Puck you, Verter!");
        error--;
    }

    return error;
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
#ifndef PASCAL_H
#define PASCAL_H

#define MAX_SIZE 30

int **getMatrix(int row, int col);
void inputMatrixPascal(int **matrix, int row);
void outputMatrix(int **matrix, int row, int col);
void freeMatrix(int **matrix);
int getNextElementPascal(int **matrix);
void inputMatrixResult(int **matrixPascal, int row, int col, int **matrixResult);
void outputRowMatrix(int **matrix, int row);

#endif  // PASCAL_H

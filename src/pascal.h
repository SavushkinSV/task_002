#ifndef PASCAL_H
#define PASCAL_H

#define MAX_SIZE 30
#define MAX_SIZE_RESULT 10

int **getMatrix(int row, int col);
void inputMatrixPascal(int **matrix, int row);
void outputMatrix(int **matrix, int row, int col);
void outputRowMatrix(int **matrix, int row);
void freeMatrix(int **matrix);
int getNextElementPascal(int **matrix);
void inputMatrixResult(int **matrixPascal, int row, int col, int **matrixResult);

int getSizeArray(int row);
void printBasePascal(int row);

#endif  // PASCAL_H

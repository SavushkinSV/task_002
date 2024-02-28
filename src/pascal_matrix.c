#include <stdio.h>
#include <stdlib.h>

#include "pascal.h"

int main() {
    int n = 0;
    int **matrixResult = NULL;
    int **matrixPascal = NULL;

    if (scanf("%d", &n) == 1 && (n > 0 && n <= MAX_SIZE_RESULT)) {
        matrixPascal = getMatrix(MAX_SIZE, MAX_SIZE);
        matrixResult = getMatrix(n, n);
        inputMatrixPascal(matrixPascal, MAX_SIZE);
        inputMatrixResult(matrixPascal, n, n, matrixResult);
        outputMatrix(matrixResult, n, n);
        freeMatrix(matrixResult);
        freeMatrix(matrixPascal);
    } else {
        fprintf(stderr, "Puck you, Verter!");
        exit(-1);
    }

    return 0;
}
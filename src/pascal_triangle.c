#include <stdio.h>
#include <stdlib.h>

#include "pascal.h"

int main() {
    int n = 0;
    int **matrix = NULL;

    if (scanf("%d", &n) == 1 && (n > 0 && n <= MAX_SIZE)) {
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
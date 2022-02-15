#include "matrix.h"
#include <malloc.h>
#include <stdio.h>

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++) {
        values[i] = (int *) malloc(sizeof(int) * nCols);
    }
    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++) {
        ms[i] = getMemMatrix(nRows, nCols);
    }
    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        free(m.values[i]);
    }
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(ms[i]);
    }
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            scanf("%d", &m.values[i][j]);
        }
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            printf("%d ", m.values[i][j]);
        }
        printf("\n");
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    int *t = m.values[i1];
    m.values[i1] = m.values[i2];
    m.values[i2] = t;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(int*, int)) {
    int *critArray = (int*) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        critArray[i] = criteria(m.values[i], m.nCols);
    }

    for (int i = 0; i < m.nRows; i++) {
        for (int j = i; i > 0 && critArray[j - 1] > critArray[j]; j--) {
            swap(&critArray[j - 1], &critArray[j]);
            swapRows(m, j - 1, j);
        }
    }

    free(critArray);
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(int*, int)) {
    int *critArray = (int*) malloc(sizeof(int) * m.nCols);
    int *addArray = (int*) malloc(sizeof(int) * m.nRows);

    for (int i = 0; i < m.nCols; i++) {
        for (int j = 0; j < m.nRows; j++) {
            addArray[j] = m.values[j][i];
        }
        critArray[i] = criteria(addArray, m.nRows);
    }

    for (int i = 0; i < m.nCols; i++) {
        for (int j = i; j > 0 && critArray[j - 1] > critArray[j]; j--) {
            swap(&critArray[j - 1], &critArray[j]);
            swapColumns(m, j - 1, j);
        }
    }

    free(critArray);
    free(addArray);
}
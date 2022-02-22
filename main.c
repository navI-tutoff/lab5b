#include "libs\data_structures\matrix\matrix.h"
//#include "libs\data_structures\matrix\matrixTests.c"
#include <assert.h>

///                                                                                  First Task

void task1(matrix m) {
    swapRows(m, getMinValuePos(m).rowIndex, getMaxValuePos(m).rowIndex);
}

void test_task1_minAndMaxInTheDifferentRows() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 8,
                    5, 4, 6,
                    7, 0, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    7, 0, 3,
                    5, 4, 6,
                    1, 2, 8,
            },
            3, 3
    );

    task1(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task1_minAndMaxInTheSameRows() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    5, 4, 6,
                    7, 2, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 0, 8,
                    5, 4, 6,
                    7, 2, 3,
            },
            3, 3
    );

    task1(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task1() {
    test_task1_minAndMaxInTheDifferentRows();
    test_task1_minAndMaxInTheSameRows();
}

///                                                                                 Second Task

int getMax(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
        }
    }

    return max;
}

void task2(matrix m) {
    selectionSortRowsMatrixByRowCriteria(m, getMax);
}

void test_task2_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    7, 1, 2,
                    1, 8, 1,
                    3, 2, 3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 3,
                    7, 1, 2,
                    1, 8, 1,
            },
            3, 3
    );

    task2(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task2_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 4, 0,
                    9, 8, 7,
                    3, 2, 2,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 2,
                    1, 4, 0,
                    9, 8, 7,
            },
            3, 3
    );

    task2(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task2() {
    test_task2_1();
    test_task2_2();
}

///                                                                                  Third Task

int getMin(int *a, int n) {
    int min = a[0];
    for (int i = 0; i < n; i++) {
        if (min > a[i]) {
            min = a[i];
        }
    }

    return min;
}

void task3(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

void test_task3_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 5, 2, 4, 3, 3,
                    2, 5, 1, 8, 2, 7,
                    6, 1, 4, 4, 8, 3,
            },
            3, 6
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    5, 2, 3, 3, 3, 4,
                    5, 1, 2, 2, 7, 8,
                    1, 4, 6, 8, 3, 4,
            },
            3, 6
    );

    task3(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task3_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
            },
            3, 4
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
            },
            3, 4
    );

    task3(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task3() {
    test_task3_1();
    test_task3_2();
}

///                                                                                 Fourth Task

void task4(matrix *m) {
    if (isSquareMatrix(*m)) {
        *m = mulMatrices(*m, *m);
    }
}

void test_task4_isSquareMatrix() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    7, 10,
                    15, 22,
            },
            2, 2
    );

    task4(&initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task4_aintSquareMatrix() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
            },
            2, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2, 5,
                    3, 4, 6,
            },
            2, 3
    );

    task4(&initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task4() {
    test_task4_isSquareMatrix();
    test_task4_aintSquareMatrix();
}

///                                                                                  Fifth Task

bool isUnique(long long *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                return 0;
            }
        }
    }
    return 1;
}

long long getSum(int *a, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }

    return sum;
}

void task5(matrix m) {
    long long rowsSum[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        rowsSum[i] = getSum(m.values[i], m.nCols);
    }

    if (isUnique(rowsSum, m.nRows)) {
        transposeSquareMatrix(m);
    }
}

void test_task5_equalSum() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 0,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 0,
            },
            2, 2
    );

    task5(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task5_differentSum() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 1,
            },
            2, 2
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, 3,
                    2, 1,
            },
            2, 2
    );

    task5(initialMatrix);

    assert(areTwoMatricesEqual(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task5() {
    test_task5_equalSum();
    test_task5_differentSum();
}

///                                                                                  Sixth Task

bool task6(matrix m1, matrix m2) {
    matrix multiplication = mulMatrices(m1, m2);
    bool isInverse = isEMatrix(multiplication);

    return isInverse;
}

void test_task6_isInverse() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    1, -1, 1,
                    -38, 41, -34,
                    27, -29, 24,
            },
            3, 3
    );

    task6(initialMatrix, expectedMatrix);

    assert(task6(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task6_isntInverse() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    2, 5, 7,
                    6, 3, 4,
                    5, -2, -3,
            },
            3, 3
    );

    matrix expectedMatrix = createMatrixFromArray(
            (int[]) {
                    4,  1, 1,
                    -38, 71, -34,
                    27, -29, 14,
            },
            3, 3
    );

    task6(initialMatrix, expectedMatrix);

    assert(!task6(initialMatrix, expectedMatrix));

    freeMemMatrix(initialMatrix);
    freeMemMatrix(expectedMatrix);
}

void test_task6() {
    test_task6_isInverse();
    test_task6_isntInverse();
}

///                                                                                Seventh Task

int max2(int a, int b) {
    return a > b ? a : b;
}

#include <limits.h>

long long task7(matrix m) {
    int arrSize = m.nRows + m.nCols - 1;
    int elemOfPseudoDiagonal[m.nRows + m.nCols - 1];

    for (int i = 0; i < arrSize; i++) {
        elemOfPseudoDiagonal[i] = INT_MIN;
    }

    elemOfPseudoDiagonal[m.nRows - 1] = 0; /// middle

    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (i != j) {
                int k = j - i + m.nRows - 1;
                elemOfPseudoDiagonal[k] = max2(elemOfPseudoDiagonal[k], m.values[i][j]);
            }
        }
    }

    return getSum(elemOfPseudoDiagonal, arrSize);
}

void test_task7_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2,
            },
            3, 4
    );

    assert(task7(initialMatrix) == 20);

    freeMemMatrix(initialMatrix);
}

void test_task7() {
    test_task7_1();
}

///                                                                                 Eighth Task

int min2(int a, int b) {
    return a < b ? a : b;
}

int task8(matrix m) {
    position pos = getMaxValuePos(m);
    int elem = m.values[pos.rowIndex][pos.colIndex];

    int right = pos.colIndex;
    int left = pos.colIndex;
    for (int i = pos.rowIndex - 1; i >= 0; i--) {
        left = left > 0 ? left - 1 : left;
        right = right < m.nCols ? right + 1 : right;

        elem = min2(getMin(&m.values[i][left], right - left), elem);
    }

    return elem;
}

void test_task8_1() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,
            },
            3, 4
    );

    assert(task8(initialMatrix) == 5);

    freeMemMatrix(initialMatrix);
}

void test_task8_2() {
    matrix initialMatrix = createMatrixFromArray(
            (int[]) {
                    6, 8, 9, 2,
                    7, 12, 3, 4,
                    10, 11, 5, 1,
            },
            3, 4
    );

    assert(task8(initialMatrix) == 6);

    freeMemMatrix(initialMatrix);
}

void test_task8() {
    test_task8_1();
    test_task8_2();
}

void tasks_tests() {
    test_task1();
    test_task2();
    test_task3();
    test_task4();
    test_task5();
    test_task6();
    test_task7();
    test_task8();
}

int main() {
    tasks_tests();

    return 0;
}
#ifndef MYMAIN_MATRIX_H
#define MYMAIN_MATRIX_H

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows;    // количество рядов
    int nCols;    // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// размещает в динамической памяти матрицу размером nRows на nCols, возвращает матрицу
matrix getMemMatrix(int nRows, int nCols);

// размещает в динамической памяти массив из nMatrices матриц
// размером nRows на nCols. Возвращает указатель на нулевую матрицу
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// освобождает память, выделенную под хранение матрицы m
void freeMemMatrix(matrix m);

// освобождает память, выделенную под хранение массива ms из nMatrices матриц
void freeMemMatrices(matrix *ms, int nMatrices);

// сохраняет значения, введённые пользователем с клавиатуры, в матрицу m
void inputMatrix(matrix m);

// сохраняет значения nMatrices матриц, введённые пользователем с клавиатуры, в массив,
// хранящийся по адресу ms
void inputMatrices(matrix *ms, int nMatrices);

// выводит матрицу m
void outputMatrix(matrix m);

// выводит массив из nMatrices матриц, хранящийся по адресу ms
void outputMatrices(matrix *ms, int nMatrices);



#endif //MYMAIN_MATRIX_H
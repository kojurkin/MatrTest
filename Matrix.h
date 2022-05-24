#ifndef MATRTEST_MATRIX_H
#define MATRTEST_MATRIX_H

class Matrix {
private:
    int **matrix;
    int rows;
    int columns;

public:
    Matrix(int rows, int columns);

    ~Matrix();

    void setElement(int i, int j, int element);

    int getElement(int i, int j);

    void print();

private:
    friend void selectionSort(Matrix &m);
    friend void swap(Matrix &m, int first, int second);
};


#endif //MATRTEST_MATRIX_H

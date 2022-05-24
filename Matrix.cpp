#include "Matrix.h"
#include <iostream>

void Matrix::setElement(int i, int j, int element)
{
    matrix[i][j] = element;
}
Matrix::Matrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
    }
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}



int Matrix::getElement(int i, int j)
{
    return matrix[i][j];
}

void Matrix::print()
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int compare(Matrix& m, int first, int second, int size)
{
    for (int i = 0; i < size; i++)
    {
        int dif = m.getElement(first, i) - m.getElement(second, i);
        if (dif != 0)
            return dif;
    }
    return 0;
}

void swap(Matrix& m, int first, int second)
{
    int *tmp = m.matrix[first];
    m.matrix[first] = m.matrix[second];
    m.matrix[second] = tmp;
}

void selectionSort(Matrix& m)
{
    int size = m.rows;
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (compare(m, j, min_index, m.columns) < 0)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            swap(m, i, min_index);
        }
    }
}
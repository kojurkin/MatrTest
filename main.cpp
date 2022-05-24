#include <iostream>
#include <fstream>
#include "Matrix.h"

int main()
{
    std::ifstream fin;
    fin.open("in.txt");

    int rows, cols;
    int element;

    fin >> rows >> cols;
    Matrix matrix(rows, cols);

    if (!fin.is_open())
    {
        return -1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin >> element;
            matrix.setElement(i, j, element);
        }
    }

    std::cout << "Source matrix:" << std::endl;
    matrix.print();
    std::cout << std::endl;

    selectionSort(matrix);
    std::cout << "Sorted matrix:" << std::endl;
    matrix.print();
    fin.close();
    return 0;
}
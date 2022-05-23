#include <iostream>
#include <fstream>
#include <cmath>

class Matrix
{
private:
    int **matr;
    int n;
    int m;

public:
    Matrix(int rows, int cols)
    {
        if (rows > 0 && cols > 0)
        {
            n = rows;
            m = cols;
            matr = new int *[n];
            for (int i = 0; i < n; i++)
            {
                matr[i] = new int[m];
            }
        }
        else
        {
            fail(1);
        }
    }

    ~Matrix()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matr[i];
        }

        delete[] matr;
    }

    void SetElt(int i, int j, int elt)
    {
        matr[i][j] = elt;
    }

    int GetElt(int i, int j)
    {
        return matr[i][j];
    }

    void Print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                std::cout << matr[i][j] << "\t";
            }
            std::cout << std::endl;
        }
    }

private:
    void fail(int code)
    {
        switch (code)
        {
            case 1:
                std::cout << "Class Error" << std::endl;
                break;
        }
        exit(1);
    }

    friend void InsertionSortBinary(Matrix& M, int *arr, int n, int m);
};

int main()
{
    setlocale(LC_ALL, "Rus");
    std::ifstream fin;
    fin.open("in.txt");

    int rows, cols;
    int elt;
    int *arr = new int[rows];
    int sum;

    fin >> rows >> cols;
    Matrix Mt(rows, cols);

    if (!fin.is_open())
    {
        return -1;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            fin >> elt;
            Mt.SetElt(i, j, elt);
        }
    }

    std::cout << "Исходная матрица:" << std::endl;
    Mt.Print();
    std::cout << std::endl;

    for (int i = 0; i < rows; i++)
    {
        sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += abs(Mt.GetElt(i, j));
        }
        arr[i] = sum;
    }

    InsertionSortBinary(Mt, arr, rows, cols);
    std::cout << "Итоговая матрица:" << std::endl;
    Mt.Print();
    delete[] arr;
    fin.close();
    return 0;
}

void InsertionSortBinary(Matrix& M, int *arr, int n, int m)
{
    int left;
    int right;
    int mid;
    int current; // текущий элемент
    int *row; // текущая строка

    for (int i = 0; i < n; i++)
    {
        row = M.matr[i]; // запоминаем указатель на строку
        current = arr[i]; // запоминаем сумму строки
        left = 0;
        right = i;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (arr[mid] <= current)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        for (int j = i; j > left; j--) // сдвиг строк влево
        {
            arr[j] = arr[j - 1];
            M.matr[j] = M.matr[j - 1];// сдвиг строк через указатели на строки
        }
        arr[left] = current; // вставляем сумму
        M.matr[left] = row; // вставляем строку через указатель на строку
    }
}
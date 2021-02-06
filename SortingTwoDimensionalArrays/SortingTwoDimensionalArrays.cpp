/*Написать шаблонную функцию Sort для сортировки двумерных массивов.*/
#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 10;

void FillRand(double arr[ROWS][COLS], const int m, const int n);
template <typename T> void Print(T arr[ROWS][COLS], const int m, const int n);
template <typename T> void Sort(T arr[ROWS][COLS], const int m, const int n);

void main()
{
    setlocale(LC_ALL, "");
    
    /*Сортировка двумерноо массива на примере double*/
    double double_arr_2[ROWS][COLS];
    FillRand(double_arr_2, ROWS, COLS);
    Print(double_arr_2, ROWS, COLS);
    Sort(double_arr_2, ROWS, COLS);
    Print(double_arr_2, ROWS, COLS);
    cout << endl;
 
}

void FillRand(double arr[ROWS][COLS], const int m, const int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 50;
            arr[i][j] /= 10;
        }
    }
}

template <typename T> void Print(T arr[ROWS][COLS], const int m, const int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T> void Sort(T arr[ROWS][COLS], const int m, const int n)
{
    for (int c = 0; c <= (m * n); c++)
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < (n - 1); j++)
            {
                if (arr[i][j] > arr[i][j + 1])
                {
                    T buffer = arr[i][j];
                    arr[i][j] = arr[i][j + 1];
                    arr[i][j + 1] = buffer;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (m - 1); j++)
            {
                if (arr[j][i] > arr[j][i + 1])
                {
                    T buffer = arr[j][i];
                    arr[j][i] = arr[j][i + 1];
                    arr[j][i + 1] = buffer;
                }
            }
        }
    }

}
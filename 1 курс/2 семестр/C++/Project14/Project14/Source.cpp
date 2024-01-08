#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>
#define N1 10
#define N2 6

using namespace std;

void f1(int** mass, int a, int b, int jojo[], int M1) // функция которая ищет количество отрицательных чисел в четных столбцах
{
    cout << endl;
    int i, j, k;
    int z = 0;

    for (j = 1; j < b; j += 2)
    {
        k = 0;
        for (i = 0; i < a; i++)
        {

            if (*(*(mass + i) + j) < 0)
            {
                k = k + 1;
            }

        }

        jojo[z] = k;
        z++;
        cout << "Количество отрицательных чисел в " << z << " четном столбце = " << k << endl;

    }
    cout << endl;
    cout << "[ ";
    for (z = 0; z < M1; z++)
        cout << jojo[z] << " ";

    cout << "]";
    cout << " Массив обозначающий количество отрицательных чисел в четных столбцах " << endl;
}

int main()
{
    int i, j, k;
    int M1 = N2 / 2;
    setlocale(0, "Russian");
    srand(time(0));

    int** mass = new int* [N1]; // выделение памяти под динамический массив
    for (i = 0; i < N1; i++)
        mass[i] = new int[N2];

    int* ans1 = new int[M1];

    cout << " Массив чисел " << endl;

    for (i = 0; i < N1; i++) // заполнение и вывод массива
    {
        cout << endl;
        for (j = 0; j < N2; j++)
        {
            mass[i][j] = rand() % 101 - 50;
            cout.width(4);
            cout << mass[i][j] << " ";
        }

    }
    cout << endl;

    f1(mass, N1, N2, ans1, M1);
    delete[] mass;
    system("pause");
    return 0;
}
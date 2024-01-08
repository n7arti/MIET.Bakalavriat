#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>

using namespace std;

void f1(double** mass, int N1, int N2, double& z, double& x)
{
    int i, j;
    double a = N1;
    double min = INT_MAX;
    double max = INT_MIN;
    for (j = 0; j < N2 / 2 + N2 % 2; j++)//левая
    {
        cout << endl;
        for (i = j; i < a; i++)
        {
            cout.width(4);
            cout << mass[i][j] << " ";
            if (mass[i][j] < min)
                min = mass[i][j];
        }
        a--;
        z = min;

    }
    cout << " Минимальное число левой части = " << z << endl;

    cout << endl;
    cout << a << endl;
    int b;
    b = N2 / 2 + N2 % 2 - 1;
    a++;

    for (j = N2 / 2 + N2 % 2 - 1; j < N2; j++)//правая
    {
        cout << endl;
        for (i = b; i < a; i++)
        {
            cout.width(4);
            cout << mass[i][j] << " ";
            if (mass[i][j] > max)
                max = mass[i][j];
        }
        a++;
        b--;
        x = max;

    }
    cout << " Максимальное число правой части = " << x << endl;
}

int main()
{
    double z = 0;
    double x = 0;

    setlocale(0, "Russian");
    srand(time(0));

    int N1, N2;
    cout << "Выведете количество строк" << endl;
    cin >> N1;

    cout << "Выведете количество столбцов" << endl;
    cin >> N2;

    int i, j, k;

    double** mass = new double* [N1]; // выделение памяти под динамический массив
    for (i = 0; i < N1; i++)
        mass[i] = new double[N2];



    cout << " Массив чисел " << endl;

    for (i = 0; i < N1; i++) // заполнение и вывод массива
    {
        cout << endl;
        for (j = 0; j < N2; j++)
        {
            mass[i][j] = rand() % 51 - 25;
            cout.width(4);
            cout << mass[i][j] << " ";
        }

    }
    cout << endl << endl;

    f1(mass, N1, N2, z, x);

    cout << endl;
    delete[] mass;
    system("pause");
    return 0;
}
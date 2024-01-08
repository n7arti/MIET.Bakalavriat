
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
using namespace std;
#define N 10

int f1(int **mass, int k) // вычисление максимального числа строки в матрице разделенной главной диагональю (по модулю)
{
    int max = INT_MIN;
    for (int i = 0; i < k; i++)
    {
        max = INT_MIN;
        for (int j = i; j < k; j++)
        {
            if (max < abs(mass[i][j]))
            {
                max = abs(mass[i][j]);
                
            }
            
            
        }
        cout << "Максимальное число по модулю " << i + 1 << " строки " << max << " ";
        cout << endl;
        
      

    }
    return max;
}
int main()
{   
    setlocale(0, "Russian");
    srand(time(0));

    int size; // выдиление памяти под двумерный динамический массив
    size = N;
    int **mass = new int* [size];
    for (int i = 0; i < size; i++)
        mass[i] = new int[size];;


    for (int i = 0; i < N; i++) // заполняю массив
        for (int j = 0; j < N; j++)
            mass[i][j] = rand() % 101 - 50;

    for (int i = 0; i < N; i++) // вывод массива на экран
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << mass[i][j] << " ";
    }
    cout << endl;


    f1(mass,N);
    system("pause");
    return 0;
}
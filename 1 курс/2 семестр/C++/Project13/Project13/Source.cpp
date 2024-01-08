
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
using namespace std;
#define N1 5
#define N2 10

int f1(int mass[], int size) // функция вычисляет положение последнего положительного элемента
{
	int k = 0;
	for (int i = 0; i < size; i++)
		if (mass[i] > 0)
			k = i+1;
	if (k == 0)
		cout << "Положительных чисел нет" << endl;
	return k;
}

int f2(int mass[], int k) // функция вычисляет минимальный элемент части массива
{
	
	int min = INT_MAX;
	for (int i = 0; i < k; i++)
		if (mass[i] < min)
			min = mass[i];
	if (min == INT_MAX)
	{
		cout << " Массив не был разделен." << endl;
		min = 0;
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	srand(time(NULL));
	int A[N1], B[N2];
	int z1, z2;
	int min1, min2;
	//заполнение массивов
	for (int i = 0; i < N1; i++)
		A[i] = rand() % 101 - 50;

	for (int i = 0; i < N2; i++)
		B[i] = rand() % 101 - 50;
	// Вывод массивов на экран
	for (int i = 0; i < N1; i++)
		cout << A[i]<<" ";
	cout << endl;
	for (int i = 0; i < N2; i++)
		cout << B[i] << " ";
	cout << endl;
	

	z1 = f1(A, N1);
	cout << "Положение последнего положительного элемента в массиве А равно " << z1 << endl;
	min1 = f2(A, z1);
	cout << "Минимальное число в первой части массива А равно " << min1 << endl;

	z2 = f1(B, N2);
	cout << "Положение последнего положительного элемента в массиве B равно " << z2 << endl;

	min2 = f2(B, z2);
	cout << "Минимальное число в первой части массива B равно " << min2 << endl;

	system("pause");
	return 0;
}


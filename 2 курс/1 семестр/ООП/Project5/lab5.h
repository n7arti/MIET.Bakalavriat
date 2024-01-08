#pragma once
#include <iostream>
#include <locale>
#include "time.h"
using namespace std;
template<class Mas>
Mas* init(Mas* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101 - 50;
		cout << arr[i] << "  ";
	}
	cout << endl;
	return arr;
}

template<class Mas>
int min(Mas* arr, int size)
{
	Mas min = arr[0];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			k = i;
		}
	}
	cout << "Минимальное значение: " << min << endl;
	return k;
}

template<class Mas>
int max(Mas* arr, int size)
{
	Mas max = arr[0];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			k = i;
		}
	}
	cout << "Максимальное значение: " << max << endl;
	return k;
}
template<class Mas>
void sum(int k1, int k2, Mas* arr)
{
	Mas sum = 0;
	if (k2 > k1)
		for (int i = k1; i < k2 + 1; i++)
			sum += arr[i];
	else if (k2 < k1)
		for (int i = k2; i < k1 + 1; i++)
			sum += arr[i];
	else sum = arr[k1];
	cout << "Cумма элементов между минимальным и максимальным равна: " << sum << endl;
}

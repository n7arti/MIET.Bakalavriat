#include <stdio.h> 
#include <stdlib.h>
#include <clocale>
#include <iostream>
#include <iomanip>
#include <time.h>

const int N = 10;

int main()
{
	setlocale(LC_ALL, "Russian");
	int X[N];
	int max = 0;
	int min = INT_MAX;
	int n, m;
	for (int i = 0; i < N; i++)
	{
		X[i] = rand();
		if (X[i] > max)
		{
			max = X[i];
			n = i;
		}
		if (X[i] < min)
		{
			min = X[i];
			m = i;
		}
	}
	printf("Максимальное значение массива:%d\n", max);
	printf("Минимальное значение массива:%d\n", min);
	if (n > m)
	{
		for (int i = m + 1; i < n; ++i)
		{
			for (int j = m+1; j < n - i; j++)
			{
				if (X[j] < X[j + 1])
				{
					int t = X[j];
					X[j] = X[j + 1];
					X[j + 1] = t;
				}
			}

		}
	}
	else if (m > n)
	{
		for (int i = n + 1; i < m; ++i)
		{
			for (int j = n+1; j < m - i; j++)
			{
				if (X[j] < X[j + 1])
				{
					int t = X[j];
					X[j] = X[j + 1];
					X[j + 1] = t;
				}
			}

		}
	}
	printf("Видоизмененный массив:\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", X[i]);
	}
	system("pause");
	return 0;

}
#include <stdio.h> 
#include <stdlib.h>
#include <clocale>
#include <iostream>
#include <iomanip>
#include <time.h>
const int N = 8;
const int M = 8;
const int L = 4;
int main()
{
	setlocale(LC_ALL, "Russian");
	int X[N][M];
	int Y[L];
	int k=0;
	int max;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			X[i][j] = rand() % 2000 - 1000;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = M; j >= N - i; j--)
		{
			if ((X[i][j] > 0) && (X[i][j]%2 == 0))
				k++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		printf("%d\n", X[i][j]);
	}
	max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < M; j++)
			{
				if (X[i][j] > max)
					max = X[i][j];
			}
			Y[i / 2] = max;
		}
		
	}
	printf("Количество четных положительных элементов в заштрихованной области:%d\n", k);
	printf("Максимальные значения четных строк:\n");
	for (int i = 0; i < L; i++)
		printf("%d\n", Y[L]);
	system("pause");
	return 0;

}
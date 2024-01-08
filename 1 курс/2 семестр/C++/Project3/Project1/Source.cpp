#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
using namespace std;
const int N1 = 10;
const int N2 = 8;
int mas(float C[], int size)
{
	int k=0;
	float min = INT_MAX;
	for (int i = 0; i < size; i++)
	{
		if (C[i] <= min) //ищем наименьшего элемента
		{
			min = C[i];
			k = i;
		}

	}
	return k;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	float A[N1];
	float B[N2];
	srand(time(NULL));
	for (int i = 0; i < N1; i++) //задаем массивы
	{
		A[i] = rand()%2001-1000 + (float)rand()/RAND_MAX;
	}
	for (int i = 0; i < N2; i++)
	{
		B[i] = rand() % 2001 - 1000 + (float)rand() / RAND_MAX;
	}
	for (int i = 0; i < N1; i++) //выводим их
	{
		printf("%4.2lf ", A[i]);
	}
	printf("\n");
	for (int i = 0; i < N2; i++)
	{
		printf("%4.2lf ", B[i]);
	}
	printf("\n");
	int k1 = mas(A, N1);
	int k2 = mas(B, N2);
	if ((N2-k2)<(N1-k1))//сравниваем кол-во индексов от наименьших элементов до конца
	{ 
		printf("В массиве В минимум находится ближе к концу массива\n");
	}
	else if ((N2 - k2) > (N1 - k1))
	{
		printf("В массиве A минимум находится ближе к концу массива\n");

	}
	else if ((N2 - k2) == (N1 - k1))
	{
		printf("В массивах A и В минимумы равноудалены от конца\n");
	}
	system("pause");
	return 0;

}
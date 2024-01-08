#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
const int N = 10;
int sums(int mas[N][N],int k)
{
	int sum = 0;
	//выбираем элементы заштрихованной области и считаем сумму в столбце
	for (int i = k; i < N; i++)
		sum += mas[i][k];
	return sum;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int A[N][N];
	srand(time(NULL));
	for (int i = 0; i < N; i++) //задаем массив
	{
		for (int j = 0; j < N; j++)
			A[i][j] = rand() % 10;
	}
	for (int i = 0; i < N; i++) //выводим массив
	{
		printf("\n");
		for (int j = 0; j < N; j++)
			printf("%d ", A[i][j]);
	}
	printf("\n");
	for (int i = 0; i < N; i++) //выводим сумму элементов каждого столбца заштрихованной области
	{
		int res = sums(A, i);
		printf("Сумма элементов %d", i);
		printf("-ого стоблца равна %d\n", res);
	}
	system("pause");
	return 0;

}
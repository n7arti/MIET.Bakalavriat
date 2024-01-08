#include <iostream>
#include <time.h>
using namespace std;
void Shaker_sort(int* mas, int size)
{
	int left = 1;
	int right = size - 1;
	while (left <= right)
	{
		for (int i = left; i <= right; i++)
			if (mas[i - 1] > mas[i]) swap(mas[i - 1], mas[i]);
		left++;

		for (int i = right; i >= left; i--)
			if (mas[i - 1] > mas[i]) swap(mas[i - 1], mas[i]);
	}	right++;
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N = 0;
	cout << "Введите размер массива: ";
	cin >> N;
	int* Array = new int[N];
	cout << "Массив до сортировки: "<<endl;
	for (int i = 0; i < N; i++)
	{
		Array[i] = rand() % 1000 - 500;
		cout << Array[i] << " | ";
	}
	cout << endl;
	Shaker_sort(Array, N);
	cout << "Массив после сортировки: " << endl;
	for (int i = 0; i < N; i++)
		cout << Array[i] << " | ";
	return 0;
}
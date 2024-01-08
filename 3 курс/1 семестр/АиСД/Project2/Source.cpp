#include <iostream>
#include <time.h>
using namespace std;
void Shaker_sort(int* mas, int size)
{
	int left = 1;
	int right = size - 1;
	while (left <= right)
	{
		for (int i = right; i >= left; i--)
			if (mas[i - 1] > mas[i]) 
				swap(mas[i - 1], mas[i]);
		left++;

		for (int i = left; i <= right; i++)
			if (mas[i - 1] > mas[i]) 
				swap(mas[i - 1], mas[i]);
		right++;
	}
}
void Fibonachchi_find(int* mas, int start, int size, int poisk)
{
	int count1 = 0, count2 = 1, left = 0, right = 0;
	while (start+count1 <size)
	{
		if (mas[start + count1] < poisk)
		{
			left = start + count1;
			cout << "left" << left << endl;
		}
		if (mas[start + count1] > poisk)
		{
			right = start + count1;
			cout << "right" << right << endl;
		}
		if (mas[start + count1] == poisk)
		{
			cout << "Элемент " << poisk << "найден!" << endl;
			break;
		}
		if (right != 0)
			Fibonachchi_find(mas, left, right, poisk);
		int temp = count1;
		count1 = count2;
		count2 += temp;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int N = 0;
	cout << "Введите размер массива: ";
	cin >> N;
	int* Array = new int[N];
	cout << "Массив до сортировки: " << endl;
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
	cout << endl;
	int find = 0;
	cout << "Введите ключ: ";
	cin >> find;
	Fibonachchi_find(Array, 0, N, find);

	return 0;
}

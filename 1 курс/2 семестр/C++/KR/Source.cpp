#include <iostream>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;
int *findminmax(int* mas, int size, int* rezult)
{
	rezult[0] = -10;//max
	rezult[1] = 10;//min
	rezult[2] = 0;//index max
	rezult[3] = 0;//index min
	for (int i = 0; i < size; i++)
	{
		if (mas[i] > rezult[0])
		{
			rezult[0] = mas[i];
			rezult[2] = i;
		}
		if (mas[i] < rezult[1])
		{
			rezult[1] = mas[i];
			rezult[3] = i;
		}

	}
	return rezult;

}
int main()
{
	srand(time(NULL));
	setlocale(0, "Russian");
	int N, M;
	cout << "Введите размер для двух массивов: ";
	cin >> N >> M;
	int* arr1 = new int[N];
	int* arr2 = new int[M];
	for (int i = 0; i < N; i++)//заполнение и вывод массивов
	{
		arr1[i] = rand() % 21 - 10;
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < M; i++)
	{
		arr2[i] = rand() % 21 - 10;
		cout << arr2[i] << " ";
	}
	cout << endl;
	int rez1[4];//максимум, минимум и их позиции(х2)
	int rez2[4];
	findminmax(arr1, N, rez1);
	findminmax(arr2, M, rez2);
	int r1, r2;//расстояние между максимумом и минимумом
	r1 = abs(rez1[2] - rez1[3]) -1;
	r2 = abs(rez2[2] - rez2[3]) - 1;
	if (r1 < r2)
		cout << "Расстояние между максимумом и минимумом в 1 массиве меньше."<<endl;
	else if (r2 < r1)
		cout << "Расстояние между максимумом и минимумом во 2 массиве меньше."<<endl;
	else if (r2 == r1)
		cout << "Расстояние между максимумом и минимумом в массивах равны."<<endl;
	delete[] arr1;
	delete[] arr2;
	system("pause");
	return 0;
}
#include<stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include<clocale>
#include <ctime>

using namespace std;
double poisk_maxel1(double** mas, int n, int m)// поиск максимального элемента в левой заштрихованной плоскости
{


	double maxel1 = **mas;

	for (int j = 0; j < (m / 2); j++)
	{
		for (int i = j; i < (n - j); i++)
		{
			if (maxel1 < *(*(mas + i) + j))

				maxel1 = *(*(mas + i) + j);

		}

	}
	return maxel1;
}
double poisk_maxel2(double** mas, int n, int m)// поиск максимального элемента в правой заштрихованной плоскости

{
	double maxel2 = mas[n][m];
	for (int j = m / 2; j < m; j++)
	{
		for (int i = n - j - 1; i <= j; i++)
		{
			if (maxel2 < *(*(mas + i) + j))

				maxel2 = *(*(mas + i) + j);

		}

	}
	return maxel2;

}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m;
	cout << "¬ведите n и m " << endl;
	cout << "√де n-это количество строк , а m-это количество столбцов" << endl;
	cin >> n >> m;
	double** mas = NULL; // вещественный массив
	mas = new double* [n];
	for (int i = 0; i < n; ++i)
	{
		mas[i] = new double[m];
		for (int j = 0; j < m; ++j)
		{

			mas[i][j] = (double)(rand() % 15 - 10);
			cout << mas[i][j] << "\t";
		}
		cout << "\n";
	} // создание динамического масссива

	cout << "---------------------------" << endl;

	double new_mas[2] = { poisk_maxel1(mas,n,m),poisk_maxel2(mas,n,m) };
	int i = 0;
	while (new_mas[i])
	{
		cout << mas[i] << " ";
		i++;
	}



	delete[]mas;
	system("pause");
	return 0;

}
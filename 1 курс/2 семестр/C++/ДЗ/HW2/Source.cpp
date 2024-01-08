#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <clocale>
#include <iostream>
using namespace std;
void find1(double *mas, int n, double &r, double &nr)
{
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < n; i++)
		{
			if (mas[i] == mas[j])
				t++;
		}
		if (t > 1)
			r++;
		else
			nr++;
	}

}
double **find2(double *mas, int n,double **repe)
{
	int t = 0, r = 0, nr = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < n; i++)
		{
			if (mas[i] == mas[j])
				t++;
		}
		if (t > 1)
		{
			r++;
			repe[0][r] = i;
		}
		else
		{
			nr++;
			repe[1][nr] = i;
		}
	}
	return repe;
}
int _tmain(int argc, _TCHAR *argv[])
{
	setlocale(LC_ALL, "Russian");
	int size;
	cin >> size;
	double *Arr = new double[size];
	for (int i = 0; i < size; i++)
	{
		Arr[i] = rand()%201-100 + (double)rand()/RAND_MAX;
		cout << Arr[i] << endl;
	}
	cout << endl;
	double rep = 0, notrep = 0;
	find1(Arr, size, rep, notrep);
	cout << " оличество повтор€ющихс€ и неповтор€ющихс€ элементов:" << endl;
	cout << rep << " " << notrep << endl;
	double **repeat = new double*[2];
	for (int i = 0; i < size; i++)
		repeat[i] = new double[size];
	find2(Arr, size, repeat);
	cout << "»ндексы повтор€ющихс€ элементов: "<< endl;
	for (int i = 0; i < rep; i++)
		cout << repeat[0][i] << " " << endl;
	cout << "»ндексы неповтор€ющихс€ элементов: "<< endl;
	for (int i = 0; i < notrep; i++)
		cout << repeat[1][i] << " " << endl;
	system("pause");
	return 0;
}
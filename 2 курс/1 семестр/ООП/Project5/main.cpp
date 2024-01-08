#include <iostream>
#include <locale>
#include "time.h"
#include "lab5.h"
using namespace std;
void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int size1, size2;
	int k1min = 0, k1max = 0, k2min = 0, k2max = 0;
	cout << "¬ведите размер массива 1: ";
	cin >> size1;
	double* Mas1 = new double[size1];
	init(Mas1, size1);
	k1min = min(Mas1, size1);
	k1max = max(Mas1, size1);
	sum(0, k1min, Mas1);
	cout << "¬ведите размер массива 2: ";
	cin >> size2;
	int* Mas2 = new int[size2];
	init(Mas2, size2);
	k2min = min(Mas2, size2);
	k2max = max(Mas2, size2);
	sum(k2min, k2max, Mas2);

}
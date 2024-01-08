#include <iostream>
#include <locale>
#include "time.h"
#include "lab5.h"
using namespace std;

void sum(int k1, int k2, double* arr)
{
	double sum = 0;
	for (int i = k1; i < k2 + 1; i++)
		sum += arr[i];
	cout << "Cумма элементов от начала массива до минимального равна: " << sum << endl;
}

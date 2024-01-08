#include <stdio.h> 
#include <stdlib.h>
#include <clocale>
#include <iostream>
#include <iomanip>
using namespace std;
int func(int a)
{
	int b = 0, i = 0;
	while (a!=0)
	{
		b +=( (a % 2) * pow(10, i));
		a = a/2;
		i++;
	}
	return b;
}
int main()
{
	int d;
	int c;
	setlocale(LC_ALL, "Russian");
	printf("¬ведите число: ");
	scanf_s("%d", &d);
	c = func(d);
	printf("¬веденное число в двоичной системе счислени€: %d\n", c);
	system("pause");
	return 0;

}

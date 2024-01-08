
#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	double x;
	int a, b, c, d;
	printf("¬ведите четыре целых числа:");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &c);
	scanf_s("%d", &d);
	while (b==0)
	
	{
		printf("¬ведите другое число:");
		scanf_s("%d", &b);
	}
	while (d == 0)
	{
		printf("¬ведите другое число:");
		scanf_s("%d", &d);
	}
	x = (a / (double)b) + (c / (double)d);
	printf("–езультат выражени€:%f\n",x);

	system("pause");
	return 1;
}
#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int x,a,b;
	int s = 0;
	printf("¬ведите диапазон,первое введенное вами число должно быть меньше второго:");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	while (b<a)
	{ 
		printf("¬ведите другой диапазон:");
		scanf_s("%d", &a);
		scanf_s("%d", &b);
	}
	printf("¬ведите целое число:");
	scanf_s("%d", &x);
	while (x != 0)
	{
		printf("¬ведите еще одно целое число:");
		scanf_s("%d", &x);
		if ((x >= a) && (x <= b))
			s += x;
	}
	printf("—умма равна:%d\n", s);
	system("pause");
	return 1;
}
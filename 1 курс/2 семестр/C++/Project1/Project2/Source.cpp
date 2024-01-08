#include <stdio.h> 
#include <stdlib.h>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	printf("¬ведите номер мес€ца:");
	scanf_s("%d", &x);
	while (x>12)
	{
		printf("¬ведите другой номер:");
		scanf_s("%d", &x);
	}
	switch (x)
	{
	case 1: printf("1 - €нварь, зима\n");
		break;
	case 2: printf("2 - февраль, зима\n");
		break;
	case 3: printf("3 - март, весна\n");
		break;
	case 4: printf("4 - апрель, весна\n");
		break;
	case 5: printf("5 - май, весна\n");
		break;
	case 6: printf("6 - июнь, лето\n");
		break;
	case 7: printf("7 - июль, лето\n");
		break;
	case 8: printf("8 - август, лето\n");
		break;
	case 9: printf("9 - сент€брь, осень\n");
		break;
	case 10: printf("10 - окт€брь, осень\n");
		break;
	case 11: printf("11 - но€брь, осень\n");
		break;
	case 12: printf("12 - декабрь, зима\n");
		break;
	}
	system("pause");
	return 1;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <locale.h>
#include <ctype.h>
#include <locale.h>


typedef struct supplier
{
	int section;
	char* name;
	double price;
	int quant;
}
supplier;

int addproduct(supplier* prod, int number)
{

	bool repit = false;
	char buff[50];
	int x, num, quant;
	double price;
	system("cls");
	printf("Номер секции: ");
	x = scanf("%d", &num);
	getchar();
	printf("Название товара: ");
	fgets(buff, 50, stdin);
	buff[strlen(buff) - 1] = '\0';
	printf("Цена: ");
	x = scanf("%lf", &price);
	printf("Количество: ");
	x = scanf("%d", &quant);
	for (int i = 0; i < number; i++)
		if (strcmp(prod[i].name, buff) == 0)
		{
			prod[i].quant += quant;
			repit = true;
		}
	if (!repit)
	{
		number++;
		prod[number - 1].section = num;
		prod[number - 1].name = (char*)calloc(strlen(buff) + 1, sizeof(char));
		strcpy(prod[number - 1].name, buff);
		prod[number - 1].price = price;
		prod[number - 1].quant = quant;
		repit = false;
	}
	return number;
}

void secprod(supplier* prod, int number, int sec)
{

	int** temp_array, a;
	char** text;
	int count = 0;
	for (int i = 0; i < number; i++)
		if (prod[i].section == sec) count++;
	if (count > 0)
	{
		text = (char**)calloc(count, sizeof(char*));
		for (int i = 0, k = 0; i < number; i++)
			if (prod[i].section == sec)
			{
				text[k] = (char*)calloc(strlen(prod[i].name) + 1, sizeof(char));
				strcpy(text[k], prod[i].name); k++;
			}
		temp_array = (int**)calloc(2, sizeof(int*));
		for (int i = 0; i < 2; i++)
			temp_array[i] = (int*)calloc(count, sizeof(int));
		for (int i = 0; i < count; i++)
		{
			temp_array[0][i] = i;
			temp_array[1][i] = text[i][0];
		}
		for (int i = 0; i < count; i++)
			for (int j = 0; j < count; j++)
				if (j + 1 != count && temp_array[1][j] > temp_array[1][j + 1])
				{
					a = temp_array[1][j];
					temp_array[1][j] = temp_array[1][j + 1];
					temp_array[1][j + 1] = a;
					a = temp_array[0][j];
					temp_array[0][j] = temp_array[0][j + 1];
					temp_array[0][j + 1] = a;
				}
		printf("Товары в секции  %d : ", sec);
		for (int i = 0; i < count; i++)
		{
			a = temp_array[0][i];
			if (i == 0) printf("%s", text[a]);
			else printf(", %s", text[a]);
		}
		printf(".\n");
		for (int i = 0; i < 2; i++)
			free(temp_array[i]);
		free(temp_array);
		for (int i = 0; i < count; i++)
			free(text[i]);
		free(text);
	}
	else printf("Таких секций не существует\n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	char buff[50];
	int n, x, func, number = 0;
	bool b = false;
	printf("Введите количество товаров: ");
	x = scanf("%d", &n);
	supplier* sklad = (supplier*)calloc(n, sizeof(supplier));
	while (!b)
	{
		system("cls");
		printf("Добавить товар..................................................1\n");
		printf("Распечатать информацию о товаре ................................2\n");
		printf("Найти все товары заданной секции................................3\n");
		printf("Определить товары с количеством меньше заданного................4\n");
		printf("Распечатать информацию о всех товарах...........................5\n");
		printf("Выход...........................................................6\n");
		printf("Введите номер функции: ");
		x = scanf("%d", &func);
		switch (func)
		{
		case 1:
		{
			if (number < n) number = addproduct(sklad, number);
			else
			{
				system("cls");
				printf("Вы добавили максимум товаровов\n");
				system("pause");
			}
			break;
		}
		case 2:
		{
			system("cls");
			int isexist = -1;
			printf("Введите название товара:\n ");
			getchar();
			fgets(buff, 50, stdin);
			buff[strlen(buff) - 1] = '\0';
			for (int i = 0; i < number; i++)
				if (strcmp(buff, sklad[i].name) == 0) isexist = i;
			if (isexist != -1)
			{
				system("cls");
				printf("Секция:\t Название: \t Цена:\t Количество:\n");
				printf("---------------------------------------------------\n");
				printf("\%d\t\t%s\t%lf\t%d\n", sklad[isexist].section, sklad[isexist].name, sklad[isexist].price, sklad[isexist].quant);
				printf("---------------------------------------------------\n");
			}
			else printf("Товаров с таким названием не существует\n");
			system("pause");
			break;
		}
		case 3:
		{
			int sec;
			system("cls");
			printf("Введите номер секции: ");
			x = scanf("%d", &sec);
			secprod(sklad, number, sec);
			system("pause");
			break;
		}
		case 4:
		{
			int c, q = 0;
			system("cls");
			printf("Введите количество: ");
			x = scanf("%d", &c);
			for (int i = 0; i < number; i++)
				if (sklad[i].quant < c) q++;
			if (q > 0)
			{
				printf("Секция:\t Название: \t Цена:\t Количество:\n");
				for (int i = 0; i < number; i++)
					if (sklad[i].quant < c)
					{
						printf("---------------------------------------------------\n");
						printf("\%d\t\t%s\t%lf\t%d\n", sklad[i].section, sklad[i].name, sklad[i].price, sklad[i].quant);
					}
				printf("---------------------------------------------------\n");
			}
			else printf("Отсутствуют товары с меньшим количеством\n");
			system("pause");
			break;
		}
		case 5:
		{
			system("cls");
			if (number != 0)
			{
				printf("Секция:\t Название: \t Цена:\t Количество:\n");
				for (int i = 0; i < number; i++)
				{
					printf("---------------------------------------------------\n");
					printf("\%d\t\t%s\t%lf\t%d\n", sklad[i].section, sklad[i].name, sklad[i].price, sklad[i].quant);
				}
				printf("---------------------------------------------------\n");
			}
			else printf("В базе данных нет никакой информации\n");
			system("pause");
			break;
		}
		case 6:
			b = true;
		}
	}
	free(sklad);
	return 0;
}

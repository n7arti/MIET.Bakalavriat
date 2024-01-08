#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <clocale>
#include <cstdlib>
#include <ctime>
int **find(char** arr, int str, int**result)
{
	for (int i=0;i<4;i++)
	*(*(result + str) + i) = 0;
	*(*(result+str)+0) = strlen(arr[str]); //длина строки
	if (isalpha(*(*(arr + str))) || isdigit(*(*(arr + str))))
		++* (*(result + str) + 1);
	for (int i = 0; i < *(*(result + str) + 0); i++)
	{
		if ((isspace(*(*(arr + str) + i))&& !isspace(*(*(arr + str) + i+1)) ))//количество слов(если элемент равен пробелу или переносу строки)
			++*(*(result + str) + 1);
		if (isdigit(*(*(arr + str) + i)))//количество цифр
			++*(*(result + str) + 2);
		if (isspace(*(*(arr + str) + i)))//количество пробелов
			++*(*(result + str) + 3);
	}
	return result;
	
}
using namespace std;
int main()
{
	setlocale(0, "Russian");
	const int len = 30;
	char buff[len] = { 'q' };
	int k = -1;
	char** text = new char* [len];
	for (int i = 0; i < len; i++)
		text[i] = new char[sizeof(*text)];
	cout << "Введите несколько строк, окончание ввода - and" << endl;//ввод строк
	while (abs(strcmp(buff, "and")))//пока строка не равна and
	{
		k++;
		gets_s(buff);
		*(text + k) = new char[strlen(buff) + 1];
		strcpy(*(text + k), buff);
	}
	int** res = NULL;//массив с длиной, количеством слов, цифр и пробелов
	res = new int* [k];
	for (int i = 0; i < k; i++)
		res[i] = new int[4];
	for (int i = 0; i < k; i++)//вывод результатов
	{
		res = find(text,i,res);
		cout << "Длинна строки: " << *(*(res + i) + 0) << " ";
		cout << "Количество слов: " << *(*(res + i) + 1) << " ";
		cout << "Количество цифр: " << *(*(res + i) + 2) << " ";
		cout << "Количество пробелов: " << *(*(res + i) + 3) << endl;
	}
	for (int i = 0; i < k-1; i++)// сортировка строк по убыванию количества цифр
	{
		for (int j = 0; j < k-1-i; j++)
		{
			if (*(*(res + j) + 2) < *(*(res + j+1) + 2))
			{
				int* t = *(res + j);
				*(res + j) = *(res + j+1);
				*(res + j+1) = t;
				char* h;
				h = *(text + j);
				*(text + j) = *(text + j+1);
				*(text + j+1) = h;
			}
		}
	}
	for (int i = 0; i < k; i++)//вывод текста
		cout << *(text + i) << "\n";

	int size = 0; //размер text2
	const char* ch = " ";
	for (int i = 0; i < k; i++)// сложение длины каждой строчки
		size += *(*(res + i) + 0);
	size += k;//+количество пробелов равных количеству строк
	size++; //символ конца строки
	char* text2 = NULL; // массив для "склеенного" текста
	text2 = new char[size];
	text2[0] = {};
	for (int i = 0; i < k; i++)//объединение текста
	{
		strcat(text2, text[i]);
		strcat(text2, ch);
	}
	int lines, leng;
	cout << "Введите количество строк и символов в строке ";
	scanf("%d", &lines);
	scanf("%d", &leng);
	int r = 0;
	r = size / (lines * leng);//количество страниц
	int chr = 0, string = 0, num = 1;
	cout << "Страница 1"<< endl;//вывод отформатированного текста
	for (int i = 0; i < size; i++)
	{
		chr++;
		if (chr == leng)
		{
			cout << endl;
			chr = 0;
			string++;
		}
		if (string == lines)
		{
			num++;
			cout << "Страница " << num << endl;
			string = 0;
		}
		cout<< *(text2 + i);
	}
	cout << endl;
	delete[] text;
	delete[] res;
	delete[] text2;
	system("pause");
	return 0;
}
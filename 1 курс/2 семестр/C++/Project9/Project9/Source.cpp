#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <clocale>

#include <stdio.h>

#include <stdlib.h>

#include <iomanip>// чтобы красивый вывод был

#include <string.h>

#define N 80

using namespace std;

struct parcel

{

	char* surname;// фамилия отправителя

	char* name;// имя отправителя

	char* adres;// адрес отправителя

	char* surname1;//фамилия получателя

	char* name1;// имя получателя

	double weight;// вес

} bebe;

void add_new_parcel(parcel* bebe, int kol)// функция добавления новой посылки

{

	char buf[N]; // kol- количество посылок

	for (int i = 0; i < kol ; i++)

	{

		cout << "kkkkkk " << i+1;

		cout << "Введите информацию о посылке" << endl;

		cout << "Фамилия отправителя :" << endl;

		cin >> buf;

		bebe[i].surname = new char[strlen(buf) + 1];

		strcpy(bebe[i].surname, buf); // копировать buff в динамическую память

		cout << "Имя отправителя :" << endl;

		cin >> buf;

		bebe[i].name = new char[strlen(buf) + 1];

		strcpy(bebe[i].name, buf);

		cout << "Адрес отправителя :" << endl;

		cin >> buf;

		bebe[i].adres = new char[strlen(buf) + 1];

		strcpy(bebe[i].adres, buf);

		cout << "Фамилия получателя :" << endl;

		cin >> buf;

		bebe[i].surname1 = new char[strlen(buf) + 1];

		strcpy(bebe[i].surname1, buf);

		cout << "Имя получателя :" << endl;

		cin >> buf;

		bebe[i].name1 = new char[strlen(buf) + 1];

		strcpy(bebe[i].name1, buf);

		cout << "Вес посылки :" << endl;

		cin >> bebe[i].weight;

		cout << "---------------------------------" << endl;

	}

}

void print_info_parcel(parcel* bebe, int num)// распечатать информацию о посылке

{

	for (int i = num; ; )

	{

		cout << "Информация о посылке" << i << ":" << endl;

		cout << "Фамилия отправителя :" << bebe[i].surname << endl;

		cout << "Имя отправителя :" << bebe[i].name << endl;

		cout << "Адрес отправителя :" << bebe[i].adres << endl;

		cout << "Фамилия получателя :" << bebe[i].surname1 << endl;

		cout << "Имя получателя" << bebe[i].name1 << endl;

		cout << "Вес посылки" << bebe[i].weight << endl;

		cout << "-------------------------" << endl;

	}

}

void find_parcel_ot()// найти все посылки заданного отправителя

{

}

void find_parcel_weight(double* w)// найти все посылки с весом больше заданного

{

}

int main()

{

	setlocale(0, "Russian");

	// динамическое выделение памяти под количество посылок

	// ДОБАВИТЬ ПРОВЕРКУ ВВОДА ИМЕННО ЧИСЛА!

	cout << " Проект Почта" << endl;

	cout << "Введите количество посылок , которое вы хотите внести в базу" << endl;

	int kol;

	cin >> kol;

	parcel* basa = new parcel[kol];

	cout << "Добавить товар.........................................1" << endl;
	cout << "Распечатать информацию о товаре в табличном виде......2" << endl;
	cout << "Найти все посылки заданного отправителя................3" << endl;
	cout << "Найти все посылки с весом больше заданного.............4" << endl;
	cout << "Выход..................................................5" << endl;

	int n;

	cin >> n;

	while (n != 5)

	{

		switch (n)

		{

		case 1:

			add_new_parcel(basa, kol);
			cin >> n;

			break;

		case 2:

		{

			cout << "О какой посылке вы хотите узнать информацию?" << endl;

			cout << "Введите номер посылки: " << endl;

			int num;

			cin >> num;

			print_info_parcel(basa, num);

		}

		break;

		case 3:

			break;

		case 4:

			break;

		}

	}

	delete[] basa;// очищение динамического массива

	system("pause");

	return 0;

}
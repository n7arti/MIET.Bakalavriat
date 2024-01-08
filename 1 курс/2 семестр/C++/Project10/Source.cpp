#include <iostream>
#include <stdio.h>
#include <time.h>
#include <locale.h>
#define BUFSIZE 80
#define NAMESIZE 28
using namespace std;

struct supplier {
	int section;
	char* name;
	double price;
	int vol;
};

enum {
	SECTION,
	VOLUME,
	ALL
};

typedef struct List {
	supplier data;
	List* next;
} List;

int listSize(List* head)
{
	int k = 0;
	List* cur;
	if (head == NULL) {
		return 0;
	}
	cur = head;
	while (cur != NULL) {
		cur = cur->next;
		k++;
	}
	return k;
}

bool isSupplierExist(List* head, supplier t)
{
	bool isExist = false;
	List* cur = head;
	while (cur != NULL) {
		if (strcmp(cur->data.name, t.name) == 0 && cur->data.price == t.price && cur->data.section == t.section) {
			cur->data.vol = t.vol;
			isExist = true;
			break;
		}
		cur = cur->next;
	}
	return isExist;
}

List* addLast(List* head, supplier t)
{
	List* newSupplier;
	List* cur;
	newSupplier = (List*)malloc(sizeof(List));
	newSupplier->data = t;
	newSupplier->next = NULL;
	if (head == NULL)
		return newSupplier;
	else {
		cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		cur->next = newSupplier;
		return head;
	}
}

List* addSupplier(List* head)
{
	supplier t;
	char buff[BUFSIZE];
	int status = 0;
	cout << "Название товара: ";
	gets_s(buff);
	t.name = (char*)malloc(strlen(buff) + 1);
	strcpy_s(t.name, strlen(buff) + 1, buff);
	while (status != 1) {
		cout << "Цена: ";
		gets_s(buff);
		status = sscanf_s(buff, "%lf\n", &t.price);
		if (status != 1) {
			cout << "Неверный формат" << endl;
		}
	}
	status = 0;
	while (status != 1) {
		cout << "Количество: ";
		gets_s(buff);
		status = sscanf_s(buff, "%d\n", &t.vol);
		if (status != 1) {
			cout << "Неверный формат" << endl;
		}
	}
	status = 0;
	while (status != 1) {
		cout << "Номер секции:";
		gets_s(buff);
		status = sscanf_s(buff, "%d\n", &t.section);
		if (status != 1) {
			cout << "Неверный формат" << endl;
		}
	}
	cout << "Поставщик добавлен" << endl;
	if (isSupplierExist(head, t)) {
		return head;
	}
	else {
		return addLast(head, t);
	}
}

void deleteSection(List** head)
{
	int s;
	char buff[BUFSIZE];
	cout << "Секция товара для удаления: ";
	cin >> s;
	List* cur, * work;
	bool isExist = false;
	if ((*head)->data.section == s) {
		work = (*head)->next;
		free(*head);
		*head = work;
		isExist = true;
	}
	else {
		cur = *head;
		while (cur->next != NULL) {
			if (cur->next->data.section == s) {
				isExist = true;
				break;
			}
			else {
				cur = cur->next;
			}
		}
		if (isExist) {
			work = cur->next->next;
			free(cur->next);
			cur->next = work;
		}
	}
	if (!isExist) {
		cout << "Не существует данной секции" << endl;
	}
}

void printStock(List* head, int mode = ALL, int value = -1)
{
	printf("------------------------------------------------------------------------------------\n");
	printf("Секция | Название | Цена | Количество \n");
	printf("------------------------------------------------------------------------------------\n");
	List* cur = head; struct tm date_time;
	switch (mode) {
	case SECTION:
		while (cur != NULL) {
			if (value == cur->data.section) {
				printf("%8d | %28s | %10.2f | %10d \n",
					cur->data.section, cur->data.name, cur->data.price, cur->data.vol);
			}
			cur = cur->next;
		}
		break;
	case VOLUME:
		while (cur != NULL) {
			if (cur->data.vol < value) {
				printf("%8d | %28s | %10.2f | %10d \n",
					cur->data.section, cur->data.name, cur->data.price, cur->data.vol);
			}
			cur = cur->next;
		}
		break;
	default:
		while (cur != NULL) {
			printf("%8d | %28s | %10.2f | %10d \n",
				cur->data.section, cur->data.name, cur->data.price, cur->data.vol);
			cur = cur->next;
		}
		break;
	}
	printf("------------------------------------------------------------------------------------\n");
}

void printSection(List* head)
{
	int section;
	int status = 0;
	char buff[BUFSIZE];
	while (status != 1) {
		cout << "Номер секции: ";
		gets_s(buff);
		status = sscanf_s(buff, "%d\n", &section);
		if (status != 1) {
			cout << "Неверный формат" << endl;
		}
	}
	printStock(head, SECTION, section);
}

void printStockVolLess(List* head)
{
	int vol;
	int status = 0;
	char buff[BUFSIZE];
	while (status != 1) {
		cout << "Максимальное количество товаров: ";
		gets_s(buff);
		status = sscanf_s(buff, "%d\n", &vol);
		if (status != 1) {
			cout << "Неверный формат" << endl;
		}
	}
	printStock(head, VOLUME, vol);
}

void sortByPrice(List** head)
{
	List* cur, * work;
	List* temp1, * temp2;
	int size;
	if (head == NULL) {
		return;
	}
	size = listSize(*head);
	for (int i = 0; i < size - 1; i++) {
		cur = *head;
		work = *head;
		for (int j = 0; j > size - i - 1; j++) {
			if (cur->data.price > cur->next->data.price) {
				temp1 = cur;
				cur = cur->next;
				cur->next = temp1;
				if (j == 0) {
					*head = cur;
				}
				else {
					work->next = cur;
				}
			}
			work = cur;
			cur = cur->next;
		}
	}
}

List* loadStockFromFile()
{
	FILE* f = NULL;
	List* stock = NULL;
	supplier t;
	char buff[BUFSIZE];
	char name[NAMESIZE];
	int fid = fopen_s(&f, "stock.txt", "r");
	long long ttt;
	if (!f) {
		cout << "Файл не может быть открыт \"stock.csv\"" << endl;
		return NULL;
	}
	while (!feof(f)) {
		fgets(buff, sizeof(buff), f);
		sscanf_s(buff, "%d | %s | %lf | %d \n", &t.section, name, NAMESIZE, &t.price, &t.vol);
		t.name = (char*)malloc(strlen(name) + 1);
		strcpy_s(t.name, strlen(name) + 1, name);
		if (!isSupplierExist(stock, t)) {
			stock = addLast(stock, t);
		}
	}
	fclose(f);
	return stock;
}

void saveStockToFile(List* head)
{
	FILE* f = NULL;
	List* cur = head;
	int fid = fopen_s(&f, "stock.txt", "w");
	if (!f) {
		cout << "Файл не может быть открыт \"stock.csv\"" << endl;
		return;
	}

	while (cur != NULL) {
		fprintf(f, "%8d | %28s | %10.2f | %10d \n", cur->data.section, cur->data.name, cur->data.price, cur->data.vol);
		cur = cur->next;
	}
	fclose(f);
}

int getCommand()
{
	char buff[BUFSIZE];
	int cmd;
	bool cmd_done = false;
	int status = 0;
	while (!cmd_done) {
		cout << "Выход............................................0" << endl;
		cout << "Добавить товар...................................1" << endl;
		cout << "Распечатать информацию о товарах.................2" << endl;
		cout << "Найти все товары в указанной секции..............3" << endl;
		cout << "Найти товары с количеством меньше указанного.....4" << endl;
		cout << "Удалить информацию о товарах.....................5" << endl;
		cout << "Сохранить список на диске........................6" << endl;
		cout << "Найти товары по разделам и удалить их............7" << endl;
		cout << "Сортировать список в порядке убывания цены.......8" << endl;
		cout << "Введите номер функции: ";
		gets_s(buff);
		status = sscanf_s(buff, "%d\n", &cmd);
		cout << cmd << ", err:" << status << endl;
		if (cmd < 0 || cmd > 8 || status != 1) {
			cout << "Неизвестная функция" << endl;
		}
		else {
			cmd_done = true;
		}
	}
	return cmd;
}

int main()
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251");
	int cmd;
	List* stock = loadStockFromFile();
	printStock(stock);
	while (true) {
		cmd = getCommand();
		switch (cmd) {
		case 0:
			saveStockToFile(stock);
			exit(0);
			break;
		case 1:
			system("cls");
			stock = addSupplier(stock);
			break;
		case 2:
			system("cls");
			printStock(stock);
			break;
		case 3:
			system("cls");
			printSection(stock);
			break;
		case 4:
			system("cls");
			printStockVolLess(stock);
			break;
		case 5:
			system("cls");
			stock = NULL;
			break;
		case 6:
			system("cls");
			saveStockToFile(stock);
			break;
		case 7:
			system("cls");
			deleteSection(&stock);
			break;
		case 8:
			system("cls");
			sortByPrice(&stock);
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}

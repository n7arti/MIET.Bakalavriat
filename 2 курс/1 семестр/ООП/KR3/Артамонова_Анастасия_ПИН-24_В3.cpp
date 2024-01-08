#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
using namespace std;
class date
{
	int day;
	int month;
	int year;
public:
	date();
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	void set_day(int day_v) { day = day_v; }
	void set_month(int month_v) { month = month_v; }
	void set_year(int year_v) { year = year_v; }
	friend std::istream& operator>> (std::istream& in, date& DATE);
	date& operator= (const date& DATE);
};
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}
std::istream& operator>> (std::istream& in, date& DATE)
{
	int g = 0;
	char* buff = new char[20];
	cout << "День: ";
	in >> buff;
	while (1)
	{
		g = 0;
		if (atoi(buff) > 31 || atoi(buff) < 1)
		{
			cout << "Не корректный ввод!" << endl;
			in >> buff;
			g++;
		}
		for (int i = 0; i < strlen(buff); i++)
		{
			if (!isdigit(buff[i]))
			{
				cout << "Не корректный ввод!" << endl;
				in >> buff;
				g++;
			}
		}
		if (g == 0)
		{
			DATE.day = atoi(buff);
			break;
		}
	}
	cout << "Месяц: ";
	in >> buff;
	while (1)
	{
		g = 0;
		if (atoi(buff) > 12 || atoi(buff) < 1)
		{
			cout << "Не корректный ввод!" << endl;
			in >> buff;
			g++;
		}
		for (int i = 0; i < strlen(buff); i++)
		{
			if (!isdigit(buff[i]))
			{
				cout << "Не корректный ввод!" << endl;
				in >> buff;
				g++;
			}
		}
		if (g == 0)
		{
			DATE.month = atoi(buff);
			break;
		}
	}
	cout << "Год: ";
	in >> buff;
	while (1)
	{
		g = 0;
		if (atoi(buff) < 1)
		{
			cout << "Не корректный ввод!" << endl;
			in >> buff;
			g++;
		}
		for (int i = 0; i < strlen(buff); i++)
		{
			if (!isdigit(buff[i]))
			{
				cout << "Не корректный ввод!" << endl;
				in >> buff;
				g++;
			}
		}
		if (g == 0)
		{
			DATE.year = atoi(buff);
			break;
		}
	}
	return in;
}
date& date::operator= (const date& DATE)
{
	day = DATE.day;
	month = DATE.month;
	year = DATE.year;
	return *this;
}
class tovar
{
protected:
	char* name;
	double price;
public:
	tovar();
	~tovar();
	char* get_name() { return name; }
	double get_price() { return price; }
	void set_name(char* name_v) { name = name_v; }
	void set_price(double price_v) { price = price_v; }
	virtual void ToString();
	virtual void Add();
};
tovar::tovar()
{
	price = 0;
	name = new char[50];
}
tovar::~tovar()
{
	delete[] name;
}
void tovar::Add()
{
	system("cls");
	char* buff = new char[50];
	cout << "Введите название товара: ";
	cin >> buff;
	name = new char[strlen(buff) - 1];
	strcpy(name, buff);
	cout << "Введите цену: ";
	cin >> price;
	
	system("pause");
}
void tovar::ToString()
{
	cout << "Название товара: " << name << endl;
	cout << "Цена: " << price << endl;
	
}
class prod: tovar
{
	date shl;
public:
	date get_shl() { return shl; }
	friend istream& operator>> (istream& in, prod& prodv);
	prod& operator= (const prod& prodv);
	void ToString();
	void Add();
	
};
istream& operator>> (istream& in, prod& prodv)
{
	int g = 0;
	char* buff = new char[50];
	cout << "Введите название товара: ";
	in >> buff;
	strcpy(prodv.name, buff);
	cout << "Введите цену: ";
	in >> buff;
	prodv.set_price(atof(buff));
	cout << "Введите срок годности: " << endl;
	in >> prodv.shl;
	return in;
}
prod& prod::operator= (const prod& prodv)
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(prodv.name) + 1];
	strcpy(name, prodv.name);
	price = prodv.price;
	shl = prodv.shl;
	return *this;
}
void prod::Add()
{
	system("cls");
	cin >> *this;
	system("pause");
}
void prod::ToString()
{
	cout << "Название товара: " << name << endl;
	cout << "Цена: " << price << endl;;
	cout << "Срок годности: " << shl.get_day() << "." << shl.get_month() << "." << shl.get_year() << endl;
}
class prom:tovar
{
	int col;
public:
	prom();
	int get_col() { return col; }
	friend istream& operator>> (istream& in, prom& promv);
	prom& operator= (const prom& promv);
	void Add();
	void ToString();
};
prom::prom()
{
	col = 0;
}
istream& operator>> (istream& in, prom& promv)
{
	int g = 0;
	char* buff = new char[50];
	cout << "Введите название товара: ";
	in >> buff;
	strcpy(promv.name,buff);
	cout << "Введите цену: ";
	in >> buff;
	promv.set_price(atof(buff));
	cout << "Введите количество: ";
	in >> promv.col;
	return in;
}
prom& prom::operator= (const prom& promv)
{
	if (name != nullptr)
		delete[] name;
	name = new char[strlen(promv.name) + 1];
	strcpy(name, promv.name);
	price = promv.price;
	col = promv.col;
	return *this;
}
void prom::Add()
{
	system("cls");
	cin >> *this;
	system("pause");
}
void prom::ToString()
{
	cout << "Название товара: " << name << endl;
	cout << "Цена: " << price << endl;
	cout << "Количество: " << col << endl;
}
int main()
{
	setlocale(LC_ALL, "rus");
	int N = 0, K = 0, count = 0;
	date now = date();
	cout << "Какое количество продовольственных товаров вы хотите добавить в базу данных?" << endl;
	cin >> N;
	prod* prodt = new prod[N];
	prod* rezprod = new prod[N];
	for (int i = 0; i < N; i++)
		prodt[i].Add();
	system("cls");
	cout << "Успешно добавлено!" << endl;
	cout << "Какое количество промышленных товаров вы хотите добавить в базу данных?" << endl;
	cin >> K;
	prom* promt = new prom[K];
	prom* rezprom = new prom[K];
	for (int i = 0; i < K; i++)
		promt[i].Add();
	system("cls");
	cout << "Успешно добавлено!" << endl;
	cout << "Введите текущую дату: " << endl;
	cin >> now;
	int y = 0;
	for (int i = 0; i < K; i++)
		if (prodt[i].get_shl().get_day() < now.get_day())
		{
			if (prodt[i].get_shl().get_month() < now.get_month())
			{
				if (prodt[i].get_shl().get_year() < now.get_year())
					rezprod[y++] = prodt[i];
			}
			else if (prodt[i].get_shl().get_year() < now.get_year())
				rezprod[y++] = prodt[i];
		}
		else if (prodt[i].get_shl().get_month() < now.get_month())
		{
			if (prodt[i].get_shl().get_year() < now.get_year())
				rezprod[y++] = prodt[i];
		}
		else if (prodt[i].get_shl().get_year() < now.get_year())
			rezprod[y++] = prodt[i];
	cout << "Введите количестов товаров: " << endl;
	cin >> count;
	int c = 0;
	for (int i = 0; i < K; i++)
		if (promt[i].get_col() < count)
			rezprom[c++] = promt[i];

	for (int i = 0; i < c; i++)
		rezprom[i].ToString();
	for (int i = 0; i < y; i++)
		rezprod[i].ToString();
}
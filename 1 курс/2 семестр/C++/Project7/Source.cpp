#include <iostream>
#include <clocale>
using namespace std;
struct supplier
{
	int number;
	char* name;
	char* namefirm;
	double price;
	int count=1;
};
struct supplier2
{
	char* name;
	int k=0;
	int count = 1;
};
void cout_quality(supplier* supplier, int num, int& num2)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Введите название товара: ";
		cin >> supplier[i].name;
		for (int j = 0; j < num; j++)
		{
			if (j != i)
			{
				if (supplier[i].name == supplier[j].name)
				{
					supplier[i].count++;
					break;
				}
			}
		}
	}
	
}
void addInfo(supplier* supplier, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << "Введите информацию о товаре " << i + 1 << " : " << endl;
		cout << "Название товара: ";
		cin >> supplier[i].name;
		for (int j = 0; j < num; j++)
		{
			if (j != i)
			{
				if (supplier[i].name == supplier[j].name)
				{
					supplier[i].count++;
					break;
				}
			}
		}



	}
}
void find(supplier2* supplier, int size, int& colvo)
{
	int h = 0;
	cout << "Введите название товаров." << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> supplier[i].name;
		for (int j = 0; j < i; j++)
		{
			if (supplier[j].name == supplier[i].name)
			{
				h++;
				break;
			}
		}
	}
	colvo = size-h;
}
int main()
{
	setlocale(0, "Russian");
	int n;
	cout << "Введите количество товаров: " << endl;
	cin >> n;
	supplier2* product = new supplier2[n];
	int n2;
	int col;
	find(product,n,col);
	cout << col;

}
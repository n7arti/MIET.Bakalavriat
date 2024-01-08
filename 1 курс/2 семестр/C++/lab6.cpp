#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <clocale>
#include <cstdlib>
#include <ctime>
using namespace std;
struct supplier
{
    int id;
    char* name;
    char* namefirm;
    double price;
    int couunt;
};
void find(supplier *supplier, int size, int &colvo)
{
    int h = 0;
    cout<<"Введите название товаров."<<endl;
    for(int i=0;i<size;i++)
    {
        cin>>supplier[i].name;
        for(int j =0;j<i;j++)
        {
            if(supplier[j].name==supplier[i].name)
            {
                h++;
                break;
            }
        }
    }
    colvo = size - h;
}
int main()
{
	setlocale(0, "Russian");
	int n =0;
	cout<<"Введите количество товаров: ";
	cin>>n;
	supplier *product = new supplier[n];
	int col;
	find(product, n, col);
	cout<<col;
	system("pause");
	return 0;
}

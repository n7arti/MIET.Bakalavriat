#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <clocale>
#include <windows.h>
#include <stdlib.h>
using namespace std;
int main()
{
	setlocale(0, "Russian");
	ofstream outf("Test.txt");
	if(!outf)
	{
		cout << "Open error";
		return 1; 
	
	}
	const int len = 30;
	char buff[len] = {'q'};
	int k = -1;
	cout << "Введите несколько строк, окончание ввода - пустая строка" << endl;
	while (abs(strcmp(buff, "\0")))//пока строка ненулевая
	{
		k++;
		gets_s(buff);
		outf << buff << endl;;
	}
	outf.close();
	
	int lines = 0;
	char ch;
	int sym = 0;
	int max = -1;
	ifstream fs("Test.txt");
	if (!fs)
	{
		cout << "Open error";
		return 1;
	}
	do
	{
		ch = fs.get();
		cout << ch;
		if (ch != '\n')
			sym++;
		else
		{
			lines++;
			if (max < sym)
				max = sym;
			sym = 0;
		}
	} 
	while (!fs.eof());
	fs.close();
	cout << "Максимальное количество символов в строке " << max << endl;
	cout << "Количество строк " << lines-1 << endl;
	char** mas = new char* [lines-1];
	for (int i = 0; i < lines-1; i++)
		mas[i] = new char[len];
	ifstream inf("Teat.txt");
	for (int i = 0; i < lines-1; i++)
	{
		inf.getline(mas[i], len - 1, '\n');
		cout << "Строка " << i + 1 << " : " << mas[i] << endl;
	}
	inf.close();
	system("pause");
	return 0;
}
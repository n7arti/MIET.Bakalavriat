#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>
using namespace std;
int main()
{
	for (int i = 0; i < 3; i++)
		switch (i)
		{
		case 1: printf("%d", i); break;
		case 2: printf("%d", i);
		case 3: printf("%d", i); break;
		default: printf("%d", i);
	}
	system("pause");
	return 0;
}
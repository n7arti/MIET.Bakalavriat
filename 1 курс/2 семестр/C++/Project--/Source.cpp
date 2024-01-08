#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <clocale>
#include <iostream>

using namespace std;

int f(int x) { cout << "I"; return 0; }
int f(float x) { cout << "F"; return 0; }
int f(double x) { cout << "D"; return 0; }
int f(bool x) { cout << "B"; return 0; }
int main()
{



	return f(f(1.0) + f(2.f) + f(true));
	
	system("pause");



	



}

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void randInit(int** M, int n, int m) {
	for (int i = 0; i < n; i++) {
		M[i] = new int[m];
		for (int j = 0; j < m; j++)
			M[i][j] = rand() % 10;
	}
}

void malualInit(int** M, int n, int m) {
	for (int i = 0; i < n; i++) {
		M[i] = new int[m];
		for (int j = 0; j < m; j++)
			cin >> M[i][j];
	}
}
void nullInit(int** M, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		M[i] = new int[n];
		for (int j = 0; j < m; j++)
			M[i][j] = 0;
	}
}

void matrixInit(int** M, int** N, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			M[i][j] = N[i][j];
	}
}

void matrixConstInit(int** M, int** N, int size, int const1, int const2) {
	for (int i = 0; i < size; i++)
	{
		M[i] = new int[size];
		for (int j = 0; j < size; j++)
			M[i][j] = N[i + const1][j + const2];
	}
}

void printMatrix(int** M, int n, int m) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}
}
void main()
{
	srand(time(NULL));
	int n1, m1, n2, m2, k, l = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена" << endl << endl;

	///////////////////////////////////////////////////////////////////////////////
	////////////////////Ввод размеров матрицы пользователем////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Введите размеры первой матрицы" << endl;
		cin >> n1 >> m1;
	} while (n1 <= 0 || m1 <= 0);
	do
	{
		cout << "Введите размеры второй матрицы" << endl;
		cin >> n2 >> m2;
	} while (n2 <= 0 || m2 <= 0);

	int** M1 = new int* [n1];
	int** M2 = new int* [n2];

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выбор способа заполнения и заполнение матриц///////////////////
	///////////////////////////////////////////////////////////////////////////////

	do
	{
		cout << "Выберите способ заполнения матриц" << endl <<
			"1 - Вручную" << endl << "2 - Случайным образом" << endl;
		cin >> k;
	} while (k < 1 || k > 2);
	switch (k)
	{
	case 1:
		malualInit(M1, n1, m1);
		malualInit(M2, n2, m2);
		break;
	case 2:
		randInit(M1, n1, m1);
		randInit(M2, n2, m2);
		break;
	}
	cout << endl << "Матрица 1" << endl << endl;
	printMatrix(M1, n1, m1);

	cout << endl << "Матрица 2" << endl << endl;
	printMatrix(M2, n2, m2);

	///////////////////////////////////////////////////////////////////////////////
	/////////////////Приведение матриц к требуемому размеру////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	while (l < n1 || l < n2 || l < m1 || l < m2)
		l *= 2;
	int** M3 = new int* [l];
	int** M4 = new int* [l];

	nullInit(M3, l, l);
	nullInit(M4, l, l);
	matrixInit(M3, M1, n1, m1);
	matrixInit(M4, M2, n2, m2);

	cout << "Приведенные матрицы" << endl;
	cout << endl << "Матрица 1" << endl << endl;
	printMatrix(M3, l, l);
	cout << endl << "Матрица 2" << endl << endl;
	printMatrix(M4, l, l);

	///////////////////////////////////////////////////////////////////////////////
	///////////////Разбиение матриц на подматрицы и их заполнение//////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat1 = new int* [l / 2];
	int** mat2 = new int* [l / 2];
	int** mat3 = new int* [l / 2];
	int** mat4 = new int* [l / 2];

	int** mat5 = new int* [l / 2];
	int** mat6 = new int* [l / 2];
	int** mat7 = new int* [l / 2];
	int** mat8 = new int* [l / 2];

	matrixConstInit(mat1, M3, l / 2, 0, 0);
	matrixConstInit(mat2, M3, l / 2, 0, l / 2);
	matrixConstInit(mat3, M3, l / 2, l / 2, 0);
	matrixConstInit(mat4, M3, l / 2, l / 2, l / 2);

	matrixConstInit(mat5, M4, l / 2, 0, 0);
	matrixConstInit(mat6, M4, l / 2, 0, l / 2);
	matrixConstInit(mat7, M4, l / 2, l / 2, 0);
	matrixConstInit(mat8, M4, l / 2, l / 2, l / 2);

	///////////////////////////////////////////////////////////////////////////////
	//////////Создание и вычисление промежуточных матриц //////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** p1 = new int* [l / 2];
	int** p2 = new int* [l / 2];
	int** p3 = new int* [l / 2];
	int** p4 = new int* [l / 2];
	int** p5 = new int* [l / 2];
	int** p6 = new int* [l / 2];
	int** p7 = new int* [l / 2];

	nullInit(p1, l / 2, l / 2);
	nullInit(p2, l / 2, l / 2);
	nullInit(p3, l / 2, l / 2);
	nullInit(p4, l / 2, l / 2);
	nullInit(p5, l / 2, l / 2);
	nullInit(p6, l / 2, l / 2);
	nullInit(p7, l / 2, l / 2);
	for (int i = 0; i < l / 2; i++)
	{
		for (int j = 0; j < l / 2; j++)
		{
			for (int z = 0; z < l / 2; z++) {
				p1[i][j] += (mat1[i][z] + mat4[i][z]) * (mat5[z][j] + mat8[z][j]);
				p2[i][j] += (mat3[i][z] + mat4[i][z]) * mat5[z][j];
				p3[i][j] += mat1[i][z] * (mat6[z][j] - mat8[z][j]);
				p4[i][j] += mat4[i][z] * (mat7[z][j] - mat5[z][j]);
				p5[i][j] += (mat1[i][z] + mat2[i][z]) * mat8[z][j];
				p6[i][j] += (mat3[i][z] - mat1[i][z]) * (mat5[z][j] + mat6[z][j]);
				p7[i][j] += (mat2[i][z] - mat4[i][z]) * (mat7[z][j] + mat8[z][j]);
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////////Создание вспомогательных матриц/////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** mat9 = new int* [l / 2];
	int** mat10 = new int* [l / 2];
	int** mat11 = new int* [l / 2];
	int** mat12 = new int* [l / 2];
	
	///////////////////////////////////////////////////////////////////////////////
	////////////Подсчет значений вспомогательных матриц из промежуточных///////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
	{
		mat9[i] = new int[l / 2];
		mat10[i] = new int[l / 2];
		mat11[i] = new int[l / 2];
		mat12[i] = new int[l / 2];
		for (int j = 0; j < l / 2; j++)
		{
			mat9[i][j] = p1[i][j] + p4[i][j] - p5[i][j] + p7[i][j];
			mat10[i][j] = p3[i][j] + p5[i][j];
			mat11[i][j] = p2[i][j] + p4[i][j];
			mat12[i][j] = p1[i][j] - p2[i][j] + p3[i][j] + p6[i][j];
		}
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Создание результирующей матрицы/////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int** M5 = new int* [l];
	for (int i = 0; i < l; i++)
		M5[i] = new int[l];

	///////////////////////////////////////////////////////////////////////////////
	///////Занесение информации из вспомогательных матриц в результирующую/////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < l / 2; i++)
		for (int j = 0; j < l / 2; j++)
		{
			M5[i][j] = mat9[i][j];
			M5[i][j + l / 2] = mat10[i][j];
			M5[i + l / 2][j] = mat11[i][j];
			M5[i + l / 2][j + l / 2] = mat12[i][j];
		}

	///////////////////////////////////////////////////////////////////////////////
	////////////////Выравнивание границ результирующей матрицы/////////////////////
	///////////////////////////////////////////////////////////////////////////////

	int x = 0, f = 100, s = 100;
	for (int i = 0; i < l; i++)
	{
		x = 0;
		for (int j = 0; j < l; j++)
			if (M5[i][j] != 0)
			{
				x++;
				f = 100;
				s = 100;
			}
		if (x == 0 && i < f)
		{
			f = i;
		}
		if (x == 0 && i < s)
		{
			s = i;
		}
	}

	int** M6 = new int* [f];
	for (int i = 0; i < f; i++)
	{
		M6[i] = new int[s];
		for (int j = 0; j < s; j++)
			M6[i][j] = M5[i][j];
	}

	///////////////////////////////////////////////////////////////////////////////
	///////////////////Вывод результирующей матрицы////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////
	cout << endl << "Результирующая матрица" << endl << endl;
	printMatrix(M6, f, s);

	system("pause");

	///////////////////////////////////////////////////////////////////////////////
	/////////////////////Очистка динамической памяти///////////////////////////////
	///////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < n1; i++)
		delete[] M1[i];
	for (int i = 0; i < n2; i++)
		delete[] M2[i];
	for (int i = 0; i < l; i++)
	{
		delete[] M3[i];
		delete[] M4[i];
		delete[] M5[i];
	}
	for (int i = 0; i < f; i++)
		delete[] M6[i];
	for (int i = 0; i < l / 2; i++)
	{
		delete[] mat1[i];
		delete[] mat2[i];
		delete[] mat3[i];
		delete[] mat4[i];
		delete[] mat5[i];
		delete[] mat6[i];
		delete[] mat7[i];
		delete[] mat8[i];
		delete[] mat9[i];
		delete[] mat10[i];
		delete[] mat11[i];
		delete[] mat12[i];
		delete[] p1[i];
		delete[] p2[i];
		delete[] p3[i];
		delete[] p4[i];
		delete[] p5[i];
		delete[] p6[i];
		delete[] p7[i];
	}
	delete[] M1, M2, M3, M4, M5, M6;
	delete[] mat1, mat2, mat3, mat4, mat5, mat6, mat7, mat8, mat9, mat10, mat11, mat12;
	delete[] p1, p2, p3, p4, p5, p6, p7;
}
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
//#define SIZE 5
//
//using namespace std;
//
//struct variety
//{
//	int arr[SIZE]; //Вершины входящие в подмножество
//	int quantity;  //Их количество
//};
//
//bool check(variety line, int graf[SIZE][SIZE])
//{
//	int count = 0, k = 0;
//	for (int i = 0; i < line.quantity - 1; i++)
//		for (int c = i + 1; c < line.quantity; c++)
//			for (int j = 0; j < SIZE; j++)
//			{
//				if ((((graf[line.arr[i]][j] == 0) && (graf[line.arr[c]][j] = 1)) || ((graf[line.arr[i]][j] == 1) && (graf[line.arr[c]][j] = 0)) || ((graf[line.arr[i]][j] == 1) && (graf[line.arr[c]][j] = 1)))
//					|| (((graf[line.arr[i]][j] == 0) && (graf[line.arr[c]][j] == 0)) && ((graf[j][line.arr[i]] == 0) && (graf[j][line.arr[c]] == 0))))
//					count++;
//			}
//	if (count == SIZE) return true;
//	else return false;
//}
//
//
//int Max(int graf[SIZE][SIZE], variety line)
//{
//	int max = 0, count = 0, top = 0, help = 0;
//
//	for (int j = 0; j < SIZE; j++)
//	{
//		for (int i = 0; i < SIZE; i++)
//		{
//			count = count + graf[i][j];
//		}
//
//		if ((count >= max) && (line.quantity == 0))
//		{
//			max = count;
//			top = j;
//		}
//
//		if ((count >= max) && (line.quantity != 0))
//		{
//			help = 0;
//			for (int c = 0; c < line.quantity; c++)
//				if (line.arr[c] == j) help++;
//			if (help > 0)
//			{
//				max = max;
//				top = top;
//			}
//			else if (help == 0)
//			{
//				max = count;
//				top = j;
//			}
//		}
//		count = 0;
//	}
//	return top;
//}
//
//void main()
//{
//	system("chcp 1251");
//	system("cls");
//
//	variety line;
//	line.quantity = 0;
//
//	int graf[SIZE][SIZE];
//	int temp, top, count = 0;
//
//	bool flag = true;
//
//	cout << "Введите значение ребра (0 - ребро есть, 1 - ребра нет) " << endl;
//	for (int i = 0; i < SIZE; i++)
//	{
//		graf[i][i] = 0;
//		for (int j = i + 1; j < SIZE; j++) {
//			cout << i + 1 << " - " << j + 1 << " :";
//			cin >> temp;
//
//			graf[i][j] = temp;
//			graf[j][i] = temp;
//		}
//	}
//
//	// Вывод матрицы связей
//	for (int i = 0; i < SIZE; i++)
//	{
//		for (int j = 0; j < SIZE; j++)
//			cout << graf[i][j] << "  ";
//		cout << endl;
//	}
//
//	top = Max(graf, line);
//
//	line.arr[line.quantity] = top;
//	line.quantity++;
//
//	for (int i = 0; i < SIZE; i++)
//	{
//		if ((graf[i][top] == 1) || (i == top))
//			count++;
//	}
//
//	if (count != SIZE)
//	{
//		while (flag == true)
//		{
//			top = Max(graf, line);
//
//			line.arr[line.quantity] = top;
//			line.quantity++;
//
//			if (check(line, graf)) flag = false;
//		}
//	}
//
//	cout << "Доминирующее множество содержит вершины: " << endl;
//	for (int i = 0; i < line.quantity; i++)
//		cout << line.arr[i] + 1 << "  ";
//
//	cout << endl;
//
//	system("pause");
//}
//#include <iostream>
//using namespace std;
//
//void reset_boxes(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//		arr[i] = 0;
//}
//void Sort(int* arr, int n)
//{
//	int temp = 0;
//	bool ex = false;
//	while (!ex)
//	{
//		ex = true;
//		for (int i = 0; i < (n - 1); i++)
//			if (arr[i] < arr[i + 1])
//			{
//				temp = arr[i];
//				arr[i] = arr[i + 1];
//				arr[i + 1] = temp;
//				ex = false;
//			}
//	}
//}
//int main()
//{
//	setlocale(LC_ALL, "rus");
//	cout << "Введите кол-во ящиков: ";
//	int nbox;
//	cin >> nbox;
//	int* box = new int[nbox];
//	reset_boxes(box, nbox);
//	cout << "Введите объем ящиков: ";
//	int size_box;
//	cin >> size_box;
//	cout << "Введите кол-во элементов: ";
//	int nel;
//	cin >> nel;
//	int* el = new int[nel];
//	for (int i = 0; i < nel; i++)
//	{
//		cout << "Введите элемент " << i + 1 << " : ";
//		cin >> el[i];
//	}
//	Sort(el, nel);
//	int sum_el = 0;
//	for (int i = 0; i < nel; i++)
//	{
//		sum_el = sum_el + el[i];
//	}
//	cout << endl;
//	bool flag = true;
//	if (el[0] > size_box)
//	{
//		cout << "Ошибка. Некоторые элементы по одиночке не могут влезть в коробку!"
//			<< endl;
//		flag = false;
//	}
//	if (sum_el > nbox * size_box)
//	{
//		cout << "Ошибка. Общая сумма элементов больше свободного места в коробках!"
//			<< endl;
//		flag = false;
//	}
//	if (flag)
//	{
//		for (int i = 0; i < nel; i++)
//		{
//			for (int j = 0; j < nbox; j++)
//			{
//				if ((size_box - box[j]) >= el[i])
//				{
//					box[j] = box[j] + el[i];
//					cout << "Добавили " << el[i] << " в ящик " << j + 1 << endl;
//					break;
//				}
//			}
//		}
//	}
//	if (flag)
//	{
//		cout << "\n\nПеред Вами " << nbox << " ящиков, где в каждом соответсвенно написан заполненный объём\n";
//		for (int j = 0; j < nbox; j++)
//			cout << box[j] << " ";
//		cout << "\n";
//	}
//	system("pause");
//	return 0;
//}

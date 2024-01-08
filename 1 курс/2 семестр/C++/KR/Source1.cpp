#include <iostream>
#include <ctime>
using namespace std;

int find_size(int* arr, int sz, int ui) {
	int q = 0;
	for (int i = 0; i < sz; i++) {
		if (*(arr + i) == ui) {
			q++;
		}
	}
	return q;
}

int* find_num(int* arr, int* ind, int* ind_sz, int ui, int sz) {
	int temp = find_size(arr, sz, ui);
	*ind_sz = temp;

	ind = new int[*ind_sz];
	int q = 0;
	for (int i = 0; i < sz; i++) {
		if (*(arr + i) == ui) {
			*(ind + q) = i;
			q++;
		}
	}
	return ind;
}

void arr_init(int* array, int size) {
	for (int i = 0; i < size; i++) {
		*(array + i) = rand() % 10;
		cout <<* (array + i) << " ";
	}
	cout << endl;
}


int main() 
{
	setlocale(LC_ALL, "Russian");
	srand(time(nullptr));
	int arr_size, user_input;
	int* arr_ptr, * indexes, * index_size;
	index_size = new int[1];
	cout << "¬ведите размер массива: " << endl;
	cin >> arr_size;
	arr_ptr = new int[arr_size];
	cout << endl << "»значальна€ матрица: " << endl;
	arr_init(arr_ptr, arr_size);
	cout << "¬ведите число, которое хотите найти: " << endl;
	cin >> user_input;
	int* indexes;
	indexes = find_num(arr_ptr, indexes, index_size, user_input, arr_size);
	system("pause");
	return 0;
}
#include <omp.h>
#include <iostream>
#include <mutex>
#include <ctime>
using namespace std;
const int NMAX = 2000;
void main()
{
    setlocale(LC_ALL, "RUS");
    int i, j, k, count;
    int proiz, binproiz;
    int** a = new int* [NMAX];
    for (i = 0; i < NMAX; i++)
        a[i] = new int[NMAX];
    cout << "Матрица: " << endl;
    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX; j++) {
            a[i][j] = 1 + rand() % 5;
            //cout << a[i][j] << " ";
        }
        //cout << endl;
    }
    // инициализация данных
    unsigned int start_time = clock();
    for (i = 0; i < NMAX; i++)
    {
        count = 0;
        proiz = 0;
        for (j = 0; j < NMAX; j++) {
            for (k = j + 1; k < NMAX; k++) {
                proiz = a[i][j] * a[i][k];
                //cout << "Произведение элементов " << j << " и " << k << " строки " << i << " равна " << proiz << endl;
                while (proiz != 0) {
                    if (proiz % 2 == 1)
                        count++;
                        proiz /= 2;
                }
            }
        }
        //cout << "Cумма единиц в бинарной записи числа всех элементов строки " << i << " равна " << count << endl;
    }
    unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time);
    cout << "Время работы программы(в мс): " << search_time << endl;
}
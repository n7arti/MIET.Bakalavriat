#include <omp.h>
#include <iostream>
#include <ctime>
const int NMAX = 1700;
const int LIMIT = 1700;
void main()
{
    setlocale(LC_ALL, "RUS");
    int i, j;
    float sum;
    int** a = new int* [NMAX];
    for (i = 0; i < NMAX; i++)
        a[i] = new int[NMAX];
    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX; j++) {
            a[i][j] = 1 + rand() % 5;
        }
    }
    unsigned int start_time = clock();
#pragma omp parallel shared(a) if (NMAX>LIMIT)
    {
#pragma omp for private(i,j,sum) 
        for (i = 0; i < NMAX; i++)
        {
            sum = 0;
            for (j = 0; j < NMAX; j++)
                sum += a[i][j];
            //printf("Сумма элементов строки %d равна %f\n", i, sum);
        }
    } /* Завершение параллельного фрагмента */
    unsigned int end_time = clock();
    unsigned int search_time = (end_time - start_time);
    printf("Время работы программы(в мс): %d\n",search_time);
}

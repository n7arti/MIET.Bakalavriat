#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#include <vector>
#include "ticket.h"

#define N 100
using namespace std;
void Sort(vector<ticket> tick)
{
    system("cls");
    ticket::FromFile(tick);
    int y = 0;
    ticket buff;
    char FIO[150];
    strcpy(FIO, "");
    double t;
    int sizefio = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, size = 0;
    ticket::count--;
    if (ticket::count > 0)
    {
        for (int i = 0; i < ticket::count - 1; i++)
        {
            for (int j = i + 1; j < ticket::count; j++)
            {
                if (strcmp(tick[i].point_from, tick[j].point_from) > 0)
                {
                    buff = tick[i];
                    tick[i] = tick[j];
                    tick[j] = buff;
                }
            }
        }
        for (int i = 0; i < ticket::count; i++)
        {
            y = strlen(tick[i].Fio.get_familia());
            if (y > sizefamilia)
                sizefamilia = strlen(tick[i].Fio.get_familia());
            y = strlen(tick[i].Fio.get_imya());
            if (y > sizeimya)
                sizeimya = strlen(tick[i].Fio.get_imya());
            y = strlen(tick[i].Fio.get_otchestvo());
            if (y > sizeotchestvo)
                sizeotchestvo = strlen(tick[i].Fio.get_otchestvo());
            y = strlen(tick[i].point_from);
            if (y > sizefrom)
                sizefrom = strlen(tick[i].point_from);
            y = strlen(tick[i].point_to);
            if (y > sizeto)
                sizeto = strlen(tick[i].point_to);
        }
        if (sizefamilia + sizeimya + sizeotchestvo + 2 < 3) sizefio = 3;
        else sizefio = sizefamilia + sizeimya + sizeotchestvo + 2;
        if (sizefrom < 17) sizefrom = 17;
        if (sizeto < 14) sizeto = 14;
        size = sizefio + sizefrom + sizeto + 22;
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        cout << "|" << setw(sizefio + 2) << "ФИО|" << setw(sizefrom + 2) << "Пункт отправления|" << setw(sizeto + 2) << "Пункт прибытия|" << setw(15);
        cout << "Цена|" << endl;
        for (int i = 0; i < ticket::count; i++)
        {
            strcat(FIO, tick[i].Fio.get_familia());
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.get_imya());
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.get_otchestvo());
            for (int i = 0; i < size; i++)
                cout << "-";
            cout << endl;
            cout << "|" << setw(sizefio + 1) << FIO << "|";
            cout << setw(sizefrom + 1) << tick[i].point_from << "|" << setw(sizeto + 1) << tick[i].point_to << "|";
            cout << setw(14) << tick[i].price << "|" << endl;
            strcpy(FIO, "");

        }
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        ofstream outf("DataBase.txt");
        for (int i = 0; i < ticket::count; i++)
        {
            outf << tick[i].Fio.get_familia() << endl;
            outf << tick[i].Fio.get_imya() << endl;
            outf << tick[i].Fio.get_otchestvo() << endl;
            outf << tick[i].point_from << endl;
            outf << tick[i].point_to << endl;
            outf << tick[i].price << endl;
        }
    }
    if (ticket::count == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}

int main()
{
    setlocale(LC_ALL, "rus");
    char n1[2];
    int n = 0;
    int number = 0;
    ticket::Set_filename("DataBase.txt");
    vector<ticket> pas(N);
    pas[N - 1].FromFile(pas);
    number = pas[N-1].Get_count();
    while (n != 6)
    {
        system("cls");
        cout << "Добавить нового пассажира.......................1" << endl;
        cout << "Распечатать данные..............................2" << endl;
        cout << "Поиск билета по пункту прибытия.................3" << endl;
        cout << "Сотировать по алфавиту по пункту отправления....4" << endl;
        cout << "Удалить последний элемент.......................5" << endl;
        cout << "Выход из программы..............................6" << endl;
        cout << "Введите номер функции" << endl;
        cin >> n1;
        n = atoi(n1);
        while (cin.get() != '\n')
            ;
        switch (n)
        {
        case 1: 
            pas.at(number).InitTicket(pas);
            number++;
            break;
        case 2:
            pas[N-1].Print(pas);
            break;
        case 3:
            pas[N-1].Find(pas);
            break;
        case 4:
            Sort(pas);
            break;
        case 5:
            pas[N-1].Delete(pas);
        }
    }
}
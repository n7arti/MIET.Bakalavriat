#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
typedef struct train
{
    char* fio;
    char* point_from;
    char* point_to;
    double price;
}
train;
int FromFile(int k, train* mas)
{
    char* buff = new char[52];
    ifstream fs("DataBase.txt");
    if (fs)
    {
        while (!fs.eof())
        {
            fs.getline(buff, 1024, '\n');
            if ((k + 1) % 4 == 1)
            {
                mas[k / 4].fio = (char*)calloc(strlen(buff) + 1, sizeof(char));
                strcpy(mas[k / 4].fio, buff);
            }
            if ((k + 1) % 4 == 2) 
            {
                mas[k / 4].point_from = (char*)calloc(strlen(buff) + 1, sizeof(char));
                strcpy(mas[k / 4].point_from, buff);
            }
            if ((k + 1) % 4 == 3)
            {
                mas[k / 4].point_to = (char*)calloc(strlen(buff) + 1, sizeof(char));
                strcpy(mas[k / 4].point_to, buff);
            }
            if ((k + 1) % 4 == 0)
            {
                mas[k / 4 ].price = atoi(buff);
            }
            k++;
        }
        fs.close();
        delete[] buff;
        k /= 4;
    }
    return k;

}
void AddInfo(train* mas, int k)
{
    char buff[50];
    char* x = new char[50];
    int g = 0;
    system("cls");
    getchar();
    cout << "Введите ФИО: " << endl;
    fgets(buff, 50, stdin);
    buff[strlen(buff) - 1] = '\0';
    mas[k].fio = (char*)calloc(strlen(buff) + 1, sizeof(char));
    strcpy(mas[k].fio, buff);
    cout << "Введите пункт отправления: " << endl;
    fgets(buff, 50, stdin);
    buff[strlen(buff) - 1] = '\0';
    mas[k].point_from = (char*)calloc(strlen(buff) + 1, sizeof(char));
    strcpy(mas[k].point_from, buff);
    cout << "Введите пункт прибытия: " << endl;
    fgets(buff, 50, stdin);
    buff[strlen(buff) - 1] = '\0';
    mas[k].point_to = (char*)calloc(strlen(buff) + 1, sizeof(char));
    strcpy(mas[k].point_to, buff);
    cout << "Введите цену: " << endl;
    cin >> x;
    while (g == 0)
    {
        if (isdigit(*x))
        {
            mas[k].price = atoi(x);
            g++;
        }
        else
        {
            cout << "Не корректный ввод!" << endl;
            cin >> x;
        }
    }
    ofstream outf("DataBase.txt", ios::app);
    outf << mas[k].fio << endl;
    outf << mas[k].point_from << endl;
    outf << mas[k].point_to << endl;
    outf << mas[k].price << endl;
}
void Print(train* mas, int k)
{
    system("cls");
    int sizefio = 0, sizefrom = 0, sizeto = 0, sizeprice =0;
    if (k > 0)
    {
        for (int i = 0; i < k; i++)
        {
            if (strlen(mas[i].fio) > sizefio)
                sizefio = strlen(mas[i].fio);
            if (strlen(mas[i].point_from) > sizefrom)
                sizefrom = strlen(mas[i].point_from);
            if (strlen(mas[i].point_to) > sizeto)
                sizeto = strlen(mas[i].point_to);
        }
        if (sizefio < 3) sizefio = 3;
        if (sizefrom < 17) sizefrom = 17;
        if (sizeto < 14) sizeto = 14;
        cout << "|" << setw(sizefio + 2) << "ФИО|" << setw(sizefrom + 2) << "Пункт отправления|" << setw(sizeto + 2) << "Пункт прибытия|" << setw(15) << "Цена|" << endl;
        for (int i = 0; i < k; i++)
        {
            cout << "________________________________________________________________________________" << endl;
            cout <<"|"<< setw(sizefio+1) <<( mas[i].fio) << "|" << setw(sizefrom+1) << mas[i].point_from << "|" << setw(sizeto+1) << mas[i].point_to << "|" << setw(14) << mas[i].price << "|" << endl;
            cout << "________________________________________________________________________________" << endl;
        }
    }
    if (k == 0)
        cout << "Данных не существует" << endl;
    system("pause");

}
void find(train* mas, int k)
{
    system("cls");
    char buff[50];
    if (k > 0)
    {
        getchar();
        cout << "Введите ФИО пассажира" << endl;
        fgets(buff, 50, stdin);
        buff[strlen(buff) - 1] = '\0';
        int m = 0;
        for (int i = 0; i < k; i++)
        {
            if (!abs(strcmp(buff, mas[i].fio)))
            {
                cout << "ФИО пассажира: " << mas[i].fio << endl;
                cout << "Пункт отправления: " << mas[i].point_from << endl;
                cout << "Пункт прибытия: " << mas[i].point_to << endl;
                cout << "Цена: " << mas[i].price << endl;
                cout << endl;
                m++;
            }
        }
        if (m == 0)
            cout << "Данные по пассажиру отсутсвуют" << endl;
    }
    if (k == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void filtr(train* mas, int k)
{
    system("cls");
    double cena = 0;
    if (k > 0)
    {
        cout << "Введите цену" << endl;
        cin >> cena;
        int m = 0;
        for (int i = 0; i < k; i++)
        {
            if (mas[i].price > cena)
            {
                cout << "ФИО пассажира: " << mas[i].fio << endl;
                cout << "Пункт отправления: " << mas[i].point_from << endl;
                cout << "Пункт прибытия: " << mas[i].point_to << endl;
                cout << "Цена: " << mas[i].price << endl;
                cout << endl;
                m++;
            }
        }
        if (m == 0)
            cout << "Билеты по цене более указанной отсутствуют" << endl;
    }
    if (k == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void sortirovka(train* mas, int k)
{
    system("cls");
    char bufffrom[50];
    char buffto[50];
    char bufffio[50];
    double t;
    int sizefio = 0, sizefrom = 0, sizeto = 0, sizeprice = 0;
    if (k > 0)
    {
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (strcmp(mas[i].point_from, mas[j].point_from) > 0)
                {
                    strcpy(bufffrom, mas[i].point_from);
                    strcpy(mas[i].point_from, mas[j].point_from);
                    strcpy(mas[j].point_from, bufffrom);

                    strcpy(buffto, mas[i].point_to);
                    strcpy(mas[i].point_to, mas[j].point_to);
                    strcpy(mas[j].point_to, buffto);

                    strcpy(bufffio, mas[i].fio);
                    strcpy(mas[i].fio, mas[j].fio);
                    strcpy(mas[j].fio, bufffio);

                    t = mas[i].price;
                    mas[i].price = mas[j].price;
                    mas[j].price = t;
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (strlen(mas[i].fio) > sizefio)
                sizefio = strlen(mas[i].fio);
            if (strlen(mas[i].point_from) > sizefrom)
                sizefrom = strlen(mas[i].point_from);
            if (strlen(mas[i].point_to) > sizeto)
                sizeto = strlen(mas[i].point_to);
        }
        if (sizefio < 3) sizefio = 3;
        if (sizefrom < 17) sizefrom = 17;
        if (sizeto < 14) sizeto = 14;
        cout << "|" << setw(sizefio + 2) << "ФИО|" << setw(sizefrom + 2) << "Пункт отправления|" << setw(sizeto + 2) << "Пункт прибытия|" << setw(15) << "Цена|" << endl;
        for (int i = 0; i < k; i++)
        {
            cout << "________________________________________________________________________________" << endl;
            cout << "|" << setw(sizefio + 1) << mas[i].fio << "|" << setw(sizefrom + 1) << mas[i].point_from << "|" << setw(sizeto + 1) << mas[i].point_to << "|" << setw(14) << mas[i].price << "|" << endl;
            cout << "________________________________________________________________________________" << endl;
        }
    }
    if (k == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
int main()
{
    setlocale(LC_ALL, "rus");
    int n = 0;
    int number = 0;
    train* pas = new train[100];
    number = FromFile(number, pas);
    while (n != 6)
    {
        system("cls");
        cout << "Добавить нового пассажира.......................1" << endl;
        cout << "Распечатать данные..............................2" << endl;
        cout << "Поиск билета по ФИО пассажира...................3" << endl;
        cout << "Фильтр по цене..................................4" << endl;
        cout << "Сотировать по алфавиту по пункту отправления....5" << endl;
        cout << "Выход из программы..............................6" << endl;
        cout << "Введите номер функции" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            AddInfo(pas, number);
            number++;
            break;
        case 2:
            Print(pas, number);
            break;
        case 3:
            find(pas, number);
            break;
        case 4:
            filtr(pas, number);
            break;
        case 5:
            sortirovka(pas, number);
            break;
        }
    }
    delete[] pas;
}
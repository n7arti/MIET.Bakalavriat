#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ticket.h"
#include "fio.h"
using namespace std;
#define N 100
int ticket::count;
string ticket::filename;
ticket::ticket()
{
    point_from = new char[50];
    strcpy(point_from, " ");
    point_to = new char[50];
    strcpy(point_to, " ");
    price = 0;
    count++;
}
ticket::~ticket()
{
    delete[] point_from;
    delete[] point_to;
    count--;
}
void ticket::Set_point_from(char* point_from_v)
{
    if (point_from != nullptr)
        delete[] point_from;
    point_from = new char[strlen(point_from_v) + 1];
    strcpy(point_from, point_from_v);
}
void ticket::Set_point_to(char* point_to_v)
{
    if (point_to != nullptr)
        delete[] point_to;
    point_to = new char[strlen(point_to_v) + 1];
    strcpy(point_to, point_to_v);
}
bool operator==(const ticket& tick1, const ticket& tick2)
{
    return ((tick1.Fio == tick2.Fio) && !abs(strcmp(tick1.point_to, tick2.point_to)) && !abs(strcmp(tick1.point_from, tick2.point_from)));
}
ticket& ticket::operator = (const ticket& ticket_v)
{
    if (Fio.familia != nullptr)
        delete[] Fio.familia;
    if (Fio.imya != nullptr)
        delete[] Fio.imya;
    if (Fio.otchestvo != nullptr)
        delete[] Fio.otchestvo;
    if (point_from != nullptr)
        delete[] point_from;
    if (point_to != nullptr)
        delete[] point_to;

    Fio.familia = new char[strlen(ticket_v.Fio.familia)+1];
    Fio.imya = new char[strlen(ticket_v.Fio.imya) + 1];
    Fio.otchestvo = new char[strlen(ticket_v.Fio.otchestvo) + 1];
    point_from = new char[strlen(ticket_v.point_from) + 1];
    point_to = new char[strlen(ticket_v.point_to) + 1];

    strcpy(Fio.familia, ticket_v.Fio.familia);
    strcpy(Fio.imya, ticket_v.Fio.imya);
    strcpy(Fio.otchestvo, ticket_v.Fio.otchestvo);
    strcpy(point_from, ticket_v.point_from);
    strcpy(point_to, ticket_v.point_to);
    price = ticket_v.price;
    return *this;
}
istream& operator>> (istream& in, ticket& Ticket)
{
    int g = 0;
    char* buff = new char[50];
    cout << "Введите фамилию: ";
    in >> buff;
    Ticket.Fio.set_familia(buff);
    cout << "Введите имя: ";
    in >> buff;
    Ticket.Fio.set_imya(buff);
    cout << "Введите отчество: ";
    in >> buff;
    Ticket.Fio.set_otchestvo(buff);
    cout << "Введите пункт отправления: ";
    in >> Ticket.point_from;
    cout << "Введите пункт отправления: ";
    in >> Ticket.point_to;
    

    return in;
}
void ticket::FromFile(ticket* tick)
{

    int k = 0;
    int y = 0;
    char* buff = new char[52];
    ofstream file(filename.c_str(), ios::app);
    file << "";
    file.close();
    ifstream fs;
    fs.open(filename.c_str());
    if (!fs)
        count = 0;
    else if (fs)
    {
        while (!fs.eof())
        {
            fs.getline(buff, 53, '\n');
            y = strlen(buff) + 1;
            tick[k].Fio.familia = new char[y];
            strcpy(tick[k].Fio.familia, buff);

            fs.getline(buff, 53, '\n');
            tick[k].Fio.imya = new char[y];
            strcpy(tick[k].Fio.imya, buff);

            fs.getline(buff, 53, '\n');
            tick[k].Fio.otchestvo = new char[y];
            strcpy(tick[k].Fio.otchestvo, buff);

            fs.getline(buff, 53, '\n');
            tick[k].point_from = new char[y];
            strcpy(tick[k].point_from, buff);

            fs.getline(buff, 53, '\n');
            tick[k].point_to = new char[y];
            strcpy(tick[k].point_to, buff);

            fs.getline(buff, 53, '\n');
            tick[k].price = atoi(buff);
            k++;
        }
        fs.close();
        count = k-1;
    }
    delete[] buff;
}
void ticket::InitTicket()
{
    char* buff = new char[50];
    int g = 0;
    system("cls");
    cin >> *this;
    cout << "Введите цену: ";
    cin >> buff;
    while (1)
    {
        g = 0;
        for (int i = 0; i < strlen(buff); i++)
        {
            if (!isdigit(buff[i]))
            {
                cout << "Не корректный ввод!" << endl;
                cin >> buff;
                g++;
            }
        }
        if (g == 0)
        {
            price = atoi(buff);
            break;
        }
    }
    count++;
  
}
void ticket::ToFile()
{
    ofstream outf(filename.c_str(), ios::app);
    outf << Fio.familia << endl;
    outf << Fio.imya << endl;
    outf << Fio.otchestvo << endl;
    outf << point_from << endl;
    outf << point_to << endl;
    outf << price << endl;
    cout << endl;
    cout << "Объект успешно добавлен" << endl;
    cout << endl;
    system("pause");
}
void ticket::Print(ticket* tick)
{
    system("cls");
    FromFile(tick);
    int y = 0;
    char FIO[150];
    strcpy(FIO, "");
    int sizefio = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, size = 0;
    if (count > 0)
    {
        for (int i = 0; i < count; i++)
        {
            y = strlen(tick[i].Fio.familia);
            if (y > sizefamilia)
                sizefamilia = strlen(tick[i].Fio.familia);
            y = strlen(tick[i].Fio.imya);
            if (y > sizeimya)
                sizeimya = strlen(tick[i].Fio.imya);
            y = strlen(tick[i].Fio.otchestvo);
            if (y > sizeotchestvo)
                sizeotchestvo = strlen(tick[i].Fio.otchestvo);
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
        for (int i = 0; i < count; i++)
        {
            strcat(FIO, tick[i].Fio.familia);
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.imya);
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.otchestvo);
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
    }
    if (count == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void ticket::Find(ticket* tick)
{
    system("cls");
    char buff[50];
    ticket* mas = new ticket [N];
    system("cls");
    FromFile(tick);
    if (count > 0)
    {
        cout << "Введите пункт прибытия: " << endl;
        fgets(buff, 50, stdin);
        buff[strlen(buff) - 1] = '\0';
        int m = 0;
        cout << endl;
        for (int i = 0; i < count; i++)
        {

            if (!abs(strcmp(buff, tick[i].point_to)))
            {
                cout << "ФИО пассажира: " << tick[i].Fio.familia << " " << tick[i].Fio.imya << " " << tick[i].Fio.otchestvo << endl;
                cout << "Пункт отправления: " << tick[i].point_from << endl;
                cout << "Пункт прибытия: " << tick[i].point_to << endl;
                cout << "Цена: " << tick[i].price << endl;
                cout << endl;
                mas[m] = tick[i];
                m++;
            }
        }
        if (m == 0)
            cout << "Данные по пассажиру отсутсвуют" << endl;
    }
    if (count == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void ticket::ToString()
{
    cout << "ФИО пассажира: " << Fio.familia << " " << Fio.imya << " " << Fio.otchestvo << endl;
    cout << "Пункт отправления: " << point_from << endl;
    cout << "Пункт прибытия: " << point_to << endl;
    cout << "Цена: " << price << endl;
    cout << endl;
}
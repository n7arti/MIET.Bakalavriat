#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "bus.h"
#include "ticket.h"
#include "fio.h"
using namespace std;

int bus::countb;
string bus::filenameb;
bus::bus()
{
	regnumb = 0;
	numbbus = 0;
	numbplace = 0;
	countb++;
}
void bus::AddInfoB(ticket* tick)
{
    int h = 0;
    int g = 0;
    char* ans = new char[4];
    char* buff = new char[20];
    while (1)
    {
        system("cls");
        ticket t;
        cin >> t;
        for (int i = 0; i < ticket::Get_count(); i++)
        {
            if (tick[i] == t)
            {
                system("cls");
                cout << "Пассажир найден!" << endl;
                cout << "Введите номер автобус: ";
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
                        numbbus = atoi(buff);
                        break;
                    }
                }
                cout << "Введите номер места: ";
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
                        numbplace = atoi(buff);
                        break;
                    }
                }
                cout << "Введите дату поездки: " << endl;
                cin >> time;
                regnumb = i;
                while (cin.get() != '\n')
                    ;
                regnumb = i;
                countb++;
                h++;
                break;
            }
        }
        if (h == 0)
        {
            system("cls");
            cout << "Пассажир не найден. Попробовать снова?" << endl;
            cout << "- Yes" << endl;
            cout << "- No" << endl;
            cin >> ans;
            while (1)
            {
                if (!abs(strcmp(ans, "No")) || !abs(strcmp(ans, "no")) || !abs(strcmp(ans, "Yes")) || !abs(strcmp(ans, "yes")))
                    break;
                else
                {
                    cout << "Не корректный ввод!" << endl;
                    cin >> ans;
                }
            }
            if (!abs(strcmp(ans, "No")) || !abs(strcmp(ans, "no")))
                break;
        }
        if (h > 0)
        {
            ToFile();
            break;
        }
    }
}
void bus::ToFile()
{
    ofstream outf(filenameb.c_str(), ios::app);
    outf << regnumb << endl;
    outf << numbbus << endl;
    outf << numbplace << endl;
    outf << time.get_day() << endl;
    outf << time.get_month() << endl;
    outf << time.get_year() << endl;;
    cout << endl;
    cout << "Объект успешно добавлен" << endl;
    cout << endl;
    system("pause");
}
void bus::FromFile(bus* b)
{

    int k = 0;
    char* buff = new char[52];
    ifstream fs(filenameb.c_str());
    if (!fs)
        countb = 0;
    else if (fs)
    {
        while (!fs.eof())
        {
            fs.getline(buff, 53, '\n');
            b[k].regnumb = atoi(buff);

            fs.getline(buff, 53, '\n');
            b[k].numbbus = atoi(buff);

            fs.getline(buff, 53, '\n');
            b[k].numbplace = atoi(buff);

            fs.getline(buff, 53, '\n');
            b[k].time.set_day(atoi(buff));

            fs.getline(buff, 53, '\n');
            b[k].time.set_month(atoi(buff));

            fs.getline(buff, 53, '\n');
            b[k].time.set_year(atoi(buff));
            k++;
        }
        fs.close();
        countb = k-1;
    }
    
    delete[] buff;
}
void bus::Print(ticket* tick, bus* b)
{
    system("cls");
    ticket::FromFile(tick);
    FromFile(b);
    int y = 0;
    char FIO[150];
    char* DATA = new char[15];
    strcpy(FIO, "");
    strcpy(DATA, "");
    int sizefio = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, sizenumbrailcar = 0, sizenumbplace = 0, numbdate = 0, size = 0;
    if ((Get_count() > 0) && (countb > 0))
    {
        for (int i = 0; i < Get_count(); i++)
        {
            for (int j = 0; j < countb; j++)
            {
                if (i == b[j].regnumb)
                {
                    y = strlen(tick[i].Get_Fio().get_familia());
                    if (y > sizefamilia)
                        sizefamilia = strlen(tick[i].Get_Fio().get_familia());
                    y = strlen(tick[i].Get_Fio().get_imya());
                    if (y > sizeimya)
                        sizeimya = strlen(tick[i].Get_Fio().get_imya());
                    y = strlen(tick[i].Get_Fio().get_otchestvo());
                    if (y > sizeotchestvo)
                        sizeotchestvo = strlen(tick[i].Get_Fio().get_otchestvo());
                    y = strlen(tick[i].Get_point_from());
                    if (y > sizefrom)
                        sizefrom = strlen(tick[i].Get_point_from());
                    y = strlen(tick[i].Get_point_to());
                    if (y > sizeto)
                        sizeto = strlen(tick[i].Get_point_to());
                }
            }
        }
        if (sizefamilia + sizeimya + sizeotchestvo + 2 < 3) sizefio = 3;
        else sizefio = sizefamilia + sizeimya + sizeotchestvo + 2;
        if (sizefrom < 17) sizefrom = 17;
        if (sizeto < 14) sizeto = 14;
        size = sizefio + sizefrom + sizeto + 22 + 15 + 14 + 15;
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        cout << "|" << setw(sizefio + 2) << "ФИО|" << setw(sizefrom + 2) << "Пункт отправления|" << setw(sizeto + 2) << "Пункт прибытия|" << setw(15);
        cout << "Цена|" << setw(16) << "Номер автобуса|" << setw(15) << "Номер места|" << setw(13) << "Дата|" << endl;
        for (int i = 0; i < Get_count(); i++)
        {
            for (int j = 0; j < countb; j++)
            {
                if (i == b[j].regnumb)
                {
                    strcpy(FIO, tick[i].Get_Fio().get_familia());
                    strcat(FIO, " ");
                    strcat(FIO, tick[i].Get_Fio().get_imya());
                    strcat(FIO, " ");
                    strcat(FIO, tick[i].Get_Fio().get_otchestvo());

                    for (int i = 0; i < size; i++)
                        cout << "-";
                    cout << endl;
                    cout << "|" << setw(sizefio + 1) << FIO << "|";
                    cout << setw(sizefrom + 1) << tick[i].Get_point_from() << "|" << setw(sizeto + 1) << tick[i].Get_point_to() << "|";
                    cout << setw(14) << tick[i].Get_price() << "|" << setw(15) << b[j].numbbus << "|" << setw(14) << b[j].numbplace << "|";
                    cout << setw(5) << b[j].time.get_day() << "." << b[j].time.get_month() << "." << b[j].time.get_year() << "|" << endl;
                    strcpy(FIO, "");
                }
            }

        }
        for (int i = 0; i < size; i++)
            cout << "-";
        cout << endl;
        if (countb == 0)
            cout << "Данных не существует" << endl;
        system("pause");
    }
}
void bus::ToString()
{
    cout << "Номер автобуса: " << numbbus << endl;
    cout << "Номер места: " << numbplace << endl;
    cout << "Дата поездки: " << time.get_day() << "." << time.get_month() << "." << time.get_year() << endl;
}
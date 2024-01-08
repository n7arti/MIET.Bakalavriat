#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "train.h"
#include "ticket.h"
#include "fio.h"

using namespace std;
int train::counttr;
string train::filenametr;
train::train()
{
	regnumb = 0;
	numbplace = 0;
	numbrailcar = 0;
	counttr++;
}
void train::AddInfoTr(ticket* tick)
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
    
        for (int i = 0; i < Get_count(); i++)
        {
            if (tick[i] == t)
            {
                system("cls");
                cout << "Пассажир найден!" << endl;
                cout << "Введите номер вагона: ";
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
                        numbrailcar = atoi(buff);
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
                while (cin.get() != '\n')
                    ;
                regnumb = i;
                counttr++;
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
void train::ToFile()
{
    ofstream outf(filenametr.c_str(), ios::app);
    outf << regnumb << endl;
    outf << numbrailcar << endl;
    outf << numbplace << endl;
    outf << time.get_day() << endl; 
    outf << time.get_month() << endl;
    outf << time.get_year() << endl;;
    cout << endl;
    cout << "Объект успешно добавлен" << endl;
    cout << endl;
    system("pause");
}
void train::FromFile(train* tr)
{

    int k = 0;
    char* buff = new char[52];
    ifstream fs(filenametr.c_str());
    if (!fs)
        counttr = 0;
    else if (fs)
    {
        while (!fs.eof())
        {
            fs.getline(buff, 53, '\n');
            tr[k].regnumb = atoi(buff);

            fs.getline(buff, 53, '\n');
            tr[k].numbrailcar = atoi(buff);

            fs.getline(buff, 53, '\n');
            tr[k].numbplace = atoi(buff);

            fs.getline(buff, 53, '\n');
            tr[k].time.set_day(atoi(buff));

            fs.getline(buff, 53, '\n');
            tr[k].time.set_month(atoi(buff));

            fs.getline(buff, 53, '\n');
            tr[k].time.set_year(atoi(buff));
            k++;
        }
        fs.close();
        counttr = k-1;
    }
    delete[] buff;
}
void train::Print(ticket* tick, train* tr)
{
    system("cls");
    ticket::FromFile(tick);
    FromFile(tr);
    int y = 0;
    char FIO[150];
    char* DATA = new char[15];
    strcpy(FIO, "");
    strcpy(DATA, "");
    int sizefio = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, sizenumbrailcar = 0, sizenumbplace = 0, numbdate = 0, size = 0;
    if ((Get_count() > 0) && (counttr > 0))
    {
        for (int i = 0; i < Get_count(); i++)
        {
            for (int j = 0; j < counttr; j++)
            {
                if (i == tr[j].regnumb)
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
            size = sizefio + sizefrom + sizeto + 22 + 14 + 14 + 15;
            for (int i = 0; i < size; i++)
                cout << "-";
            cout << endl;
            cout << "|" << setw(sizefio + 2) << "ФИО|" << setw(sizefrom + 2) << "Пункт отправления|" << setw(sizeto + 2) << "Пункт прибытия|" << setw(15);
            cout << "Цена|" << setw(15) << "Номер вагона|" << setw(15) << "Номер места|" << setw(13) << "Дата|" << endl;
            for (int i = 0; i < Get_count(); i++)
            {
                for (int j = 0; j < counttr; j++)
                {
                    if (i == tr[j].regnumb)
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
                        cout << setw(14) << tick[i].Get_price() << "|" << setw(14) << tr[j].numbrailcar << "|" << setw(14) << tr[j].numbplace << "|";
                        cout << setw(5) << tr[j].time.get_day() << "." << tr[j].time.get_month() << "."  << tr[j].time.get_year() << "|" << endl;
                        strcpy(FIO, "");
                    }
                }

            }
            for (int i = 0; i < size; i++)
                cout << "-";
            cout << endl;
        if (counttr == 0)
            cout << "Данных не существует" << endl;
        system("pause");
    }
}
void train::ToString()
{
    cout << "Номер вагона: " << numbrailcar << endl;
    cout << "Номер места: " << numbplace << endl;
    cout << "Дата поездки: " << time.get_day() << "." << time.get_month() << "." << time.get_year() << endl;
}
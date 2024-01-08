#include <iostream>
#include "date.h"
using namespace std;

date::date()
{
    day = 0;
    month = 0;
    year = 0;
}
date& date::operator = (const date& date_v)
{

    day = date_v.day;
    month = date_v.month;
    year = date_v.year;
    return *this;
}
std::istream& operator>> (std::istream& in, date& DATE)
{
    int g = 0;
    char* buff = new char[20];
    cout << "День: ";
    in >> buff;
    while (1)
    {
        g = 0;
        if (atoi(buff) > 31 || atoi(buff) < 1)
        {
            cout << "Не корректный ввод!" << endl;
            in >> buff;
            g++;
        }
        for (int i = 0; i < strlen(buff); i++)
        {
            if (!isdigit(buff[i]))
            {
                cout << "Не корректный ввод!" << endl;
                in >> buff;
                g++;
            }
        }
        if (g == 0)
        {
            DATE.day = atoi(buff);
            break;
        }
    }
    cout << "Месяц: ";
    in >> buff;
    while (1)
    {
        g = 0;
        if (atoi(buff) > 12 || atoi(buff) < 1)
        {
            cout << "Не корректный ввод!" << endl;
            in >> buff;
            g++;
        }
        for (int i = 0; i < strlen(buff); i++)
        {
            if (!isdigit(buff[i]))
            {
                cout << "Не корректный ввод!" << endl;
                in >> buff;
                g++;
            }
        }
        if (g == 0)
        {
            DATE.month = atoi(buff);
            break;
        }
    }
    cout << "Год: ";
    in >> buff;
    while (1)
    {
        g = 0;
        if (atoi(buff) < 1)
        {
            cout << "Не корректный ввод!" << endl;
            in >> buff;
            g++;
        }
        for (int i = 0; i < strlen(buff); i++)
        {
            if (!isdigit(buff[i]))
            {
                cout << "Не корректный ввод!" << endl;
                in >> buff;
                g++;
            }
        }
        if (g == 0)
        {
            DATE.year = atoi(buff);
            break;
        }
    }
    return in;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#define N 80
using namespace std;
struct cinema
{
    int id;
    char* name;
    int year;
    double mark;
    
};

//Функция ввода
void addInfo(cinema* cinema, int n)
{
    char buff[N];
    for (int i = 0; i < n; i++)
    {
        cout << "Введите информацию о фильме " << i + 1 << endl;
        cout << "ID: ";
        cin >> cinema[i].id;
        cout << "Название:";
        cin >> buff;	
        cinema[i].name = new char[strlen(buff) + 1];
        strcpy(cinema[i].name, buff);	
        cout << "Год выпуска: ";
        cin >> cinema[i].year;
        cout << "Оценка: ";
        cin >> cinema[i].mark;
        cout << endl;
    }
}
//Функция вывода
void showInfo(cinema* cinema, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Информация о фильме " << i + 1 << endl;
        cout << "ID: " << cinema[i].id << endl;
        cout << "Название: " << cinema[i].name << endl;
        cout << "Год выпуска: " << cinema[i].year << endl;
        cout << "Оценка: " << cinema[i].mark << endl;
    }
}

//Функция фильтрации по году
void filtr(cinema* cinema, int n, int god)
{
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (god == cinema[i].year)
        {
            cout << "Информация о фильме " << i + 1 << endl;
            cout << "ID: " << cinema[i].id << endl;
            cout << "Название: " << cinema[i].name << endl;
            cout << "Год выпуска: " << cinema[i].year << endl;
            cout << "Оценка: " << cinema[i].mark << endl;
            t++;
        }
    }
    if (t == 0)
        cout << "Фильмов данного года не найдено." << endl;
}
//Функция подсчета средней оценки всех фильмов
void srznach(cinema* cinema, int n, double& ocenka)
{
    for (int i = 0; i < n; i++)
    {
        ocenka += cinema[i].mark;
    }
    ocenka /= n;
}
int main()
{
    setlocale(0, "Russian");
    int count;
    cout << "Введите количество фильмов: ";
    cin >> count;
    cinema* films = new cinema[count];
    // Вызов функции ввода информации
    addInfo(films, count);
    // Вызов функции вывода информации
    showInfo(films, count);
    // Вызов функции фильтрации по какому-либо признаку
    int god1 = 0;
    cout << "Введите год желаемого фильма: ";
    cin >> god1;
    filtr(films, count, god1);
    // Вызов функции подсчета
    double val=0;
    srznach(films, count, val);
    cout << "Средняя оценка всех фильмов: " << val << endl;
    return 0;
}

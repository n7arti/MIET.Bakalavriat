#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <clocale>
#include <fstream>
#include <iomanip>
#define N 100
using namespace std;
class fio
{
    char* familia;
    char* imya;
    char* otchestvo;
    friend class ticket;
public:
    fio();//конструктор
    ~fio();//деструктор
    fio(char* familia_value, char* imya_value, char* otchestvo_value);
    void define_fio();
    char* get_familia() { return familia; }
    char* get_imya() { return imya; }
    char* get_otchestvo() { return otchestvo; }

};
class ticket
{
    char* point_from;
    char* point_to;
    double price;
    static int count;
    fio Fio;
    static string filename;
public:
    ticket();
    ~ticket();
    ticket(char* Fio_familia_value, char* Fio_imya_value, char* Fio_otchestvo_value, char* point_from_value, char* point_to_value, double price_value);
    ticket& operator = (const ticket& ticket_v);
    void InitTicket();
    static void Print(ticket* tick);
    static void FromFile(ticket* tick);
    static void Find(ticket* tick);
    char* Get_point_from() { return point_from; }
    char* Get_point_to() { return point_to; }
    double Get_price() { return price; }
    int Get_count() { return count; }
    static string Get_filename() { return filename; }
    static void Set_filename(string filename_v) { filename = filename_v; }
    friend void Filtr(ticket* tick);
    friend void Sort(ticket* tick);
    friend class fio;

};
int ticket::count;
string ticket::filename;
void fio::define_fio()//добавить загрузку в файл
{
    char buff[50];
    cout << "Введите фамилию: ";
    cin >> buff;
    familia = new char[strlen(buff) + 1];
    strcpy(familia, buff);
    cout << "Введите имя: ";
    cin >> buff;
    imya = new char[strlen(buff) + 1];
    strcpy(imya, buff);
    cout << "Введите отчество: ";
    cin >> buff;
    otchestvo = new char[strlen(buff) + 1];
    strcpy(otchestvo, buff);
    ofstream outf("DataBase.txt", ios::app);
    outf << familia << endl;
    outf << imya << endl;
    outf << otchestvo << endl;
}
fio::fio()
{
    familia = new char[50];
    strcpy(familia, " ");
    imya = new char[50];
    strcpy(imya, " ");
    otchestvo = new char[50];
    strcpy(otchestvo, " ");
}
fio::~fio()
{
    delete[] familia;
    delete[] imya;
    delete[] otchestvo;
}
fio::fio(char* familia_value, char* imya_value, char* otchestvo_value)
{
    familia = familia_value;
    imya = imya_value;
    otchestvo = otchestvo_value;
}
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
ticket::ticket(char* Fio_familia_value, char* Fio_imya_value, char* Fio_otchestvo_value, char* point_from_value, char* point_to_value, double price_value)
{
    Fio.familia = Fio_familia_value;
    Fio.imya = Fio_imya_value;
    Fio.otchestvo = Fio_otchestvo_value;
    point_from = point_from_value;
    point_to = point_to_value;
    price = price_value;
}
ticket& ticket::operator = (const ticket& ticket_v)
{

    Fio.familia = new char[50];
    Fio.imya = new char[50];
    Fio.otchestvo = new char[50];
    point_from = new char[50];
    point_to = new char[50];

    Fio.familia = ticket_v.Fio.familia;
    Fio.imya = ticket_v.Fio.imya;
    Fio.otchestvo = ticket_v.Fio.otchestvo;
    point_from = ticket_v.point_from;
    point_to = ticket_v.point_to;
    price = ticket_v.price;
    return *this;
}
void ticket::FromFile(ticket* tick)
{
    int y = 0;
    int k = 0;
    char* buff = new char[52];
    /*ofstream file(filename.c_str(), ios::app);
    file << "";
    file.close();*/
    ifstream fs;
    fs.open(filename.c_str());
    if (!fs)
        cout << "warning" << endl;
    if (fs)
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
    }
    if (k == 0)
        count = k;
    else
        count = 0;
    cout << count << endl;
    delete[] buff;
}
void ticket::InitTicket()
{
    char buff[50];
    char* x = new char[50];
    int g = 0;
    int y = 0;
    system("cls");
    Fio.define_fio();
    while (cin.get() != '\n')
        ;
    cout << "Введите пункт отправления: ";
    fgets(buff, 50, stdin);
    buff[strlen(buff) - 1] = '\0';
    y = strlen(buff) + 1;
    point_from = new char[y];
    strcpy(point_from, buff);
    cout << "Введите пункт прибытия: ";
    fgets(buff, 50, stdin);
    buff[strlen(buff) - 1] = '\0';
    point_to = new char[y];
    strcpy(point_to, buff);
    cout << "Введите цену: ";
    cin >> x;
    while (g == 0)
    {
            if (isdigit(*x))
            {
                price = atoi(x);
                g++;
            }
            else
            {
                cout << "Не корректный ввод!" << endl;
                cin >> x;
            }
    }
    count++;
    ofstream outf(filename.c_str(), ios::app);
    outf << point_from << endl;
    outf << point_to << endl;
    outf << price << endl;
    cout << "Объект успешно добавлен" << endl;
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
            cout << "|" << setw(sizefio+1) << FIO << "|";
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
    FromFile(tick);
    char buff[50];
    char FIO[150];
    strcpy(FIO, "");
    if (count > 0)
    {
        cout << "Введите ФИО пассажира" << endl;;
        fgets(buff, 50, stdin);
        buff[strlen(buff) - 1] = '\0';
        int m = 0;
        cout << endl;
        for (int i = 0; i < count; i++)
        {
            strcat(FIO, tick[i].Fio.familia);
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.imya);
            strcat(FIO, " ");
            strcat(FIO, tick[i].Fio.otchestvo);
            if ((!abs(strcmp(buff, tick[i].Fio.familia))) || (!abs(strcmp(buff, tick[i].Fio.imya))) || (!abs(strcmp(buff, tick[i].Fio.otchestvo))) || (!abs(strcmp(buff, FIO))))
            {
                cout << "ФИО пассажира: " << tick[i].Fio.familia << " " << tick[i].Fio.imya << " " << tick[i].Fio.otchestvo << endl;
                cout << "Пункт отправления: " << tick[i].point_from << endl;
                cout << "Пункт прибытия: " << tick[i].point_to << endl;
                cout << "Цена: " << tick[i].price << endl;
                cout << endl;
                m++;
            }
            strcpy(FIO, "");
        }
        if (m == 0)
            cout << "Данные по пассажиру отсутсвуют" << endl;
    }
    if (count == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void Filtr(ticket* tick)
{
    system("cls");
    tick->FromFile(tick);
    double cena = 0;
    if (tick->count > 0)
    {
        cout << "Введите цену" << endl;
        cin >> cena;
        cout << endl;
        int m = 0;
        for (int i = 0; i < tick->count; i++)
        {
            if (tick[i].price > cena)
            {
                cout << "ФИО пассажира: " << tick[i].Fio.get_familia() << " " << tick[i].Fio.get_imya() << " " << tick[i].Fio.get_otchestvo() << endl;
                cout << "Пункт отправления: " << tick[i].point_from << endl;
                cout << "Пункт прибытия: " << tick[i].point_to << endl;
                cout << "Цена: " << tick[i].price << endl;
                cout << endl;
                m++;
            }
        }
        if (m == 0)
            cout << "Билеты по цене более указанной отсутствуют" << endl;
    }
    if (tick->count == 0)
        cout << "Данных не существует" << endl;
    system("pause");
}
void Sort(ticket* tick)
{
    system("cls");
    tick->FromFile(tick);
    int y = 0;
    ticket buff;
    char FIO[150];
    strcpy(FIO, "");
    double t;
    int sizefio = 0, sizefrom = 0, sizeto = 0, sizeprice = 0, sizefamilia = 0, sizeimya = 0, sizeotchestvo = 0, size = 0;
    tick->count--;
    if (tick->count > 0)
    {
        for (int i = 0; i < tick->count - 1; i++)
        {
            for (int j = i + 1; j < tick->count; j++)
            {
                if (strcmp(tick[i].point_from, tick[j].point_from) > 0)
                {
                    buff = tick[i];
                    tick[i] = tick[j];
                    tick[j] = buff;
                }
            }
        }
        for (int i = 0; i < tick->count; i++)
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
            if (y> sizefrom)
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
        for (int i = 0; i < tick->count; i++)
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
        for (int i = 0; i < tick->count; i++)
        {
            outf << tick[i].Fio.get_familia() << endl;
            outf << tick[i].Fio.get_imya() << endl;
            outf << tick[i].Fio.get_otchestvo() << endl;
            outf << tick[i].point_from << endl;
            outf << tick[i].point_to << endl;
            outf << tick[i].price << endl;
        }
    }
    if (tick->count == 0)
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
    ticket* pas = new ticket[N];
    pas[N-1].FromFile(pas);
    number = pas[N - 1].Get_count();
    while (n != 6)
    {
        //system("cls");
        cout << number << endl;
        cout << "Добавить нового пассажира.......................1" << endl;
        cout << "Распечатать данные..............................2" << endl;
        cout << "Поиск билета по ФИО пассажира...................3" << endl;
        cout << "Фильтр по цене..................................4" << endl;
        cout << "Сотировать по алфавиту по пункту отправления....5" << endl;
        cout << "Выход из программы..............................6" << endl;
        cout << "Введите номер функции" << endl;
        cin >> n1;
        n = atoi(n1);
        while (cin.get() != '\n')
            ;
        switch (n)
        {
        case 1:
            pas[number].InitTicket();
            number++;
            break;
        case 2:
            pas[N-1].Print(pas);
            break;
        case 3:
            pas[N-1].Find(pas);
            break;
        case 4:
            Filtr(pas);
            break;
        case 5:
            Sort(pas);
            break;
        }
    }
}
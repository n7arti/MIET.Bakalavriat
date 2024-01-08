#include <iostream>
using namespace std;
#define N 50
class date
{
	int day;
	int month;
	int year;
public:
	date();
	int get_day(){ return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	void set_day(int day_v) { day = day_v; }
	void set_month(int month_v) { month = month_v; }
	void set_year(int year_v) { year = year_v; }
};
class human
{
	char* surname;
	date birthday;
public:
	human();
	~human();
	human& operator=(human& human_v);
	friend ostream& operator<<(ostream& out, const human& human_v);
	friend bool operator<=(const date& d1, const date& d2);
	char* get_surname() { return surname; }
	date get_birthday() { return birthday; }

	
};
date::date()
{
	day = 0;
	month = 0;
	year = 0;
}
human::human()
{
	surname = new char[N];
}
human::~human()
{
	delete[] surname;
}
human& human::operator=(human& human_v)
{
	if (surname != nullptr)
		delete[] surname;
	surname = new char[strlen(human_v.surname) + 1];
	surname = human_v.surname;
	birthday.set_day(human_v.birthday.get_day());
	birthday.set_month(human_v.birthday.get_month());
	birthday.set_year(human_v.birthday.get_year());
}
ostream& operator<<(ostream& out, human& human_v)
{
	out << "Surname: " << human_v.get_surname() << " Birthday: " << human_v.get_birthday().get_day() << "." << human_v.get_birthday().get_month() << "." << human_v.get_birthday().get_year();
	return out;
} 
bool operator<=(date& d1, date& d2)
{
	return (d1.get_day() <= d2.get_day())&(d1.get_month() <= d2.get_month())&(d1.get_year() <= d2.get_year());
}
int main()
{
	human* H = new human[N];
	date D;
	human R;
	for (int i = 0; i < N; i++)
	{
		if (H[i].get_birthday() <= D)
		{
			R = H[i];
			cout << R;
		}
	}
}
 
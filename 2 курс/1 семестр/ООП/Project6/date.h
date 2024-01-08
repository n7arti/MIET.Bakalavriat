#pragma once
#include <iostream>
class date
{
	int day;
	int month;
	int year;
public:
	date();
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	void set_day(int day_v) { day = day_v; }
	void set_month(int month_v) { month = month_v; }
	void set_year(int year_v) { year = year_v; }
	date& operator = (const date& date_v);
	friend std::istream& operator>> (std::istream& in, date& DATE);
};
#include <iostream>
#include <cmath>
using namespace std;
void input(double &a, double &b, double &c, double &d, double &e, double &f) {
	cin >> a >> b >> c >> d >> e >> f;
}
bool allzero(double a, double b, double c, double d, double e, double f) {
	if ((a == 0) && (b == 0) && (c == 0) && (d == 0) && (e == 0) && (f == 0))
	{
		cout << '5';
		return true;
	}
	return false;
}
bool function2(double a, double b, double c, double d, double e, double f) {
	if ((a * d - c * b != 0) && ((e * d - b * f != 0) || (a * f - c * e != 0)))
	{
		double y = (a * f - c * e) / (a * d - c * b);
		double x = (d * e - b * f) / (d * a - b * c);
		cout << "2 " << x << ' ' << y;
		return true;
	}
	return false;
}
bool function3(double a, double b, double c, double d, double e, double f)
{
	if (((a * d - c * b == 0) && ((e * d - b * f != 0) || (a * f - c * e != 0))) ||
		(a == 0 && c == 0 && e / b != f / d) ||
		(b == 0 && d == 0 && e / a != f / c) ||
		(a == 0 && b == 0 && c == 0 && d == 0 && (e / f > 0)))
	{
		if (((a == 0 && b == 0 && e == 0 && d != 0 && c == 0) ||
			(c == 0 && d == 0 && f == 0 && b != 0 && a == 0)))
		{
			double y;
			if (b == 0)
				y = f / d;
			else if (d == 0)
				y = e / b;
			else if (e == 0 || f == 0)
				y = 0;
			cout << '4' << ' ' << y;
		}
		else if (((a == 0 && b == 0 && e == 0 && c != 0 && d == 0) ||
			(c == 0 && d == 0 && f == 0 && a != 0 && b == 0)))
		{
			double x;
			if (a == 0)
				x = f / c;
			else if (c == 0)
				x = e / a;
			else if (e == 0 || f == 0)
				x = 0;
			cout << '3' << ' ' << x;
		}
		else
			cout << '0';
		return true;
	}
	return false;
}
bool function4(double a, double b, double c, double d, double e, double f) {
	if (a == 0 && c == 0)
	{
		double y;
		if (e == 0)
			y = f / d;
		else if (f == 0)
			y = e / b;
		else
			y = e / b;
		cout << '4' << ' ' << y;
		return true;
	}
	return false;
}
bool function5(double a, double b, double c, double d, double e, double f) {
	if (b == 0 && d == 0)
	{
		double x;
		if (e == 0)
			x = f / c;
		else if (f == 0)
			x = e / a;
		else
			x = e / a;
		cout << '3' << ' ' << x;
		return true;
	}
	return false;
}
bool function6(double b, double c, double d, double e, double f)
{
	if (b == 0 && e == 0)
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n;
		return true;
	}
	return false;
}
bool function7(double a, double b, double d, double e, double f) {
	if (d == 0 && f == 0)
	{
		double k, n;
		k = -a / b;
		n = e / b;
		cout << '1' << ' ' << k << ' ' << n;
		return true;
	}
	return false;
}
bool function8(double a, double c, double d, double e, double f) {
	if (a == 0 && e == 0)
	{
		double k, n;
		k = -d / c;
		n = f / c;
		cout << '1' << ' ' << k << ' ' << n;
		return true;
	}
	return false;
}
bool function9(double a, double b, double c, double e, double f) {
	if (c == 0 && f == 0)
	{
		double k, n;
		k = -b / a;
		n = e / a;
		cout << '1' << ' ' << k << ' ' << n;
		return true;
	}
	return false;
}
bool function10(double a, double b, double c, double d, double f) {
	if ((a / b == c / d))
	{
		double k, n;
		k = -c / d;
		n = f / d;
		cout << '1' << ' ' << k << ' ' << n;
		return true;
	}
	return false;
}
int main()
{
	double a, b, c, d, e, f;
	input(a, b, c, d, e, f);

	if (allzero(a, b, c, d, e, f));
	else if (function2(a, b, c, d, e, f));
	else if (function3(a, b, c, d, e, f));
	else if (function4(a, b, c, d, e, f));
	else if (function5(a, b, c, d, e, f));
	else if (function6(b, c, d, e, f));
	else if (function7(a, b, d, e, f));
	else if (function8(a, c, d, e, f));
	else if (function9(a, b, c, e, f));
	else if (function10(a, b, c, d, f));
	else
	{
		cout << "Are you kidding me?";
	}
	return 0;
}

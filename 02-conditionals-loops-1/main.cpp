#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, c, sx, ex, dx, f;
	cout << "Введите a:" << endl;
	cin >> a;
	cout << "Введите b:" << endl;
	cin >> b;
	cout << "Введите c:" << endl;
	cin >> c;
	cout << "Введите начальное значение:" << endl;
	cin >> sx;
	cout << "Введите конечное значение:" << endl;
	cin >> ex;
	cout << "Введите шаг:" << endl;
	cin >> dx;

	cout << "|-------------|-------------|" << endl;
	cout << "|      x      |      F      |" << endl;

	bool is_double = (static_cast<int> (a) | static_cast<int>(b))&(static_cast<int>(a) | static_cast<int>(c));

	for (double xx = sx; xx < ex; xx += dx)
	{
		cout << "|-------------|-------------|" << endl;

		if (xx < 0 && b != 0)
		{
			f = a * pow(is_double ? xx : static_cast<int> (xx), 2) + b;
		}
		else if (xx > 0 && b == 0)
		{
			f = (is_double ? xx : static_cast<int>(xx) - a) / (is_double ? xx : static_cast<int>(xx) - c);
		}
		else
		{
			f = is_double ? xx : static_cast<int>(xx) / c;
		}

		cout << "|" << setw(8) << xx << "     |" << setw(8) << f << "     |" << endl;
	}
	cout << "|-------------|-------------|" << endl;
}
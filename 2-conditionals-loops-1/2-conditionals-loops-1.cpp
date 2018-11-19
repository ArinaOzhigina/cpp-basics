#include "pch.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);

	setlocale(LC_ALL, "Russian");
	double a, b, c, sx, ex, dx, f;
	wcout << L"Введите a:" << endl;
	cin >> a;
	wcout << L"Введите b:" << endl;
	cin >> b;
	wcout << L"Введите c:" << endl;
	cin >> c;
	wcout << L"Введите начальное значение:" << endl;
	cin >> sx;
	wcout << L"Введите конечное значение:" << endl;
	cin >> ex;
	wcout << L"Введите шаг:" << endl;
	cin >> dx;

	wcout << L"╔═════════════╦═════════════╗" << endl;
	wcout << L"║      x      ║      F      ║" << endl;

	bool is_double = ((int) a| (int)b)&((int)a| (int)c);

	for (double xx = sx; xx < ex; xx += dx) 
	{
		wcout << L"╠═════════════╬═════════════╣" << endl;

		if (xx < 0 && b != 0) 
		{
			f = a * pow(is_double ? xx : (int) xx, 2) + b;
		}
		else if (xx > 0 && b == 0) 
		{
			f = (is_double ? xx : (int)xx - a) / (is_double ? xx : (int)xx - c);
		}
		else 
		{
			f = is_double ? xx : (int)xx / c;
		}

		wcout << L"║" << setw(13) << xx << L"║" << setw(13) << f << L"║" << endl;
	}
	wcout << L"╚═════════════╩═════════════╝" << endl;
}
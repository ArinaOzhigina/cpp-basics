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

	double x, ex, dx, eps, sum, curel;
	int n;
	wcout << L"Введите начальное значение:" << endl;
	cin >> x;
	wcout << L"Введите конечное значение:" << endl;
	cin >> ex;
	wcout << L"Введите шаг:" << endl;
	cin >> dx;
	wcout << L"Введите точность:" << endl;
	cin >> eps;
	
	wcout << L"╔═════════════╦═════════════╦═════════════╗" << endl;
	wcout << L"║      x      ║      F      ║      n      ║" << endl;
	while (x < ex)
	{
		n = 0;
		wcout << L"╠═════════════╬═════════════╬═════════════╣" << endl;
		sum = 0;
		do
		{
			curel = 1 / ((2 * n + 1)*pow(x, 2 * n + 1));
			sum += curel;
			n++;
		} while (fabs(curel) > eps);
		wcout << L"║" << setw(13) << x << L"║" << setw(13) << 2 * sum << L"║" << setw(13) << n << L"║" << endl;
		x += dx;
	}

	wcout << L"╚═════════════╩═════════════╩═════════════╝" << endl;
}
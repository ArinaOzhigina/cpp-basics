#include "pch.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

double eps;


double getEl(double x, double n)
{
	return 1 / ((2 * n + 1)*pow(x, 2 * n + 1));
}

bool checkEps(double curel)
{
	return fabs(curel) > eps;
}

void printSum(double x)
{
	double sum, curel;
	int n = 0;
	sum = 0;
	wcout << L"╠═════════════╬═════════════╬═════════════╣" << endl;
	do
	{
		curel = getEl(x, n);
		sum += curel;
		n++;
	} while (checkEps(curel));
	wcout << L"║" << setw(13) << x << L"║" << setw(13) << 2 * sum << L"║" << setw(13) << n << L"║" << endl;
}


int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	setlocale(LC_ALL, "Russian");

	double x, ex, dx, curel;

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
		printSum(x);
		x += dx;
	}
	wcout << L"╚═════════════╩═════════════╩═════════════╝" << endl;
}




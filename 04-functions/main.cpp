#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

double GetEl(double x, double n)
{
	return 1 / ((2 * n + 1)*pow(x, 2 * n + 1));
}

bool CheckEps(double curel, double eps)
{
	return fabs(curel) > eps;
}

void PrintSum(double x, double eps)
{
	double sum, curel;
	int n = 0;
	sum = 0;
	cout << "|-------------|-------------|-------------|" << endl;
	do
	{
		curel = GetEl(x, n);
		sum += curel;
		n++;
	} while (CheckEps(curel,eps));
	cout << "|" << setw(13) << x << "|" << setw(13) << 2 * sum << "|" << setw(13) << n << "|" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, ex, dx,eps;

	cout << "Введите начальное значение:" << endl;
	cin >> x;
	cout << "Введите конечное значение:" << endl;
	cin >> ex;
	cout << "Введите шаг:" << endl;
	cin >> dx;
	cout << "Введите точность:" << endl;
	cin >> eps;

	cout << "|-------------|-------------|-------------| " << endl;
	cout << "|      x      |      F      |      n      |" << endl;
	while (x < ex)
	{
		PrintSum(x,eps);
		x += dx;
	}
	cout << "|-------------|-------------|-------------|" << endl;
}




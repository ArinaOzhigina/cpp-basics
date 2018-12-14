#include <cstdio>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	double x, ex, dx, eps, sum, curel;
	int n;
	cout << "Введите начальное значение:" << endl;
	cin >> x;
	cout << "Введите конечное значение:" << endl;
	cin >> ex;
	cout << "Введите шаг:" << endl;
	cin >> dx;
	cout << "Введите точность:" << endl;
	cin >> eps;

	cout << "|-------------|-------------|-------------|" << endl;
	cout << "|      x      |      F      |      n      |" << endl;
	while (x < ex)
	{
		n = 0;
		cout << "|-------------|-------------|-------------|" << endl;
		sum = 0;
		do
		{
			curel = 1 / ((2 * n + 1)*pow(x, 2 * n + 1));
			sum += curel;
			n++;
		} while (fabs(curel) > eps);
		cout << "|" << setw(13) << x << "|" << setw(13) << 2 * sum << "|" << setw(13) << n << "|" << endl;
		x += dx;
	}

	cout << "|-------------|-------------|-------------|" << endl;
}
#include "pch.h"

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	double a, z1, z2;
	cout << "Введите a:" << endl;
	cin >> a;

	z1 = 2 * pow(sin(3 * M_PI - 2 * a), 2) * pow(cos(5 * M_PI + 2 * a), 2);

	z2 = 0.25 - 0.25 * sin(2.5 * M_PI - 8 * a);

	cout << "z1 = " << z1 << "; z2 = " << z2 << ";" << endl;
}
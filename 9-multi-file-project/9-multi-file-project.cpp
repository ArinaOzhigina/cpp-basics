#include "pch.h"
#include <iostream>
#include "functions.h"

using namespace std;

int main()
{
	int n;
	double *myarray;
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество элементов:" << endl;
	cin >> n;
	if (n > 0)
	{
		myarray = new double[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Введите " << i + 1 << " элемент:" << endl;
			cin >> myarray[i];
		}

		cout << "Сумма отрицательных элементов равна: " << endl << negSum(myarray,n) << endl << "Произведение элементов между максимальным и минимальным числом равна:" << endl << getMultiple(myarray,n) << endl << "Отсортированный массив:";
		myarray = sortArray(myarray, n);
		for (int i = 0; i < n; i++)
		{
			cout << myarray[i] << " ";
		}
	}
}
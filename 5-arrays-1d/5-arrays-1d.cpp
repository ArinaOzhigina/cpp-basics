#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int n,minindex,maxindex;
	double negsum, minel, maxel, multiple,*myarray;
	
	cout << "Введите количество элементов:" << endl;
	cin >> n;
	if (n > 0) 
	{
		myarray = new double[n];
		negsum = 0;
		multiple = 1;

		for (int i = 0; i < n; i++)
		{
			double temp;
			cout << "Введите " << i + 1 << " элемент:" << endl;
			cin >> temp;
			if (i == 0) 
			{
				minel = temp;
				maxel = temp;
				minindex = 0;
				maxindex = 0;
			}

			if (temp < 0)
			{
				negsum += temp;
			}

			if (temp > maxel) 
			{
				maxel = temp;
				maxindex = i;
			}

			if (temp < minel)
			{
				minel = temp;
				minindex = i;
			}
			myarray[i] = temp;
		}

		for (int i = maxindex; i < minindex; i++)
		{
			multiple *= myarray[i];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - (i + 1); j++)
			{
				if (myarray[j] > myarray[j + 1])
				{
					double temp = myarray[j];
					myarray[j] = myarray[j + 1];
					myarray[j + 1] = temp;
				}
			}
		}

		cout << "Сумма отрицательных элементов равна: " << endl << negsum << endl << "Произведение элементов между максимальным и минимальным числом равна:" << endl << multiple << endl << "Отсортированный массив:";
		for (int i = 0; i < n; i++)
		{
			cout << myarray[i] << " ";
		}
	}
}

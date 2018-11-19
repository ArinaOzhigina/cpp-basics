#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int x, y, **matrix, nzc, max,min, prevmax;

	cout << "Введите количество столбцов:" << endl;
	cin >> x;
	cout << "Введите количество строк:" << endl;
	cin >> y;
	matrix = new int*[y];
	nzc = y;
	min = 0;
	for (int i = 0; i < y; i++)
	{
		matrix[i] = new int[x];
		bool is_zero = false;
		for (int j = 0; j < x; j++)
		{
			cout << "Введите элемент [" << j << "," << i << "]:" << endl;
			cin >> matrix[i][j];
			if (matrix[i][j] == 0)
			{
				is_zero = true;
			}
			if (i == 0 && j == 0)
			{
				min = matrix[0][0];
			}
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
		}
		if (is_zero)
		{
			nzc--;
		}
	}

	int maxcount;
	prevmax = min;
	bool have_vdrt = false;
	bool is_null = true;
	do 
	{
		maxcount = 0;
		max = min;
		is_null = true;
		for (int i = 0; i < y; i++) 
		{
			for (int j = 0; j < x; j++) 
			{
				if (have_vdrt)
				{
					if (matrix[i][j] > max && matrix[i][j] < prevmax)
					{
						max = matrix[i][j];
						is_null = false;
					}
				}	
				else 
				{
					if (matrix[i][j] > max)
					{
						max = matrix[i][j];
					}
				}
			}
		}

		if (!have_vdrt) 
		{
			have_vdrt = !have_vdrt;
		}

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (matrix[i][j] == max) 
				{
					maxcount++;
				}
			}
		}

		prevmax = max;
	} while (prevmax > min && maxcount < 2);

	cout << "Количество строк, не содержащих ни одного нулевого элемента: " << nzc << endl;
	cout << "Максимальное число, встречающееся более одного раза: ";
	if (is_null)
	{
		cout << "отсутствует";
	}
	else
	{
		cout << max;
	} 
}

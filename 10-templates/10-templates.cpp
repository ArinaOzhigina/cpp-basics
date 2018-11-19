#include "pch.h"
#include <iostream>

using namespace std;

template <typename T>

int getNonZeroRows(T ** matrix, int x, int y) 
{
	int nzc;
	nzc = y;
	for (int i = 0; i < y; i++) 
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i][j] == 0) 
			{
				nzc--;
				break;
			}
		}
	}
	return nzc;
}

template <typename T>
T getMaxDigit(T ** matrix, int x, int y) 
{
	int max, min, prevmax;

	min = matrix[0][0];

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (matrix[i][j] < min)
			{
				min = matrix[i][j];
			}
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
	if (maxcount < 2) 
	{
		return -1;
	}

	return max;
}

template <typename T>
void getDigit(T digit) 
{
	if (digit < 0)
	{
		cout << "отсутствует";
	}
	else
	{
		cout << digit;
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int xint, yint, xfl, yfl, xdoub, ydoub, **matrixint;
	float  **matrixfl;
	double  **matrixdoub;

	cout << "Введите количество столбцов матрицы int:" << endl;
	cin >> xint;
	cout << "Введите количество строк матрицы int:" << endl;
	cin >> yint;
	matrixint = new int*[yint];

	for (int i = 0; i < yint; i++)
	{
		matrixint[i] = new int[xint];
		for (int j = 0; j < xint; j++)
		{
			cout << "Введите элемент [" << j << "," << i << "]:" << endl;
			cin >> matrixint[i][j];
		}
	}

	cout << "Введите количество столбцов матрицы float:" << endl;
	cin >> xfl;
	cout << "Введите количество строк матрицы float:" << endl;
	cin >> yfl;
	matrixfl = new float*[yfl];

	for (int i = 0; i < yfl; i++)
	{
		matrixfl[i] = new float[xfl];
		for (int j = 0; j < xfl; j++)
		{
			cout << "Введите элемент [" << j << "," << i << "]:" << endl;
			cin >> matrixfl[i][j];
		}
	}

	cout << "Введите количество столбцов матрицы double:" << endl;
	cin >> xdoub;
	cout << "Введите количество строк матрицы double:" << endl;
	cin >> ydoub;
	matrixdoub = new double*[ydoub];

	for (int i = 0; i < ydoub; i++)
	{
		matrixdoub[i] = new double[xdoub];
		for (int j = 0; j < xdoub; j++)
		{
			cout << "Введите элемент [" << j << "," << i << "]:" << endl;
			cin >> matrixdoub[i][j];
		}
	}

	



	cout << "Количество строк, не содержащих ни одного нулевого элемента для матрицы int: " << getNonZeroRows(matrixint, xint, yint) << endl;
	cout << "Максимальное число, встречающееся более одного раза: ";
	getDigit(getMaxDigit(matrixint, xint, yint));
	cout << endl;

	cout << "Количество строк, не содержащих ни одного нулевого элемента для матрицы float: " << getNonZeroRows(matrixfl, xfl, yfl) << endl;
	cout << "Максимальное число, встречающееся более одного раза: ";
	getDigit(getMaxDigit(matrixfl, xfl, yfl));
	cout << endl;

	cout << "Количество строк, не содержащих ни одного нулевого элемента для матрицы double: " << getNonZeroRows(matrixdoub, xdoub, ydoub) << endl;
	cout << "Максимальное число, встречающееся более одного раза: ";
	getDigit(getMaxDigit(matrixdoub, xdoub, ydoub));
}
#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string* s = new string[3];
	ifstream file("index.txt");

	if (!file)
	{
		cout << "Файл не открыт\n\n";
	}
	else 
	{
		for (int i = 0; i < 3; i++)
		{
			getline(file, s[i]);
		}

		for (int i = 2; i >= 0; i--)
		{
			cout << s[i] << endl;
		}
	}

}

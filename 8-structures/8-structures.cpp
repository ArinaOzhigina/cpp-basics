#include "pch.h"
#include <fcntl.h>
#include <io.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

const int MARKS_COUNT = 5;
const int STUDENTS_COUNT = 10;

using namespace std;

struct student 
{
	wchar_t * name = new wchar_t[100];
	int group_number;
	short *marks = new short[MARKS_COUNT];
};

int main()
{

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);
	
	setlocale(LC_ALL, "Russian");

	student * students = new student[STUDENTS_COUNT];
	for (int i = 0; i < STUDENTS_COUNT; i++)
	{
		wcout << L"Введите имя " << i + 1 << L" студента:" << endl;
		wcin.getline(students[i].name,100);
		
		wcout << L"Введите номер группы " << i + 1 << L" студента:" << endl;
		wcin >> students[i].group_number;
		wcout << L"Введите оценки " << i + 1 << L" студента:" << endl;
		for (int j = 0; j < MARKS_COUNT; j++)
		{
			wcout << L"Введите оценку " << j + 1 << L":" << endl;
			wcin >> students[i].marks[j];
		}
		wcin.ignore();
	}

	for (int i = 0; i < STUDENTS_COUNT; i++) 
	{
		for (int j = 0; j < STUDENTS_COUNT - (i + 1); j++)
		{
			if (students[j].group_number > students[j + 1].group_number) 
			{
				student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}	
	}

	for (int i = 0; i < STUDENTS_COUNT; i++)
	{
		float middle = 0;
		for (int j = 0; j < MARKS_COUNT; j++) 
		{
			middle += students[i].marks[j];
		}
		middle = middle / MARKS_COUNT;
		if (middle > 4.0) 
		{
			wcout << students[i].name << L"   " << students[i].group_number << endl;
		}
	}
}
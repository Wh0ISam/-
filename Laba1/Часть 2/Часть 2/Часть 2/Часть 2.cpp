#include "pch.h"
#include "Complex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <math.h>

using namespace std;

struct T {
	float x;
	float y;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin;
	fin.open("Complex.txt");
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!\n" << endl;
		int index;
		float buffer, max = 0;
		fin >> buffer;
		int n = buffer;
		cout << "Кол-во комплексных чисел" << n << endl;
		T* p = new T[n];
		for (int i = 0; i < n; i++)
		{
			fin >> buffer;
			p[i].x = buffer;
			fin >> buffer;
			p[i].y = buffer;
			if (p[i].y >= 0)
				cout << i + 1 << " число: " << p[i].x << "+" << p[i].y << "*i" << endl;
			else
				cout << i + 1 << " число: " << p[i].x << p[i].y << "*i" << endl;
			if (sqrt(p[i].x * p[i].x + p[i].y * p[i].y) > max)
			{
				max = sqrt(p[i].x * p[i].x + p[i].y * p[i].y);
				index = i;
			}
		}
		if (p[index].y >= 0)
			cout << "Комплексное число с максимальным модулем: " << p[index].x << " + " << p[index].y << "*i\nМодуль равен: " << max << endl;
		else
			cout << "Комплексное число с максимальным модулем: " << p[index].x << p[index].y << "*i\nМодуль равен: " << max << endl;
	}
	fin.close();
}
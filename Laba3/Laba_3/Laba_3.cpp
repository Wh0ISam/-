#include "pch.h"
#include <iostream>
#include <string>
#include "Child.h"
#include "Tiles.h"
#include "Complex.h"
#include "Vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice;
	cout << "Введите номер задания: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		Child child_1, child_2;
		cout << "Введите информацию о первом ребенке:" << endl;
		child_1.set_info();
		cout << "Введите информацию о втором ребенке:" << endl;
		child_2.set_info();
		cout << "Информация о первом ребенке:" << endl;
		child_1.get_info();
		cout << "Информация о втором ребенке:" << endl;
		child_2.get_info();
	}
	break;

	case 2:
	{
		Tiles tile_1, tile_2;
		cout << "Введите информацию о первом виде кафеля:" << endl;
		cout << "Введите бренд кафеля: ";
		cin >> tile_1.brand;
		cout << "Введите высоту кафеля: ";
		cin >> tile_1.size_h;
		cout << "Введите ширину кафеля: ";
		cin >> tile_1.size_w;
		cout << "Введите цену кафеля: ";
		cin >> tile_1.price;

		cout << "Введите информацию о втором виде кафеля:" << endl;
		cout << "Введите бренд кафеля: ";
		cin >> tile_2.brand;
		cout << "Введите высоту кафеля: ";
		cin >> tile_2.size_h;
		cout << "Введите ширину кафеля: ";
		cin >> tile_2.size_w;
		cout << "Введите цену кафеля: ";
		cin >> tile_2.price;

		cout << "\nИнформация о первом виде кафеля:" << endl;
		tile_1.getData();
		cout << "\nИнформацию о втором виде кафеля:" << endl;
		tile_2.getData();
	}
	break;

	case 3:
	{
		Complex number;
		cout << "Введите число: " << endl;
		number.set_info();
		cout << "\nЗначение числа: " << endl;
		number.get_info();
		number.abs();
	}
	break;

	case 4:
	{
		Vector vector_1, vector_2, vector_sum, vector_sub;
		cout << "Введите первый вектор: " << endl;
		vector_1.set_info();
		cout << "Введите второй вектор: " << endl;
		vector_2.set_info();

		cout << "\nЗначение координат первого вектора: " << endl;
		vector_1.get_info();
		cout << "\nЗначение координат второго вектора: " << endl;
		vector_2.get_info();

		cout << "\nСумма координат первого и второго вектора: " << endl;
		vector_sum.sum(vector_1, vector_2);
		vector_sum.get_info();

		cout << "\nРазность координат первого второго вектора: " << endl;
		vector_sub.sub(vector_1, vector_2);
		vector_sub.get_info();

		cout << "\nМодуль первого вектора: ";
		vector_1.abs();
		cout << "\nМодуль второго вектора: ";
		vector_2.abs();
	}
	break;
	default:
		break;
	}
}
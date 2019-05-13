#include "pch.h"
#include <iostream>
#include <string>
#include "Child.h"
#include "Tiles.h"
#include "Complex.h"
#include "Vector.h"

using namespace std;

void Child::set_info()
{
	cout << "Введите имя ребенка:";
	cin >> name;
	cout << "Введите фамилию ребенка: ";
	cin >> surname;
	cout << "Введите возраст ребенка: ";
	cin >> age;
}

void Child::get_info()
{
	cout << "Имя ребенка: " << name << endl;
	cout << "Фамилия ребенка: " << surname << endl;
	cout << "Возраст ребенка: " << age << endl;
}

void Tiles::getData()
{
	cout << "Бренд кафеля" << brand << endl;
	cout << "Высота кафеля" << size_h << endl;
	cout << "Ширина кафеля" << size_w << endl;
	cout << "Цена кафеля" << price << endl;
}

void Complex::set_info()
{
	cout << "Введите X: ";
	cin >> x;
	cout << "Введите Y: ";
	cin >> y;
}

void Complex::get_info()
{
	cout << "Значение X: " << x << endl;
	cout << "Значение Y: " << y << endl;
}

void Complex::abs()
{
	float result = sqrt(x * x + y * y);
	cout << "\nМодуль числа равен: " << result << endl;
}

void Vector::set_info()
{
	cout << "Введите X: ";
	cin >> x;
	cout << "Введите Y: ";
	cin >> y;
	cout << "Введите Z: ";
	cin >> z;
}

void Vector::get_info()
{
	cout << "Значение X: " << x << endl;
	cout << "Значение Y: " << y << endl;
	cout << "Значение Z: " << z << endl;
}

void Vector::sum(Vector a, Vector b)
{
	x = a.x + b.x;
	y = a.y + b.y;
	z = a.z + b.z;
}

void Vector::sub(Vector a, Vector b)
{
	x = a.x - b.x;
	y = a.y - b.y;
	z = a.z - b.z;
}

void Vector::abs()
{
	float result = sqrt(x*x + y * y + z * z);
	cout << result << endl;
}
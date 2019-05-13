#include "pch.h"
#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex() // по умолчанию
{
	x = 0;
	y = 0;
}

Complex::Complex(float x_yVal) // с параметром
{
	x = x_yVal;
	y = x_yVal;
}

Complex::Complex(float xVal, float yVal) : x(xVal), y(yVal) // Инициалиирующий
{

}

Complex::Complex(const Complex &object) // копирования 
{
	x = object.x;
	y = object.y;
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

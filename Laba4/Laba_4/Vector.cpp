#include "pch.h"
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

Vector::Vector() // по умолчанию
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(float x_y_zVal) // с параметром
{
	x = x_y_zVal;
	y = x_y_zVal;
	z = x_y_zVal;
}

Vector::Vector(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) // Инициалиирующий
{

}

Vector::Vector(const Vector &object) // копирования 
{
	x = object.x;
	y = object.y;
	z = object.z;
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
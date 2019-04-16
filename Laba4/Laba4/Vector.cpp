#include "pch.h"
#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

Vector::Vector() 
{
	x = 0;
	y = 0;
	z = 0;
}

Vector::Vector(float x_y_zVal) 
{
	x = x_y_zVal;
	y = x_y_zVal;
	z = x_y_zVal;
}

Vector::Vector(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) 
{

}

Vector::Vector(const Vector &object) 
{
	x = object.x;
	y = object.y;
	z = object.z;
}

void Vector::set_info()
{
	cout << "������� X: ";
	cin >> x;
	cout << "������� Y: ";
	cin >> y;
	cout << "������� Z: ";
	cin >> z;
}

void Vector::get_info()
{
	cout << "�������� X: " << x << endl;
	cout << "�������� Y: " << y << endl;
	cout << "�������� Z: " << z << endl;
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
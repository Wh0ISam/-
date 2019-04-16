#include "pch.h"
#include <iostream>
#include "Vector.h"

using namespace std;


Vector::Vector()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector &Vector::operator=(const Vector &obj)
{
	x = obj.x;
	y = obj.y;
	z = obj.z;
	return *this;
}

bool Vector::operator==(const Vector & obj)
{
	return (sqrt(x*x + y * y + z * z) == sqrt(obj.x*obj.x + obj.y * obj.y + obj.z * obj.z));
}

bool Vector::operator!=(const Vector & obj)
{
	return !(sqrt(x*x + y * y + z * z) == sqrt(obj.x*obj.x + obj.y * obj.y + obj.z * obj.z));
}


ostream &operator<<(ostream &stream, Vector &obj)
{
	cout << "Vector = (";
	stream << obj.x << ", ";
	stream << obj.y << ", ";
	stream << obj.z << ")\n";
	return stream;
}

istream &operator>>(istream &stream, Vector &obj)
{
	cout << "¬ведите Vector:\n";
	cout << "¬ведите X: ";
	stream >> obj.x;
	cout << "¬ведите Y: ";
	stream >> obj.y;
	cout << "¬ведите Z: ";
	stream >> obj.z;
	return stream;
}
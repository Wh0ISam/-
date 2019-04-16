#include "pch.h"
#include <iostream>
#include "Complex.h"

using namespace std;

Complex::Complex()
{
	x = 0;
	y = 0;
}

Complex &Complex::operator=(const Complex &obj)
{
	x = obj.x;
	y = obj.y;
	return *this;
}

Complex &Complex::operator++(int Val)
{
	Complex temp(*this);
	x++;
	y++;
	return temp;
}

Complex &Complex::operator--(int Val)
{
	Complex temp(*this);
	x--;
	y--;
	return temp;
}

bool Complex::operator==(const Complex & obj)
{
	return (x == obj.x && y == obj.y);
}

bool Complex::operator!=(const Complex & obj)
{
	return !(x == obj.x && y == obj.y);
}

ostream &operator<<(ostream &stream, Complex &obj)
{
	cout << "Complex: ";
	if (obj.y >= 0)
		stream << obj.x << "+" << obj.y << "*i" << endl;
	else
		stream << obj.x << obj.y << "*i" << endl;

	return stream;
}

istream &operator>>(istream &stream, Complex &obj)
{
	cout << "¬ведите Complex:\n";
	cout << "¬ведите X: ";
	stream >> obj.x;
	cout << "¬ведите Y: ";
	stream >> obj.y;
	return stream;
}

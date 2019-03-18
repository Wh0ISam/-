#include "Complex.h"
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


void ComplexNumber::showComplexNumber()
{
	cout << x << showpos << y << "i" << noshowpos;
}

ComplexNumber::ComplexNumber(double x, double y)
{
	this->x = x;
	this->y = y;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber num)
{
	ComplexNumber newNum(x + num.x, y + num.y);
	return newNum;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber num)
{
	ComplexNumber newNum(x - num.x, y - num.y);
	return newNum;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber num)
{
	ComplexNumber newNum(x * num.x - y * num.y, y * num.x + x * num.y);
	return newNum;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber num)
{
	ComplexNumber newNum((x * num.x + y * num.y) / (num.x * num.x + num.y * num.y), (y * num.x - x * num.y) / (num.x * num.x + num.y * num.y));
	return newNum;
}
void ComplexNumber::readComplexNumber() {
	cout << "Enter real : ";
	cin >> x;
	cout << "Enter imaginary : ";
	cin >> y;
}
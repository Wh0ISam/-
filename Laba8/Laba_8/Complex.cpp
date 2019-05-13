#include "pch.h"
#include "Complex.h"

void Complex::set_info()
{
	cout << "\nВведите X: ";
	cin >> x;
	cout << "Введите Y: ";
	cin >> y;
	cout << endl;
}

ostream &operator<<(ostream &stream, Complex &obj)
{
	cout << "\nComplex: ";
	if (obj.y >= 0)
		stream << obj.x << "+" << obj.y << "*i";
	else
		stream << obj.x << obj.y << "*i";

	return stream;
}
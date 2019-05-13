#include "pch.h"
#include <iostream>
#include <string>
#include "Complex.h"

using namespace std;

Complex::Complex() // �� ���������
{
	x = 0;
	y = 0;
}

Complex::Complex(float x_yVal) // � ����������
{
	x = x_yVal;
	y = x_yVal;
}

Complex::Complex(float xVal, float yVal) : x(xVal), y(yVal) // ���������������
{

}

Complex::Complex(const Complex &object) // ����������� 
{
	x = object.x;
	y = object.y;
}

void Complex::set_info()
{
	cout << "������� X: ";
	cin >> x;
	cout << "������� Y: ";
	cin >> y;
}

void Complex::get_info()
{
	cout << "�������� X: " << x << endl;
	cout << "�������� Y: " << y << endl;
}

void Complex::abs()
{
	float result = sqrt(x * x + y * y);
	cout << "\n������ ����� �����: " << result << endl;
}

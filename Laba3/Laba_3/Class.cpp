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
	cout << "������� ��� �������:";
	cin >> name;
	cout << "������� ������� �������: ";
	cin >> surname;
	cout << "������� ������� �������: ";
	cin >> age;
}

void Child::get_info()
{
	cout << "��� �������: " << name << endl;
	cout << "������� �������: " << surname << endl;
	cout << "������� �������: " << age << endl;
}

void Tiles::getData()
{
	cout << "����� ������" << brand << endl;
	cout << "������ ������" << size_h << endl;
	cout << "������ ������" << size_w << endl;
	cout << "���� ������" << price << endl;
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
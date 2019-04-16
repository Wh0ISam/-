#pragma once

using namespace std;

class Complex
{
private:
	float x;
	float y;
public:
	Complex();

	Complex &operator=(const Complex &obj);
	Complex &operator++(int Val);
	Complex &operator--(int Val);
	bool operator==(const Complex & obj);
	bool operator!=(const Complex & obj);
	friend ostream &operator<<(ostream &stream, Complex &obj);
	friend istream &operator>>(istream &stream, Complex &obj);
};
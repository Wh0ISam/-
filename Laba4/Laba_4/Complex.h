#pragma once

using namespace std;

class Complex
{
private:
	float x;
	float y;
public:
	void set_info();
	void get_info();
	void abs();

	Complex();

	Complex(float x_yVal);

	Complex(float xVal, float yVal);

	Complex(const Complex &object);

	~Complex() {}
};
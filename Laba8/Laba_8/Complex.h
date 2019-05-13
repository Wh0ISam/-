#pragma once
#include <iostream>

using namespace std;

class Complex
{
private:
	float x;
	float y;
public:
	void set_info();
	friend ostream &operator<<(ostream &stream, Complex &obj);
};


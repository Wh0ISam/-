#pragma once

using namespace std;

class Vector
{
private:
	float x;
	float y;
	float z;
public:
	void set_info();
	void get_info();
	void sum(Vector a, Vector b);
	void sub(Vector a, Vector b);
	void abs();

	Vector();

	Vector(float x_y_zVal);

	Vector(float xVal, float yVal, float zVal);

	Vector(const Vector &object);
	
	~Vector() {} // деструктор

};
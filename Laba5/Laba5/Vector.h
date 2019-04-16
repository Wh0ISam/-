#pragma once

using namespace std;

class Vector
{
private:
	float x;
	float y;
	float z;
public:
	Vector();

	Vector &operator=(const Vector &obj);
	bool operator==(const Vector & obj);
	bool operator!=(const Vector & obj);
	friend ostream &operator<<(ostream &stream, Vector &obj);
	friend istream &operator>>(istream &stream, Vector &obj);
};

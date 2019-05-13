#pragma once
#include <string>
#include <iostream>

using namespace std;

class Machine
{
private:
	string mark;
	string number;
public:
	void set_info();
	friend ostream &operator<<(ostream &stream, Machine &obj);
};


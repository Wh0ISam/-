#pragma once
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Child

{
private:
	string name;
	string surname;
	int age;
public:
	void set_info();
	void get_info();

	Child();

	Child(string nameVal, string surnameVal);

	Child(string nameVal, string surnameVal, int ageVal);

	Child(const Child &object);

	~Child() {} // деструктор
};

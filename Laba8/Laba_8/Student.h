#pragma once
#include <string>
#include <iostream>

using namespace std;

class Student
{
private:
	string name;
	string surname;
	int age;
public:
	void set_info();
	void get_info();
};


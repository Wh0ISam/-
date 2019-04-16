#pragma once

using namespace std;

class Student
{
protected:
	string name;
	int age;
	string group;
	long long int pasport;
public:
	void set_student();
	void get_student();
};
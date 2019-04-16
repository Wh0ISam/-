#pragma once
#include "Student.h" 

using namespace std;

class Leader : public Student
{
protected:
	long long int phone_number;
	string email;
public:
	void info();
	void set_leader();
	void get_leader();
};
#include "pch.h"
#include <iostream>
#include <string>
#include "Child.h"

using namespace std;

Child::Child() 
{
	name = "NoName";
	surname = "NoSurname";
	age = 0;
}

Child::Child(string nameVal, string surnameVal){
	name = nameVal;
	surname = surnameVal;
	age = 0;
}

Child::Child(string nameVal, string surnameVal, int ageVal) : name(nameVal), surname(surnameVal), age(ageVal) 
{

}

Child::Child(const Child &object)
{
	name = object.name;
	surname = object.surname;
	age = object.age;
}

void Child::set_info()
{
	cout << "������� ��� �������:";
	cin >> name;
	cout << "������� ������� �������: ";
	cin >> surname;
	cout << "������� ������� �������: ";
	cin >> age;
}

void Child::get_info()
{
	cout << "��� �������: " << name << endl;
	cout << "������� �������: " << surname << endl;
	cout << "������� �������: " << age << endl;
}

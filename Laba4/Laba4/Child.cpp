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
	cout << "Введите имя ребенка:";
	cin >> name;
	cout << "Введите фамилию ребенка: ";
	cin >> surname;
	cout << "Введите возраст ребенка: ";
	cin >> age;
}

void Child::get_info()
{
	cout << "Имя ребенка: " << name << endl;
	cout << "Фамилия ребенка: " << surname << endl;
	cout << "Возраст ребенка: " << age << endl;
}

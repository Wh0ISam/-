#include "pch.h"
#include "Student.h"

void Student::set_info()
{
	cout << "Введите имя ученика: ";
	cin >> name;
	cout << "Введите фамилию ученика: ";
	cin >> surname;
	cout << "Введите возраст ученика: ";
	cin >> age;
}

void Student::get_info()
{
	cout << "Имя ученика: " << name << endl;
	cout << "Фамилия ученика:" << surname << endl;
	cout << "Возраст ученика: " << age << endl;
}
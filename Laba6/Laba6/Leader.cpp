#include "pch.h"
#include <iostream>
#include <string>
#include "Leader.h"

using namespace std;

void Leader::info()
{
	cout << "Оповестить группу о чем-либо";
}

void Leader::set_leader()
{
	cout << "Введите имя старосты: ";
	cin >> name;
	cout << "Введите возраст старосты: ";
	cin >> age;
	cout << "Введите номер группы старосты: ";
	cin >> group;
	cout << "Введите паспортные данные старосты: ";
	cin >> pasport;
	cout << "Введите номер телефона старосты: ";
	cin >> phone_number;
	cout << "Введите Email старосты: ";
	cin >> email;
}

void Leader::get_leader()
{
	cout << "Имя студента: " << name << endl;
	cout << "Возраст студента: " << age << endl;
	cout << "Номер группы студента: " << group << endl;
	cout << "Паспортные данные студента: " << pasport << endl;
	cout << "Номер телефона старосты: " << phone_number << endl;
	cout << "Email старосты: " << email << endl;
}
#include "pch.h"
#include <iostream>
#include <string>
#include "Alive.h"

using namespace std;

void Alive::eat()
{
	cout << "Кушать" << endl;
}
void Alive::set_alive()
{
	cout << "Введите название живого существа: ";
	cin >> name;
	cout << "Введите скорость живого существа: ";
	cin >> speed;
}

void Alive::get_alive()
{
	cout << "Название живого существа: " << name << endl;
	cout << "Скорость живого существа: " << speed << endl;
}
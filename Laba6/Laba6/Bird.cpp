#include "pch.h"
#include <iostream>
#include <string>
#include "Bird.h"

using namespace std;

void Bird::move()
{
	cout << "Летать" << endl;
}

void Bird::sound()
{
	cout << "Кар-Кар" << endl;
}

void Bird::set_bird()
{
	cout << "Введите название птицы: ";
	cin >> name;
	cout << "Введите скорость птицы: ";
	cin >> speed;
}

void Bird::get_bird()
{
	cout << "Название птицы: " << name << endl;
	cout << "Скорость птицы: " << speed << endl;
}

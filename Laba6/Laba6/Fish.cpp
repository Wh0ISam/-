#include "pch.h"
#include <iostream>
#include <string>
#include "Fish.h"

using namespace std;

void Fish::move()
{
	cout << "Плавать" << endl;
}

void Fish::ability()
{
	cout << "Жабры" << endl;
}

void Fish::set_fish()
{
	cout << "Введите название рыбы: ";
	cin >> name;
	cout << "Введите скорость рыбы: ";
	cin >> speed;
}

void Fish::get_fish()
{
	cout << "Название рыбы: " << name << endl;
	cout << "Скорость рыбы: " << speed << endl;
}
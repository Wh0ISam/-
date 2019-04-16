#include "pch.h"
#include <iostream>
#include <string>
#include "Animals.h"

using namespace std;

void Animals::set_animals()
{
	cout << "Введите имя животного: ";
	cin >> name;
	cout << "Введите возраст животного: ";
	cin >> age;
	cout << "Введите скорость животного: ";
	cin >> speed;
}

void  Animals::get_animals()
{
	cout << "Имя животного: " << name << endl;
	cout << "Возраст животного: " << age << endl;
	cout << "Скорость животного: " << speed << endl;
}
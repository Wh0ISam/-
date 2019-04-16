#include "pch.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Leader.h"
#include "Alive.h"
#include "Bird.h"
#include "Fish.h"
#include "Animal.h"
#include "Animals.h"
#include "Dog.h"
#include "Cat.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Часть 1\n\n\n";

	Student st;
	cout << "Введите информацию о ученике:" << endl;
	st.set_student();
	cout << "\nИнформация о ученике:" << endl;
	st.get_student();

	Leader lead;
	cout << "\nВведите информацию о старосте:" << endl;
	lead.set_leader();
	cout << "\nИнформация о старосте:" << endl;
	lead.get_leader();
	cout << "\nСтароста может: ";
	lead.info();

	cout << "\n\n\nЧасть 2\n\n\n";

	Bird bird;
	cout << "Введите информацию о птице:" << endl;
	bird.set_bird();
	cout << "\nИнформация о птице:" << endl;
	bird.get_bird();
	cout << "\nПтица может:\n";
	bird.move();
	bird.eat();
	cout << "\nПтица издает звук:";
	bird.sound();

	Fish fish;
	cout << "\nВведите информацию о рыбе:" << endl;
	fish.set_fish();
	cout << "\nИнформация о рыбе:" << endl;
	fish.get_fish();
	cout << "\nРыба может:\n";
	fish.ability();
	fish.eat();
	fish.move();

	Animal animal;
	cout << "\nВведите информацию о животном:" << endl;
	animal.set_animal();
	cout << "\nИнформация о животном:" << endl;
	animal.get_animal();
	cout << "\nЖивотное может:\n";
	animal.eat();
	animal.move();

	cout << "\n\n\nЧасть 3\n\n\n";

	Dog dog;
	cout << "\nВведите информацию о собаке:" << endl;
	dog.set_animals();
	cout << "\nИнформация о собаке:" << endl;
	dog.get_animals();
	cout << "\nСобака может выполнять команды:\n";
	dog.sit();
	dog.sound();
	dog.take();

	Cat cat;
	cout << "\nВведите информацию о кошке:" << endl;
	cat.set_animals();
	cout << "\nИнформация о кошке:" << endl;
	cat.get_animals();
	cout << "\nКошка может:\n";
	cat.play();
	cat.drink();

	cout << "\n\n\nКонец!\n\n\n";
	return 0;
}
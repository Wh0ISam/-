#include "pch.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include "Student.h"
#include "Complex.h"
#include "Machine.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//part 1
	vector <Student> Group;
	Student buffer_student;
	int choice;
	do
	{
		cout << "Хотите добавить нового студента?\n"
			<< "1. Да\n"
			<< "2. Нет\n"
			<< "Выберете желаемый вариант: ";
		cin >> choice;
		if (choice == 1)
		{
			buffer_student.set_info();
			Group.push_back(buffer_student);
		}
	} while (choice == 1);
	for (int i = 0; i < Group.size(); i++)
	{
		cout << "\nУченик №" << i + 1 << endl;
		Group[i].get_info();
	}
	//part 2
	list <Complex> complex_list;
	Complex buffer_complex;
	cout << endl;
	do
	{
		cout << "Хотите добавить комплексное число?\n"
			<< "1. Да\n"
			<< "2. Нет\n"
			<< "Выберете желаемый вариант: ";
		cin >> choice;
		if (choice == 1)
		{
			buffer_complex.set_info();
			complex_list.push_back(buffer_complex);
		}
	} while (choice == 1);
	cout << "Вывод списка Complex:" << endl;
	for (auto i = complex_list.begin(); i != complex_list.end(); i++)
	{
		cout  << *i ;
	}

	//part 3

	queue <Machine> machine_queue;
	Machine buffer_machine;
	cout << endl;
	do
	{
		cout << "\nХотите добавить машину в очередь?\n"
			<< "1. Да\n"
			<< "2. Нет\n"
			<< "Выберете желаемый вариант: ";
		cin >> choice;
		if (choice == 1)
		{
			buffer_machine.set_info();
			machine_queue.push(buffer_machine);
		}
	} while (choice == 1);
	cout << "\nВывод очереди" << endl;
	cout << "В очереди " << machine_queue.size() << " машин!\n" << endl;
	while (!machine_queue.empty())
	{
		cout << machine_queue.front() << endl;
		machine_queue.pop();
	}
}


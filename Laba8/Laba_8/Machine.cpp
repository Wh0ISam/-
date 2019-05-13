#include "pch.h"
#include "Machine.h"

void Machine::set_info()
{
	cout << "Введите марку машины: ";
	cin >> mark;
	cout << "Введите номер машины: ";
	cin >> number;
}

ostream &operator<<(ostream &stream, Machine &obj)
{
	cout << "Марка машины: " << obj.mark << endl;
	cout << "Номер машины:" << obj.number << endl;
	return stream;
}
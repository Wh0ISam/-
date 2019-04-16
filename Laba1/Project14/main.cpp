#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
#include "Complex.h"

using namespace std;
void instruction();
void menu();

int main()
{
	setlocale(LC_CTYPE, "rus");
	menu();

	cout << "\n\n";
	return 0;
}
void menu() {

	instruction();

	int punkt;
	ComplexNumber z1(0, 0);
	ComplexNumber z2(0, 0);

	do {
		cin >> punkt;

		switch (punkt) {
		case 1:
			cout << "Введите первое комплексное число: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Введите второе комплексное число:  ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 + z2 = ";
			(z1 + z2).showComplexNumber();
			cout << "\n";
			instruction();
			break;
		case 2:
			cout << "Введите первое комплексное число: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Введите второе комплексное число: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 - z2 = ";
			(z1 - z2).showComplexNumber();
			cout << "\n";
			instruction();
			break;
		case 3:
			cout << "Введите первое комплексное число: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Введите второе комплексное число: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 * z2 = ";
			(z1 * z2).showComplexNumber();
			cout << "\n";
			instruction();
			break;
		case 4:
			cout << "Введите первое комплексное число: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Введите второе комплексное число: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 / z2 = ";
			(z1 / z2).showComplexNumber();
			cout << "\n";
			instruction();
			break;
		}
	} while (punkt != 5);
}

void instruction() {
	cout << "\t\t Меню \n" <<
		"1 - Сумма\n" <<
		"2 - Разность\n" <<
		"3 - Произведение\n" <<
		"4 - Деление\n" <<
		"5 - Выход\n\n";
}
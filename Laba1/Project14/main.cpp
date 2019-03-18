#include <iostream>
#include <cmath>
#include <iomanip>
#include "Complex.h"

using namespace std;
void instruction();
void menu();

int main()
{
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
			cout << "Enter the first complex number: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Enter the second complex number: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 + z2 = ";
			(z1 + z2).showComplexNumber();
			break;
		case 2:
			cout << "Enter the first complex number: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Enter the second complex number: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 - z2 = ";
			(z1 - z2).showComplexNumber();
			break;
		case 3:
			cout << "Enter the first complex number: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Enter the second complex number: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 * z2 = ";
			(z1 * z2).showComplexNumber();
			break;
		case 4:
			cout << "Enter the first complex number: ";
			cout << "\n";
			z1.readComplexNumber();
			cout << "Enter the second complex number: ";
			cout << "\n";
			z2.readComplexNumber();

			cout << "z1 / z2 = ";
			(z1 / z2).showComplexNumber();
			break;
		}
	} while (punkt != 5);
}

void instruction() {
	cout << "\t\t Menu \n" <<
		"1 - Sum\n" <<
		"2 - Difference\n" <<
		"3 - Multiplication\n" <<
		"4 - Division\n" <<
		"5 - Exit\n\n";
}
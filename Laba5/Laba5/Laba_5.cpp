#include "pch.h"
#include <iostream>
#include "Complex.h"
#include "Vector.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	//Part 1
	Complex num1, num2;
	cout << "Созданные комплекные числа:\n";
	cout << num1 << num2 << endl;

	cout << "Введите значения этим числам:\n"
		<< "Первое число:\n";
	cin >> num1;
	cout << "Второе число:\n";
	cin >> num2;

	cout << "\nВведенные числа:\n";
	cout << "Первое число:\n" << num1 << "Второе число:\n" << num2 << endl;

	num1++;
	num2--;
	cout << "1ое число после оператора ++:\n" << num1 << "2ое число после оператора --:\n" << num2 << endl;

	if (num1 == num2)
		cout << "Комплексные числа равны" << endl;
	if (num1 != num2)
		cout << "Комплексные числа не равны" << endl;
	//Part 2
	Vector vec1, vec2;

	cout << "\n\nСозданные вектора:\n";
	cout << vec1 << vec2 << endl;

	cout << "Введите значения этим векторам:\n"
		<< "Первый вектор:\n";
	cin >> vec1;
	cout << "Второй вектор:\n";
	cin >> vec2;

	cout << "\nВведенные вектора:\n";
	cout << "Первой вектор:\n" << vec1 << "Второй вектор:\n" << vec2 << endl;

	if (vec1 == vec2)
		cout << "Вектора равны" << endl;
	if (vec1 != vec2)
		cout << "Вектора не равны" << endl;

	return 0;
}
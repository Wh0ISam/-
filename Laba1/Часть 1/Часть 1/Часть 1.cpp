#include "pch.h"
#include <iostream>
#include <string>
#include "Complex.h"


using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	T numbers;
	int choice;
	string proverka;
	cout << "Какую операцию хотите выполнить?\n1. Сложение комплексных чисел\n2. Вычитание комплексных чисел\n3. Умножение комплексных чисел\n4. Деление комплексных чисел\n5. Умножение комплексного числа на вещественное число\nВведите номер выбранной операции:  ";
again:
	cin >> proverka;
	if (proverka.length() != 1 || proverka[0] < '1' || proverka[0] > '5')
	{
		cout << "Ошибка ввода!\nВведите номер выбранной операции заново: ";
		goto again;
	}
	choice = stoi(proverka);

	if (choice != 5)
	{
		cout << "\nАлгебраическая форма комплексного числа z = x + y*i\n" << endl;
		cout << "Введите х для первого числа: ";
		numbers.x1 = Enter();
		cout << "Введите y для первого числа: ";
		numbers.y1 = Enter();
		cout << "Введите х для второго числа: ";
		numbers.x2 = Enter();
		cout << "Введите y для второго числа: ";
		numbers.y2 = Enter();
		switch (choice)
		{
		case 1:
			numbers.sum();
			break;
		case 2:
			numbers.diff();
			break;
		case 3:
			numbers.pr();
			break;
		case 4:
			numbers.del();
			break;
		}
	}
	else
	{
		cout << "Алгебраическая форма комплексного числа z = x + y*i" << endl;
		cout << "Введите х для комплексного числа: ";
		numbers.x1 = Enter();
		cout << "Введите y для комплексного числа: ";
		numbers.y1 = Enter();
		cout << "Введите вещественное число на которе будете умножать: ";
		numbers.alfa = Enter();
		numbers.pr_alfa();
	}
	return 0;
}
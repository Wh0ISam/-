#include "pch.h"
#include <iostream>
#include "functoin.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int size;
	cout << "Введите кол-во элементов в массиве: ";
	cin >> size;
	int *array = new int[size];
	cout << "Сгенерированный массив:\n";
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 21 - 10;
		cout << array[i] << "\t";
	}
	void(*pointer) (int*, int) = menu(array, size);
	pointer(array, size);
}
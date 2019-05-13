#include "pch.h"
#include <iostream>
#include "functoin.h"

using namespace std;

void(*menu(int *array, int size))(int*, int)
{
	int sum = array[0];
	for (int i = 1; i < size; i++)
		sum = sum + array[i];
	if (sum == array[0])
		return &inverse;
	if (sum > array[0])
		return &increase;
	if (sum < array[0])
		return &decrease;
}

void inverse(int *array, int size)
{

	cout << "\nИнвертированный массив:\n";
	int t;
	for (int i = 0; i < size; i++)
	{
		if (i != size / 2)
		{
			t = array[i];
			array[i] = array[size - i - 1];
			array[size - i - 1] = t;
		}
		cout << array[i] << "\t";
	}
}

void increase(int *array, int size)
{
	cout << "\nМассив в неубывающем порядке:\n";
	int t;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] > array[j])
			{
				t = array[j];
				array[j] = array[i];
				array[i] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}

}

void decrease(int *array, int size)
{
	cout << "\nМассив в невозрастающем порядке:\n";
	int t;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				t = array[j];
				array[j] = array[i];
				array[i] = t;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << "\t";
	}
}
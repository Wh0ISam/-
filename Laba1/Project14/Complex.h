#pragma once
class ComplexNumber
{
private:
	double x;
	double y;
public:
	//конструкторы
	ComplexNumber(double x, double y);

	//вывод комплексного числа
	void showComplexNumber();
	void readComplexNumber();


	// операции: сложение, вычитание, деление, умножение
	ComplexNumber operator+(ComplexNumber num);
	ComplexNumber operator-(ComplexNumber num);
	ComplexNumber operator*(ComplexNumber num);
	ComplexNumber operator/(ComplexNumber num);
};


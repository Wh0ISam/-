#pragma once
class ComplexNumber
{
private:
	double x;
	double y;
public:
	//������������
	ComplexNumber(double x, double y);

	//����� ������������ �����
	void showComplexNumber();
	void readComplexNumber();


	// ��������: ��������, ���������, �������, ���������
	ComplexNumber operator+(ComplexNumber num);
	ComplexNumber operator-(ComplexNumber num);
	ComplexNumber operator*(ComplexNumber num);
	ComplexNumber operator/(ComplexNumber num);
};


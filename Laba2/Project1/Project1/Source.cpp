// ��������� ������� ������� ��������� ������ � ���� ������ �������� ������ 50 ��������� �� �����������, ���� ��� �� �������� 
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
//���������� �� ��������
void lessSort(int &x, int &y) {
	int temp = 0;
	if (x > y) {
		temp = x;
		x = y;
		y = temp;
	}
}
//���������� �� �����������
void greateSort(int &x, int &y) {
	int temp = 0;
	if (x < y) {
		temp = x;
		x = y;
		y = temp;
	}
}
//����������
void sort(int *a, void(*g)(int&, int&), void(*l)(int&, int&)) {
	//���� ������ �������� ������� ������ 50 ��������� �� ����������� ����� �� ��������
	if (a[0] > 50) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				g(a[i], a[j]);
			}
		}
	}
	else 
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				l(a[i], a[j]);
			}
		}

}
void main() {
	//������� ��������� �� �������
	void(*lessptr) (int&, int&) = &lessSort;
	void(*greateptr) (int&, int&) = &greateSort;
	int i, j;
	int a[5];
	srand(time(NULL));
	for (i = 0; i < 5; i++) {
		a[i] = rand() % 100 + 0;
		cout << a[i] << endl;
	}


	cout << "................" << endl;
	

	sort(a, greateptr, lessptr);
	for (i = 0; i < 5; i++)
		cout << a[i] << endl;


	cout << "................" << endl;
	system ("pause");
}
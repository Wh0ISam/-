#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
struct building     //������� ���������!
{
	char mark[20];       //����� ����� ��������� �������� �����
	int god;        //��� �������
	int Vbag;   //����� ���������
	bool engine;       //��������� ���������
	bool window; //������� �� ����
	int Vbag2; //������������ ���������

	bool window_f(int b);
	bool engine_f(int b);
	int Vbag2_f(int b);
};
bool building::window_f(int b) {
	if (b = 1)
		window = false;
	else
		window = true;
	return window;
}
bool building::engine_f(int b) {
	if (b = 1)
		engine = true;
	else
		engine = false;
	return engine;
}
int building::Vbag2_f(int b) {
	if (b = 1)
		Vbag2 = true;
	else
		Vbag2 = false;
	return Vbag2;
}


int main() {
	setlocale(LC_ALL, "rus");
	struct building avto;
	int a = 0, b;
	cout << "������� ������ ���� �����, ��� �������, ����� ���������." << endl;
	cin >> avto.mark >> avto.god >> avto.Vbag;
	cout << "�����:" << avto.mark << endl;
	cout << "��� �������:" << avto.god << endl;
	cout << "����� ���������:" << avto.Vbag << endl;
	cout << "�������� � ��� �� ������ ��������. ���� - 1, ��������� - 2, �������� - 3 " << endl;
	cin >> a;
	if (a == 1) {
		cout << "������� ��� ������� ����? 1-������� 2-�������" << endl;
		cin >> b;
		avto.window = avto.window_f(b);
	}
	if (a == 2) {
		cout << "��������� ��� ��������� ���������? 1-��������� 2-���������"<<endl;
		cin >> b;
		avto.engine = avto.engine_f(b);
	}

	
	if (a == 3) {
		cout << "������� ����� ����� �������� � ��������."<< endl;
		cin >> b;
		avto.Vbag2 = avto.Vbag2_f(b);
	}

	cout << "�����:" << avto.mark << endl;
	cout << "��� �������:" << avto.god << endl;
	cout << "����� ���������:" << avto.Vbag << endl;
	cout << "����:" << avto.window << endl;
	cout << "���������:" << avto.engine << endl;
	cout << "��������� ����� � ���������" << avto.Vbag2 << endl;
	system("pause");

	return 0;
}
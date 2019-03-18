#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
struct building     //Создаем структуру!
{
	char mark[20];       //здесь будет храниться название марки
	int god;        //год выпуска
	int Vbag;   //объем багажника
	bool engine;       //состояние двигателя
	bool window; //открыты ли окна
	int Vbag2; //заполненость багажника

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
	cout << "Введите данные авто марка, год выпуска, объем багажника." << endl;
	cin >> avto.mark >> avto.god >> avto.Vbag;
	cout << "Марка:" << avto.mark << endl;
	cout << "Год выпуска:" << avto.god << endl;
	cout << "Объем багажника:" << avto.Vbag << endl;
	cout << "Выберете с чем вы хотите работать. Окна - 1, двигатель - 2, багажник - 3 " << endl;
	cin >> a;
	if (a == 1) {
		cout << "Открыть или закрыть окно? 1-закрыть 2-открыть" << endl;
		cin >> b;
		avto.window = avto.window_f(b);
	}
	if (a == 2) {
		cout << "Запустить или заглушить двигатель? 1-запустить 2-заглушить"<<endl;
		cin >> b;
		avto.engine = avto.engine_f(b);
	}

	
	if (a == 3) {
		cout << "Введите какой объем положить в багажник."<< endl;
		cin >> b;
		avto.Vbag2 = avto.Vbag2_f(b);
	}

	cout << "Марка:" << avto.mark << endl;
	cout << "Год выпуска:" << avto.god << endl;
	cout << "Объем багажника:" << avto.Vbag << endl;
	cout << "Окно:" << avto.window << endl;
	cout << "Двигатель:" << avto.engine << endl;
	cout << "Свободное место в багажнике" << avto.Vbag2 << endl;
	system("pause");

	return 0;
}
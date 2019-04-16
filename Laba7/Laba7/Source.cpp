#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>
using namespace std;

class Human {
protected:
	string surname;
	string name;
	string midname;
	int age;
public: 
	Human() {
	
	}
	Human(string valueName, string valueSurname, string valueMidname, int valueAge) {
		name = valueName;
		surname = valueSurname;
		midname = valueMidname;
		age = valueAge;
	}
	virtual void print() = 0;

	~Human() {
	}
};
class Student :public Human {
private:
	bool onLesson;
public:
	Student() {
	
	}
	void setStudent(string valueName, string valueSurname, string valueMidname, int valueAge, bool Lesson) {
		name = valueName;
		surname = valueSurname;
		midname = valueMidname;
		age = valueAge;
		onLesson = Lesson;
	}
	void print() override {
		cout << "Имя: " << name << endl << "Фамилия: " << surname << endl << "Отчество: " << midname << endl << "Возраст: " << age << endl << "Есть пара?: " << onLesson <<endl;
	}
	~Student() {
	};
};


class Boss :public Human {
private:
	int numberOfWorkers;
public:
	Boss(){
	
	}
	void setBoss(string valueName, string valueSurname, string valueMidname, int valueAge,int Number ) {
		name = valueName;
		surname = valueSurname;
		midname = valueMidname;
		age = valueAge;
		numberOfWorkers = Number;
	}
	void print() override {
		cout << "Имя: " << name << endl << "Фамилия: " << surname << endl << "Отчество: " << midname << endl << "Возраст: " << age << endl << "Кол-во сотрудников: " << numberOfWorkers << endl;
	}
	~Boss(){
	}

};
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a,  Number, age;
	string name, surname, midname;
	bool Lesson;
	cout << "Выберете номер:" << endl << " 1.Учюсь"<< endl << " 2.Работаю" << endl;
	cin >> a;

	if (a == 1) {
		cout << "Имя, Фамилия, Отчество, Возраст, Есть ли у вас парра?(1 = да, 0 = нет)" << endl;
		cin >> name >> surname >> midname >> age >> Lesson;
		Student test;
		test.setStudent(name, surname, midname, age, Lesson);
		test.print();
	}
	else{
		cout << "Имя, Фамилия, Отчество, Возраст, Сколько работников?(1 = да, 0 = нет)" << endl;
		cin >> name >> surname >> midname >> age >> Number;
		Boss test;
		test.setBoss(name, surname, midname, age, Number);
		test.print();
	}
	system("pause");
}
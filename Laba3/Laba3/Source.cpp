#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Child {
private:
	string name;
	string surname;
	int age;
public: 
	void input() {
		cin >> name >> surname >> age;
	}
	void print() {
		cout << name << " " << surname << age << endl;
	}
};
int main() {
	Child firstChild;
	Child secondChild;
	firstChild.input();
	secondChild.input();
	firstChild.print();
	secondChild.print();
	system("pause");
}


#pragma once
#include <string>
using namespace std;
class PersonClass
{
public:
	string name;
	void setAge(int _age) {
		age = _age;
	}
	void display() {
		cout << endl << "Имя: " << name;
		cout << endl << "Возраст: " << age;
		// endl = "\n"
	}
private:
	int age;
};


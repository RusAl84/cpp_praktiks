#pragma once
class Student
{
private:
	int age=13;
	char password[20];
public:
	void age(int _age) {
		if (_age>0 and _age<200)
			this->age = _age;
	}
	int age() {
		return this->age;
	}
};


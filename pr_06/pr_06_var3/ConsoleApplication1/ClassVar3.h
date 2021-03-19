#pragma once

#include <string>

using namespace std;

class ClassVar3
{
public:
	string FIO;
	float var1, var2;
	float* pmas[2];
	ClassVar3(string _fio, int _age) {
		this->FIO = _fio;
		//this->Age = _age;
		this->SetAge(_age);
	}
	ClassVar3() {}

	bool Display() {
		cout<<"FIO = " << this->FIO<<endl;
		cout<<"Age = " << this->Age<<endl;
		prf2();
		return true;
	}
	bool SetAge(int _age) {
		if ((_age > 12) && (_age < 100)) {
			this->Age = _age;
			return true;
		}
		else {
			cout << "ERROR: Ti debil Age = " << _age << "??!!"<< endl;
			return false;
		}
		//try {
		//	this->Age /= 0;
		//}
		//catch (int error) {

		//}
	}
	int GetAge() {
		return this->Age;
	}

private:
	int Age;
	void pf1(){
		cout << "pf1" << endl;
	}

protected:
	void prf1() {
		cout << "pfr1" << endl;
	}
	void prf2() {
		cout << "pfr2" << endl;
		this->pmas[0] = &this->var1;
		this->pmas[1] = &this->var2;
	}
	void prf3() {
		cout << "pfr3" << endl;
	}

};


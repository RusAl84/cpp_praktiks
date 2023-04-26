#pragma once
#include <iostream>
using namespace std;
class ClassVar2
{
public:
	ClassVar2() {
		cout << "Class is Constructed!" << endl;
	}
	int Ekaterina;
	float var1;
	float var2;
	void lia() {
		pf1();
	}

private:
	void pf1() {
		cout << "pf1" << endl;
		float* pmas[2];
		pmas[0] = &this->pvar1;
		pmas[1] = &this->pvar2;
		
	}
	void pf2() {
		cout << "pf2" << endl;
	}
protected:
	float pvar1;
	float pvar2;
	void prf1() {
		cout << "prf1" << endl;
	}
	void prf2() {
		cout << "prf2" << endl;
	}
	void prf3() {
		cout << "prf3" << endl;
	}


};


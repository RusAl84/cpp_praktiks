#pragma once

using namespace std;

class ClassVar7
{
public: 
	int Age;
	int ShouzeSize;
	int* pmas [2];
	float SizeOfBolt;


	ClassVar7() {
		this->Age = 18;
	};

	ClassVar7(int tamila) {
		this->SetAge(tamila);
	};


	void Display(int jocker) {
		cout << "Age = " << this->Age << endl;
	};
	bool Setpmas() {
		this->pmas[0] = &this->Age;
		this->pmas[1] = &this->ShouzeSize;
		//this->pmas[0] = new int(46);
		*this->pmas[0]=46;
		return true;
	};



	bool SetAge(int x) {
		//try
		//{
		//	this->Age = 18 / x;
		//	throw 1;
		//}
		//catch (std::logic_error e) {
		//	cout << "Error set Age" << endl;
		//	this->Age = 0;
		//	return false;
		//};
		if ((x > 1) && (x < 200)) {
			this->Age = x;
			return true;
		}
		else
		{
			cout << "Error set Age" << endl;
			this->Age = 18;
			return false;
		}
	}

protected:
	int* pr[2];
	void prf1() {
		cout << "pf1" << endl;
	}

private:
	void pf1() {
		cout << "pf1" << endl;
	}
	void pf2() {
		cout << "pf2" << endl;
	}

};


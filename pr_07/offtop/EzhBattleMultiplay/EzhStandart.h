#pragma once
#include <iostream>
using namespace std;
class EzhStandart
{
private:
	string name;
	int Age;
public:
	void setName(string s) {
		name = s;
	}
	string getName() {
		return name;
	}
	EzhStandart(){
		name = "Стёпа";
		Age = 19;
	}

};


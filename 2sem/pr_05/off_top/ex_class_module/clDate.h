#pragma once
#include <iostream>
#include <string>

struct myDate {
	int day;
	int month;
	int year;
};

class clDate
{
private:
	myDate mydate;

public:
	char delimiter='/';

	clDate() {
		this->mydate.day = 1;
		this->mydate.month = 1;
		this->mydate.year = 1970;
	};

	void setDate(int _day, int _month, int _year) {
		this->mydate.day = _day;
		this->mydate.month = _month;
		this->mydate.year = _year;
	};

	void convertDate() {
		string resultStr1 = "";
		//string resultStr { "Hello METANIT.COM!" };
		/*string resultStr1 = "";*/

		//int _day = _mydate.day;
		//int _month = _mydate.month;
		//int _year = _mydate.year;

		//if (_day > 0 and _day < 10)
		//	resultStr += "0";
		//resultStr += _day;
		//resultStr += this->delimiter;

		//if (_month > 0 and _month < 10)
		//	resultStr += "0";
		//resultStr += _day;
		//resultStr += this->delimiter;

		//resultStr += _year;

		//return resultStr;
	}
	myDate getDate() {
		return mydate;
	};

	

	//void printDate()
	//{
	//	cout << convertDate(this->mydate);
	//}

	bool operator==(const clDate& other) const
	{
		return false;
	}
};


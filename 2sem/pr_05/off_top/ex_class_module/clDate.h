#pragma once
#include <iostream>
#include <string>
#define DATE_ERROR_LIMITS "Ошибка в дате"

using namespace std;

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
	}

	void setDate(int _day, int _month, int _year) {
		int feb_max = 28;
		if (_year % 4 == 0)
			feb_max = 29;
		int max_days[12] = { 31,feb_max, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((_month < 1) || (_month > 12))
			return;
		if ((_day < 1) || (_day > max_days[_month - 1]))
			return;
		if ((_year < 1970) || (_year > 3000))
			return;
		this->mydate.day = _day;
		this->mydate.month = _month;
		this->mydate.year = _year;
	}

	string convertDate(myDate _mydate) {
		string resultStr { "" };

		int _day = _mydate.day;
		int _month = _mydate.month;
		int _year = _mydate.year;

		if (_day > 0 and _day < 10)
			resultStr += "0";
		resultStr += to_string(_day);
		resultStr += this->delimiter;

		if (_month > 0 and _month < 10)
			resultStr += "0";
		resultStr += to_string(_month);
		resultStr += this->delimiter;

		resultStr += to_string(_year);

		return resultStr;
	}

	myDate getDate() {
		return mydate;
	};

	void printDate()
	{
		cout << endl << convertDate(this->mydate);
	}

	bool operator==(const clDate& other) const
	{
		return false;
	}
};


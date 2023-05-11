#pragma once
using namespace std;
struct Date {
	unsigned short day;
	unsigned short month;
	int year;
};

class clDate
{
private:
	unsigned short day;
	unsigned short month;
	int year;
public:
	/// <summary>
	/// Разделитель для даты (по умолчанию '.')
	/// </summary>

	char delimiter = '.';
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	clDate()
	{
		//this->day = 1;
		//this->month = 1;
		//this->year = 1970;
		setDate(1, 1, 1970);
	}
	/// <summary>
	/// Конструктор c возможностью задания даты
	/// </summary>
	/// <param name="_day"></param>
	/// <param name="_month"></param>
	/// <param name="_year"></param>
	clDate(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		setDate(_day, _month, _year);
	}
	//clDate(struct Date mD) { setDate(mD); }
	//clDate(struct Date* pD)
	//{
	//	day = pD->day; month = pD->month; year = pD->year;
	//}
	//~clDate() { ; }

	clDate getDate()
	{
		struct Date MD;
		MD.year = year;
		MD.month = month;
		MD.day = day;
	}

	void setDate(Date _mD)
	{
		setDate(_mD.day, _mD.month, _mD.year);
	}
	void setDate(unsigned short _day, unsigned short _month, unsigned short _year)
	{
		this->day = _day;
		this->month = _month;
		this->year = _year;
	}

	void printDate() {
		if (this->day > 0 and this->day < 10)
			cout << "0";
		cout << day << this->delimiter;
		if (this->month > 0 and this->month < 10)
			cout << "0";
		cout << month << this->delimiter << year << endl;
	}
};


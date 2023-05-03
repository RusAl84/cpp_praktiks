//Итоговое задание по практикам 0-4(5) (включая МЕНЮ)
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Record
{
	char author[25];
	char bookName[21];
	int year;
	char group;
	struct Date date;
	Record* next;
};
void myCentr(const char* s, int wLine)
{
	int w = strlen(s);
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta); cout << " ";
}
void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9)
	{
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;

	}
	else {
		cout << "0" << month;

	}
	cout << ".";
	cout << year;
	cout.width(delta);
	cout << " ";
}

void Draw(struct Record* table, int count)
{
	cout << endl;
	cout.width(94);
	cout.fill('-');
	cout << "-" << endl;
	cout.fill(' ');
	cout.width(93);
	cout << left << "|Каталог библиотеки";
	cout << "|" << endl;
	cout.width(94); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	cout << left << "|"; myCentr("Автор книги", 22);
	cout << left << "|"; myCentr("Название", 20);
	cout << left << "|"; myCentr("Год выпуска", 10);
	cout << left << "|"; myCentr("Группа", 10);
	cout << left << "|"; myCentr("Дата подписания рукописи", 33);





	cout << "|" << endl;
	cout.width(94); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	for (int i = 0; i < count; i++)
	{
		cout << left << "|"; cout.width(19); cout << left << table[i].author;
		cout << left << "|"; cout.width(18); cout << left << table[i].bookName;
		cout << left << "|"; cout.width(13); cout << left << table[i].year;
		cout << left << "|"; cout.width(8); cout << left << table[i].group;
		cout << left << "|";
		printDate(table[i].date.day, table[i].date.month, table[i].date.year, 33);
		cout << "|" << endl;

	}
	cout.width(94); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(81); cout << left << "|Примечание: Х - художественная литература; У - учебная литература; С - справочная литература";
	cout << "|" << endl;
	cout.width(94); cout.fill('-'); cout << "-" << endl;

}

int praktika1()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	struct Record table[10];
	table[0] = { "Борис Акунин", "Турецкий гамбит", 1998, 'Х', { 11, 11, 2020 } };
	table[1] = { "Стругацкие", "Пикник на обочине", 1978, 'У', { 11, 11, 2020 } };
	table[2] = { "Станислав Лем", "Футурологический ко", 1980, 'С', { 12, 12, 2010 } };

	int maxYear = table[0].year;
	int maxDay = table[0].date.day;
	int maxMonth = table[0].date.month;
	int maxYearDate = table[0].date.year;
	int maxIndex = 0;

	for (int i = 1; i < 3; i++) {
		if (table[i].year > maxYear) {
			maxYear = table[i].year;
			maxIndex = i;
		}
		if (table[i].date.day > maxDay) {
			maxDay = table[i].date.day;
			maxIndex = i;
		}
		if (table[i].date.month > maxMonth) {
			maxMonth = table[i].date.month;
			maxIndex = i;
		}
		if (table[i].date.year > maxYearDate) {
			maxYearDate = table[i].date.year;
			maxIndex = i;
		}
	}



	table[3] = { "max","max", maxYear, table[maxIndex].group, {maxDay, maxMonth, maxYearDate} };

	Draw(table, 4);
	return 0;
}


int praktika0() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char aftor1[25], aftor2[25], aftor3[25];
	char name1[21], name2[21], name3[21];
	unsigned short year1, year2, year3;
	char group1, group2, group3;

	cout << "Программа: Каталог библиотеки\n";

	cout << "\nПервая запись в таблице\n";
	cout << "Введите автора: ";
	cin.getline(aftor1, 25);
	cin.clear();
	_flushall();
	cout << "Введите наименование: ";
	cin.getline(name1, 21);
	cin.clear();
	_flushall();
	cout << "Введите год: ";
	while (!(cin >> year1)) {
		cout << "данные некорректны! Пожалуйста, попрубуйте снова!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();
	cout << "Введите группу: ";
	while (!(cin >> group1)) {
		cout << "Данные некорректны! Пожалуйста, попрубуйте снова!!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();
	cin.ignore();

	cout << "\nВторая запись в таблице\n";
	cout << "Введите автора: ";
	cin.getline(aftor2, 25);
	cin.clear();
	_flushall();
	cout << "Введите наименование: ";
	cin.getline(name2, 21);
	cin.clear();
	_flushall();
	cout << "Введите год: ";
	while (!(cin >> year2)) {
		cout << "Данные некорректны! Пожалуйста, попрубуйте снова!!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();
	cout << "Введите группа: ";
	while (!(cin >> group2)) {
		cout << "Данные некорректны! Пожалуйста, попрубуйте снова!!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();
	cin.ignore();

	cout << "\nТретья запись в таблице\n";
	cout << "Введите автора: ";
	cin.getline(aftor3, 25);
	cin.clear();
	_flushall();
	cout << "Введите наименование: ";
	cin.getline(name3, 21);
	cin.clear();
	_flushall();
	cout << "Введите год: ";
	while (!(cin >> year3)) {
		cout << "Данные некорректны! Пожалуйста, попрубуйте снова!!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();
	cout << "Введите группу: ";
	while (!(cin >> group3)) {
		cout << "Данные некорректны! Пожалуйста, попрубуйте снова!!\n";
		cin.clear();
		_flushall();
	}
	cin.clear();
	_flushall();

	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "| Каталог библиотеки                                                                           |\n";
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "|        Автор книги        |       Название        |      Год выпуска      |      Группа      |\n";
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "| " << setw(25) << aftor1 << " | " << setw(21) << name1 << " | " << setw(21) << year1 << " | " << setw(16) << group1 << " |\n";
	cout << "| " << setw(25) << aftor2 << " | " << setw(21) << name2 << " | " << setw(21) << year2 << " | " << setw(16) << group2 << " |\n";
	cout << "| " << setw(25) << aftor3 << " | " << setw(21) << name3 << " | " << setw(21) << year3 << " | " << setw(16) << group3 << " |\n";
	cout << "------------------------------------------------------------------------------------------------\n";
	cout << "| Примечание: Х - художественная литература; У - учебная литература; С - справочная литература |\n";
	cout << "------------------------------------------------------------------------------------------------\n";
	return 0;
}

int praktika2() {
	struct Record Table[] = {
	{ "Борис Акунин", "Турецкий гамбит", 1998, 'Х', {11, 11, 2020} },
	{ "Стругацкие", "Пикник на обочине", 1978, 'У', {11, 11, 2020} },
	{ "Станислав Лем", "Футурологический ко", 1980, 'С', {12, 12, 2010} }
	};

	int numRecords = sizeof(Table) / sizeof(Table[0]);

	int yearCount = 0;
	for (int i = 0; i < numRecords; i++) {
		yearCount += Table[i].year;
	}

	struct Record* A = (struct Record*)malloc(yearCount * sizeof(struct Record));
	if (A == NULL) {
		cout << "Ошибка при выделении памяти для массива A." << endl;
		return 1;
	}

	int indexA = 0;
	for (int i = 0; i < numRecords; i++) {
		for (int j = 0; j < Table[i].year; j++) {
			memcpy(&A[indexA], &Table[i], sizeof(struct Record));
			indexA++;
		}
	}

	struct Record* B = new struct Record[10];
	memcpy(B, A, 10 * sizeof(struct Record));

	struct Record* tempA = (struct Record*)realloc(A, 10 * sizeof(struct Record));
	if (tempA != NULL) {
		A = tempA;
	}

	cout << "Адрес массива Table: " << &Table << endl;
	cout << "Адрес массива A: " << A << endl;
	cout << "Адрес массива B: " << B << endl;

	cout << endl;

	cout << "Таблица значений:" << endl;
	cout << "Адрес A[i]\t\tЗначение A[i]->строковое_поле\tАдрес B[i]\t\tЗначение B[i]->строковое_поле" << endl;
	for (int i = 0; i < 10; i++) {
		cout << &A[i] << "\t" << A[i].author << "\t\t\t" << &B[i] << "\t" << B[i].author << endl;
	}

	free(A);
	delete[] B;

	return 0;
}




void printRecord(Record* record) {
	std::cout << "Author: " << record->author << std::endl;
	std::cout << "Book Name: " << record->bookName << std::endl;
	std::cout << "Year: " << record->year << std::endl;
	std::cout << "Group: " << record->group << std::endl;
	std::cout << "Date: " << record->date.day << "." << record->date.month << "." << record->date.year << std::endl;
	std::cout << "Address: " << record << std::endl;
	std::cout << "Next: " << record->next << std::endl;
	std::cout << std::endl;
}

void removeRecordsByDate(Record*& head, const Date& searchDate) {
	if (head == nullptr)
		return;

	Record* currentNode = head;
	Record* previousNode = nullptr;
	bool isFirstNodeRemoved = false;

	do {
		if (currentNode->date.day == searchDate.day &&
			currentNode->date.month == searchDate.month &&
			currentNode->date.year == searchDate.year) {
			Record* nodeToRemove = currentNode;

			if (nodeToRemove == head)
				isFirstNodeRemoved = true;

			currentNode = currentNode->next;

			if (previousNode != nullptr)
				previousNode->next = currentNode;

			delete nodeToRemove;
		}
		else {
			previousNode = currentNode;
			currentNode = currentNode->next;
		}
	} while (currentNode != head);

	if (isFirstNodeRemoved)
		head = currentNode;
	currentNode = head;

	do {
		printRecord(currentNode);
		currentNode = currentNode->next;
	} while (currentNode != head);

}

int praktika3() {
	struct Record table[3] = {
		{ "Сенкевич", "Потоп", 1978, 'Х', {11, 11, 2020}, nullptr },
		{ "Ландау", "Механика", 1989, 'У', {11, 11, 2020}, nullptr },
		{ "Дойль", "Сумчатые", 1990, 'С', {12, 12, 2010}, nullptr }
	};

	// Создание списка
	Record* head = nullptr;
	Record* tail = nullptr;

	for (int i = 0; i < 6; i++) {
		Record* newNode = new Record;
		strcpy_s(newNode->author, table[i % 3].author);
		strcpy_s(newNode->bookName, table[i % 3].bookName);
		newNode->year = table[i % 3].year;
		newNode->group = table[i % 3].group;
		newNode->date = table[i % 3].date;
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			tail = newNode;
			newNode->next = head;
		}
		else {
			tail->next = newNode;
			tail = newNode;
			newNode->next = head;
		}
	}

	// Вывод значений элементов списка
	Record* currentNode = head;

	do {
		printRecord(currentNode);
		currentNode = currentNode->next;
	} while (currentNode != head);
	cout << "Введите дату для поиска день месяц код" << endl;
	Date newDate;
	cin >> newDate.day >> newDate.month >> newDate.year;

	cout << "Вывод после удаления:" << endl;
	removeRecordsByDate(head, newDate);

	// Освобождение памяти
	currentNode = head;

	do {
		Record* temp = currentNode;
		currentNode = currentNode->next;
		delete temp;
	} while (currentNode != head);

	return 0;
}


#include <fstream>
#include <sstream>

void writeRecordsToTextFile(const char* filename, Record* records, int count) {
	std::ofstream file(filename);

	if (file.is_open()) {
		for (int i = 0; i < count; i++) {
			file << records[i].author << " "
				<< records[i].bookName << " "
				<< records[i].year << " "
				<< records[i].group << " "
				<< records[i].date.day << " "
				<< records[i].date.month << " "
				<< records[i].date.year << "\n";
		}

		file.close();
		std::cout << "Records have been written to the text file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the text file." << std::endl;
	}
}

void readRecordsFromTextFile(const char* filename) {
	std::ifstream file(filename);

	if (file.is_open()) {
		Record record;
		while (file >> record.author
			>> record.bookName
			>> record.year
			>> record.group
			>> record.date.day
			>> record.date.month
			>> record.date.year) {
			std::cout << "Author: " << record.author << std::endl;
			std::cout << "Book Name: " << record.bookName << std::endl;
			std::cout << "Year: " << record.year << std::endl;
			std::cout << "Group: " << record.group << std::endl;
			std::cout << "Date: " << record.date.day << "." << record.date.month << "." << record.date.year << std::endl;
			std::cout << std::endl;
		}

		file.close();
		std::cout << "Records have been read from the text file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the text file." << std::endl;
	}
}

void writeRecordsToBinaryFile(const char* filename, Record* records, int count) {
	std::ofstream file(filename, std::ios::binary);

	if (file.is_open()) {
		file.write(reinterpret_cast<const char*>(records), sizeof(Record) * count);
		file.close();
		std::cout << "Records have been written to the binary file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the binary file." << std::endl;
	}
}

void readRecordsFromBinaryFile(const char* filename) {
	std::ifstream file(filename, std::ios::binary);

	if (file.is_open()) {
		Record record;
		while (file.read(reinterpret_cast<char*>(&record), sizeof(Record))) {
			std::cout << "Author: " << record.author << std::endl;
			std::cout << "Book Name: " << record.bookName << std::endl;
			std::cout << "Year: " << record.year << std::endl;
			std::cout << "Group: " << record.group << std::endl;
			std::cout << "Date: " << record.date.day << "." << record.date.month << "." << record.date.year << std::endl;
			std::cout << std::endl;
		}

		file.close();
		std::cout << "Records have been read from the binary file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the binary file." << std::endl;
	}
}
void addRecordToTextFile(const char* filename) {
	std::ofstream file(filename, std::ios::app);

	if (file.is_open()) {
		Record record;
		std::cout << "Enter author: ";
		std::cin.getline(record.author, sizeof(record.author));
		std::cout << "Enter book name: ";
		std::cin.getline(record.bookName, sizeof(record.bookName));
		std::cout << "Enter year: ";
		std::cin >> record.year;
		std::cout << "Enter group: ";
		std::cin >> record.group;
		std::cout << "Enter day: ";
		std::cin >> record.date.day;
		std::cout << "Enter month: ";
		std::cin >> record.date.month;
		std::cout << "Enter year: ";
		std::cin >> record.date.year;

		file << record.author << " "
			<< record.bookName << " "
			<< record.year << " "
			<< record.group << " "
			<< record.date.day << " "
			<< record.date.month << " "
			<< record.date.year << "\n";

		file.close();
		std::cout << "Record has been added to the text file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the text file." << std::endl;
	}
}

void swapText(const char* filename) {
	std::ifstream file(filename);

	if (file.is_open()) {
		Record record;
		while (file >> record.author
			>> record.bookName
			>> record.year
			>> record.group
			>> record.date.day
			>> record.date.month
			>> record.date.year) {
			std::cout << "Author: " << record.author << std::endl;
			std::cout << "Book Name: " << record.bookName << std::endl;
			std::cout << "Year: " << record.year << std::endl;
			std::cout << "Group: " << record.group << std::endl;
			std::cout << "Date: " << record.date.day << "." << record.date.month << "." << record.date.year << std::endl;
			std::cout << std::endl;
		}

		file.close();
		std::cout << "Records have been read from the text file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the text file." << std::endl;
	}
}
void swapStringValuesInFile(const char* filename) {
	std::fstream file(filename, std::ios::in | std::ios::out);

	if (file.is_open()) {
		// Пропустим две первые записи
		std::string line;
		std::getline(file, line);
		std::getline(file, line);

		// Считываем значения третьей записи
		std::streampos pos1 = file.tellg();
		std::getline(file, line);

		// Считываем значения четвёртой записи
		std::streampos pos2 = file.tellg();
		std::getline(file, line);

		// Перемещаем указатель чтения/записи к началу четвёртой записи
		file.seekg(pos2);

		// Записываем значения третьей записи на место четвёртой записи
		file << line << std::endl;

		// Перемещаем указатель чтения/записи к началу третьей записи
		file.seekg(pos1);

		// Записываем значения четвёртой записи на место третьей записи
		file << line << std::endl;

		file.close();
		std::cout << "String values have been swapped in the file successfully." << std::endl;
	}
	else {
		std::cout << "Failed to open the file." << std::endl;
	}
}

int praktika4() {
	struct Record table[3] = {
	{ "Борис Акунин", "Турецкий гамбит", 1998, 'Х', {11, 11, 2020}, nullptr },
	{ "Стругацкие", "Пикник на обочине", 1978, 'У', {11, 11, 2020}, nullptr },
	{ "Станислав Лем", "Футурологический ко", 1980, 'С', {12, 12, 2010}, nullptr }
	};

	writeRecordsToTextFile("text.txt", table, 3);

	std::cout << "Чтение текстового файла:" << std::endl;
	readRecordsFromTextFile("text.txt");
	std::cout << std::endl;
	writeRecordsToBinaryFile("text.bin", table, 3);

	std::cout << "Чтение бинарного файла:" << std::endl;
	readRecordsFromBinaryFile("text.bin");
	std::cout << std::endl;

	cout << "Ввод нового элемента для текстового файла:" << endl;
	addRecordToTextFile("kondin.txt");

	std::cout << "Reading from text file:" << std::endl;
	readRecordsFromTextFile("text.txt");
	std::cout << std::endl;

	swapStringValuesInFile("text.txt");

	std::cout << "Reading from text file:" << std::endl;
	readRecordsFromTextFile("text.txt");
	std::cout << std::endl;
	return 0;
}

class clDate {
private:
	int day;
	int month;
	int year;

public:
	clDate() {
		day = 1;
		month = 1;
		year = 2000;
	}

	clDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	clDate(const Date& date) {
		day = date.day;
		month = date.month;
		year = date.year;
	}

	void setDate(int d, int m, int y) {
		day = d;
		month = m;
		year = y;
	}

	Date getDate() const {
		Date date;
		date.day = day;
		date.month = month;
		date.year = year;
		return date;
	}
};

class clRecord {
public:
	std::string bookName;
	int year;

protected:
	char group;

private:
	std::string author;
	struct Date date;

public:
	clRecord() {
		author = "";
		bookName = "";
		year = 0;
		group = '\0';
		date.day = 1;
		date.month = 1;
		date.year = 2000;
	}

	clRecord(const std::string& filename) {
		// Чтение данных из файла и инициализация полей объекта
	}

	clRecord(const Record* record) {
		author = record->author;
		bookName = record->bookName;
		year = record->year;
		group = record->group;
		date.day = record->date.day;
		date.month = record->date.month;
		date.year = record->date.year;
	}

	void setAuthor(const std::string& authorName) {
		author = authorName;
	}

	std::string getAuthor() const {
		return author;
	}

	void setGroup(const char& grp) {
		group = grp;
	}

	char getGroup() const {
		return group;
	}

	// Методы чтения/записи значений данных-членов класса (при необходимости)

	void printRecord() const {
		std::cout << "Author: " << author << std::endl;
		std::cout << "Book Name: " << bookName << std::endl;
		std::cout << "Year: " << year << std::endl;
		std::cout << "Group: " << group << std::endl;
		std::cout << "Date: " << date.day << "/" << date.month << "/" << date.year << std::endl;
	}
};

int praktika5() {
	clDate staticDate; // Статический объект класса clDate с использованием конструктора по умолчанию
	clDate staticDate2(10, 5, 2023); // Статический объект класса clDate с использованием конструктора с параметрами

	Date dynamicDate = { 15, 8, 2023 };
	clDate* dynamicDateObj = new clDate(dynamicDate); // Динамический объект класса clDate с использованием конструктора с параметрами

	clDate copyDate(*dynamicDateObj); // Создание объекта на основе конструктора
	copyDate.setDate(copyDate.getDate().day + 5, copyDate.getDate().month, copyDate.getDate().year);

	// Контроль допустимости новой даты
	if (copyDate.getDate().day > 31 || copyDate.getDate().month > 12) {
		std::cout << "Недопустимая дата. Оставляю прежнюю дату." << std::endl;
		copyDate.setDate(dynamicDateObj->getDate().day, dynamicDateObj->getDate().month, dynamicDateObj->getDate().year);
	}

	// Создание объекта класса clRecord
	clRecord recordObj;
	recordObj.setAuthor("Борис Акунин");
	recordObj.bookName = "Турецкий гамбит";
	recordObj.year = 1998;
	recordObj.setGroup('Х');
	recordObj.printRecord();

	// Создание массива объектов класса clRecord
	const int arraySize = 3;
	clRecord recordArray[arraySize] = {
	};
	recordArray[0].setAuthor("Борис Акунин");
	recordArray[0].bookName = "Турецкий гамбит";
	recordArray[0].year = 1998;
	recordArray[0].setGroup('Х');
	recordArray[0].printRecord();
	recordArray[1].setAuthor("Стругацкие");
	recordArray[1].bookName = "Пикник на обочине";
	recordArray[1].year = 1978;
	recordArray[1].setGroup('У');
	recordArray[1].printRecord();
	recordArray[2].setAuthor("Станислав Лем");
	recordArray[2].bookName = "Футурологический конгресс";
	recordArray[2].year = 1980;
	recordArray[2].setGroup('С');
	recordArray[2].printRecord();
	return 0;
}

void menu() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = -1;
	while (menu != 0) {
		cout << "Введите значение от 0 до 6:" << endl;
		cout << "0: Выход" << endl;
		cout << "1: Практика 0" << endl;
		cout << "2: Практика 1" << endl;
		cout << "3: Практика 2" << endl;
		cout << "4: Практика 3" << endl;
		cout << "5: Практика 4" << endl;
		cout << "6: Практика 5" << endl;
		cin >> menu;
		system("cls");
		switch (menu)
		{
			case 0: break;
			case 1: praktika0(); break;
			case 2: praktika1(); break;
			case 3: praktika2(); break;
			case 4: praktika3(); break;
			case 5: praktika4(); break;
			case 6: praktika5(); break;
			default:
				cout << "Введите другое значение. Вы ввели: " << menu << " Должно быть в диапазоне от 0 до 6"  << endl;
				break;
		}
	}
}


int main()
{
	menu();
}


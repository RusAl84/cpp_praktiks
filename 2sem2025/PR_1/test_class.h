#pragma once
using namespace std;

// ������� ���������� ������ ��������� � ���� ��������� ������ :
// ����������� ������ � � ������������ �����(���������� "h"), 
// ������� ����������� ������������ ������� � ������������� 
// ������� � � ����� � ����������� �����(���������� "cpp").
// ��� ��������� �� ����� h �  cpp 
//https://learn.microsoft.com/ru-ru/cpp/cpp/header-files-cpp?view=msvc-170


class test_class
{
public:
	//2. ����� ������ ��������� ����������� �� ���������, ����������� � �� - 
	// ��������(�������� ������������ � ���������� ��������� ������������� �������), 
	// ����������� �����������.����� ���� � ������ ������������ ������� ������ ������ 
	// ������� ����������.
	test_class() = default; //����������� �� ���������
	test_class(int size);   
	// ����������� �����������  
	// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
	test_class(const test_class& t);  
	~test_class();  


	void setElement(int ind, int x);
	int getElement(int ind);
	int getSize();
	void display();
	void author();
	// https://metanit.com/cpp/tutorial/5.14.php?ysclid=m761vuw5f9931647360
	bool operator==(const test_class& _other) const;
	bool operator < (const test_class& _other);
	friend bool operator-- ();
private:
	//1. ������ ������������ ������ ������ ������ ���������� 
	// ����������� �������� ������� ������������� �������
	// (�.�.������������ �������� - ���� ������).
	// ������������ ������ ������ ������ ���� ��������� � 
	// �������� ����� ������.
	int size; // ������ ������������� �������
	int *numbers; // ��������� �� ������������ ������
	
};


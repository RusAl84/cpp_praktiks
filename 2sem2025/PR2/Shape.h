#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class Shape
{
protected:
    char* name;
public:
	Shape() 
	{
        //name = "������ �� ����������";
        name = new char[40];
        strcpy_s(name, sizeof(name), "������ �� ����������");
	};
    Shape(const char* _name)
    {
        this->name = new char[40];
        strcpy_s(this->name, 40, _name);
    }
    virtual ~Shape()
    {
        delete[] name;
    }
    virtual double Area() const = 0;
    virtual double Perimetr() const = 0;
    //���������� ������� ��� ������ ������������� ������� � ����;
    void SaveToFIle(ofstream& out_file) const
    {
        if (!out_file.is_open())
        {
            cout << "������ �������� �����" << endl;
        }
        else
        {
            out_file << "������: " << name;
            out_file << endl << "�������: " << Area();
            out_file << endl << "��������: " << Perimetr();
            out_file << endl << "----------------------" << endl  ;
        }
    }
    void display()
    {
        cout << name;
    }
};


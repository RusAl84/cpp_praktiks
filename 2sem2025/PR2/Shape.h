#pragma once
#include <stdio.h>
#include <iostream>
#include <fstream>
class Shape
{
protected:
    char* name;
public:
	Shape() 
	{
        //name = "������ �� ����������";
        name = new char[40];
        strcpy(name, "������ �� �����������");
        strcpy_s(name, sizeof(name), "������ �� ����������");
	};
    Shape(const char* name)
    {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
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
            out_file << "\n�������: " << Area();
            out_file << "\n��������: " << Perimetr();
            out_file << "\n----------------------\n";
        }
    }

};


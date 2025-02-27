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
        //name = "Фигура не определена";
        name = new char[40];
        strcpy_s(name, sizeof(name), "Фигура не определена");
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
    //глобальную функцию для записи компонентного массива в файл;
    void SaveToFIle(ofstream& out_file) const
    {
        if (!out_file.is_open())
        {
            cout << "Ошибка открытия файла" << endl;
        }
        else
        {
            out_file << "Фигура: " << name;
            out_file << endl << "Площадь: " << Area();
            out_file << endl << "Периметр: " << Perimetr();
            out_file << endl << "----------------------" << endl  ;
        }
    }
    void display()
    {
        cout << name;
    }
};


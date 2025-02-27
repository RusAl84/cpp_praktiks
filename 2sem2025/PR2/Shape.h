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
        //name = "Фигура не определена";
        name = new char[40];
        strcpy(name, "Фигура не определенна");
        strcpy_s(name, sizeof(name), "Фигура не определена");
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
            out_file << "\nПлощадь: " << Area();
            out_file << "\nПериметр: " << Perimetr();
            out_file << "\n----------------------\n";
        }
    }

};


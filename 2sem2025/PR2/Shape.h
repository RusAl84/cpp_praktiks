#pragma once
#include <stdio.h>
class Shape
{
public:
	Shape() 
	{
        strcpy_s(name, sizeof(name), "������ �� ����������");

	};
    //���������� ������� ��� ������ ������������� ������� � ����;
    void SaveToFile() {
        // stdio.h
        FILE* textFile;
        fopen_s(&textFile, "log.txt", "w+");
        if (textFile) {
            fprintf(textFile, "%d %\n", name);
        }
    }
private:
	char* name;
};


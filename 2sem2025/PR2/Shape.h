#pragma once
#include <stdio.h>
class Shape
{
public:
	Shape() 
	{
        //name = "������ �� ����������";
        int size = 30;
        name = (char*)malloc(sizeof(char) * size);
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
	char* name ="f";
};


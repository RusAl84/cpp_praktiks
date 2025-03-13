#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "StringWorker.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "Практическая работа 3\n";
    auto author = []()
        {
            cout << "Русаков Алексей БИСО-02-24" << endl;
        };
    author();
    // Работа со строками
    // https://metanit.com/cpp/tutorial/12.1.php
    // https://metanit.com/cpp/tutorial/12.9.php
    // https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
    // Traverse till stream is valid
    // while (my_stream >> token) {
    // чтобы ещё знать https://www.geeksforgeeks.org/class-stdstring_view-in-cpp-17/?ref=ml_lbp
    StringWorker* sw = new StringWorker("    Вышел ёжик и пошел гулять с капибарой. Капибара бросила    ");
    sw->loadFile("data.txt"); // загрузка строки из файла task_3.txt
    cout << endl << "Исходная строка:" << endl;
    cout << *sw << endl; // перегруженный вывод объекта
    // Разработать метод, который позволяет упорядочить слова исходной строки
    // по возрастанию их длины. Вывести на экран и в результирующий файл 
    // строку, состоящую из слов в упорядоченном виде.
    vector<string> words = sw->sortedWords();
    cout << endl << "Отсортированная строка:" << endl;
    for (const auto& word : words) {
        cout << word << endl;
    }
    sw->writeResultsToFile("out.txt"); 
    return 0;
}
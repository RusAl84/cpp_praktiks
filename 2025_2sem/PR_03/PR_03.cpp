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
    // 8 вар. Разработать метод, который позволяет упорядочить слова исходной строки
    // по возрастанию их длины. Вывести на экран и в результирующий файл 
    // строку, состоящую из слов в упорядоченном виде.
    vector<string> words = sw->sortedWords_var8();
    cout << endl << "Отсортированная строка 8 вариант:" << endl;
    for (const auto& word : words) 
        cout << word << " ";
    sw->writeResultsToFile("out_var8.txt", words);
    // 12 вар. Разработать метод, выделяющий из исходной строки слова, являющиеся 
    // положительными шестнадцатеричными константами С++.
    words.clear();
    words = sw->hex_var12();
    cout << endl << "Отсортированная строка 12 вариант:" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out_var12.txt", words);
    // 16 вар Разработать метод, который позволяет отсортировать слова исходной строки 
    // по убыванию их длины, используя для этого алгоритм сортировки вставками. 
    // Вывести на экран и в результирующий файл строку, состоящую из слов в 
    // упорядоченном виде.
    words.clear();
    words = sw->sortedWords_var16();
    cout << endl << "Отсортированная строка 16 вариант:" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out_var16.txt", words);
    // 21 вар Разработать метод, переворачивающий слова 
    // в предложении. Например, 
    // "Мама мыла раму" – "амаМ алым умар".
    words.clear();
    words = sw->ReverseWords_var21();
    cout << endl << "Отсортированная строка 21 вариант:" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out_var21.txt", words);
    // 26 вар. Разработать метод, который в исходной строке 
    // находит самое короткое и самое длинное слово. 
    // Результат – строка, в которой найденное самое 
    // короткое слово размещено в ее начале, а найденное 
    // самое длинное – в конце.
    words.clear();
    words = sw->ExtractWords_var26();
    cout << endl << "Отсортированная строка 26 вариант:" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out_var26.txt", words);
    // 4 вар. Разработать метод, выделяющий из исходной строки слова, 
    // являющиеся целыми десятичными константами С++.
    words.clear();
    words = sw->dec_var4();
    cout << endl << "Отсортированная строка 4 вариант:" << endl;
    for (const auto& word : words)
        cout << word << " ";
    sw->writeResultsToFile("out_var4.txt", words);
    return 0;
}
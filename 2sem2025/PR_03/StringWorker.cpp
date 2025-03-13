#include "StringWorker.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
//Класс должен содержать конструктор по умолчанию, 
StringWorker::StringWorker() = default;
// конструктор с параметром, 
StringWorker::StringWorker(const string& str) : str(str) {}
// конструктор копирования, 
// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
StringWorker::StringWorker(const StringWorker& _other)
{
	str = _other.str;
}
// перегруженную операцию присваивания, 
bool StringWorker::operator==(const StringWorker& _other) const
{
	return str == _other.str;
}
// вывод на экран исходной строки;
string StringWorker::getStr()
{
    return str;
}
ostream& operator<<(ostream& out, const StringWorker& _other) {
    return out << _other.str << endl;
}
// перегруженную операцию вывода содержимого объекта в поток.
void StringWorker::loadFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        getline(file, str);
        file.close();
        cout << " Файл прочитан" << endl;
    }
    else {
        cerr << " Файл с данными открыть не удалось" << filename << endl;
    }
}
vector<string> StringWorker::sortedWords() {
    vector<string> words;
    vector<int> lens;
    // https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
    // Traverse till stream is valid
    // while (my_stream >> token) {
    // чтобы ещё знать https://www.geeksforgeeks.org/class-stdstring_view-in-cpp-17/?ref=ml_lbp
    istringstream my_stream(str);
    string word;
    while (my_stream >> word) {
        if (!word.empty() ) {
            lens.push_back(word.length());
            words.push_back(word);
        }
    }
    // Sort vector in descending order
    sort(lens.begin(), lens.end());
    //cout << endl;
    //for (auto i : lens)
    //    cout << i << " ";
    vector<string> sorted_words;
    for (auto l : lens)
        for (auto i = 0; i < words.size(); i++) 
            if (words[i].length() == l)
            {
                sorted_words.push_back(words[i]);
                words.erase(words.begin() + i);
                break;
            }
    return sorted_words;
}
void StringWorker::writeResultsToFile(const string& filename) {
    ofstream file(filename); // Открываем файл для добавления данных
    if (file.is_open()) {
        vector<string> words = sortedWords();
        file << endl << " Отсортированная строка:" << endl;
        for (const auto& word : words) {
            file << word << endl;
        }
        file.close();
        cout << endl << "Результаты успешно записаны в файл: " << filename << endl;
    }
    else {
        cerr << endl << "Не удалось открыть файл для записи: " << filename << endl;
    }
}
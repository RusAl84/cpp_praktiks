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
vector<string> StringWorker::sortedWords_var8() {
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
vector<string> StringWorker::hex_var12() {
    istringstream my_stream(str);
    string word;
    vector<string> valid_words;
    string hexChars = "0123456789abcdefABCDEFx";
    while (my_stream >> word) {
        if (!word.empty()) {
            int countValidChar = 0;
            for (auto ind = 0; ind < word.size(); ind++) {
                for (auto i = 0; i < hexChars.size(); i++) {
                    if (word[ind] == hexChars[i])
                    {
                        countValidChar++;
                        break;
                    }
                }
            }
            if (word.size()== countValidChar)
                valid_words.push_back(word);
        }
    }
    return valid_words;
}
//  отсортировать слова исходной строки 
// по убыванию их длины, используя для этого алгоритм сортировки вставками.
// https://www.geeksforgeeks.org/cpp-program-for-insertion-sort/
vector<int> insertionSort(vector<int> arr)
{
    int n = arr.size();
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1],
        // that are greater than key, to one
        // position ahead of their
        // current position
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}
vector<string> StringWorker::sortedWords_var16() {
    vector<string> words;
    vector<int> lens;
    // https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
    // Traverse till stream is valid
    // while (my_stream >> token) {
    // чтобы ещё знать https://www.geeksforgeeks.org/class-stdstring_view-in-cpp-17/?ref=ml_lbp
    istringstream my_stream(str);
    string word;
    while (my_stream >> word) {
        if (!word.empty()) {
            lens.push_back(word.length());
            words.push_back(word);
        }
    }
    // отсортировать слова исходной строки 
    // по убыванию их длины, используя для этого алгоритм сортировки вставками.
    lens = insertionSort(lens);
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
void StringWorker::writeResultsToFile(const string& filename, vector<string> words) {
    ofstream file(filename); // Открываем файл для добавления данных
    if (file.is_open()) {
        //vector<string> words = sortedWords_var8();
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
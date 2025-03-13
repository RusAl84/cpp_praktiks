#include "StringWorker.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
//����� ������ ��������� ����������� �� ���������, 
StringWorker::StringWorker() = default;
// ����������� � ����������, 
StringWorker::StringWorker(const string& str) : str(str) {}
// ����������� �����������, 
// https://metanit.com/cpp/tutorial/5.17.php?ysclid=m75yug6sg0141565775
StringWorker::StringWorker(const StringWorker& _other)
{
	str = _other.str;
}
// ������������� �������� ������������, 
bool StringWorker::operator==(const StringWorker& _other) const
{
	return str == _other.str;
}
// ����� �� ����� �������� ������;
string StringWorker::getStr()
{
    return str;
}
ostream& operator<<(ostream& out, const StringWorker& _other) {
    return out << _other.str << endl;
}
// ������������� �������� ������ ����������� ������� � �����.
void StringWorker::loadFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        getline(file, str);
        file.close();
        cout << " ���� ��������" << endl;
    }
    else {
        cerr << " ���� � ������� ������� �� �������" << filename << endl;
    }
}
vector<string> StringWorker::sortedWords() {
    vector<string> words;
    vector<int> lens;
    // https://www.geeksforgeeks.org/processing-strings-using-stdistringstream/
    // Traverse till stream is valid
    // while (my_stream >> token) {
    // ����� ��� ����� https://www.geeksforgeeks.org/class-stdstring_view-in-cpp-17/?ref=ml_lbp
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
    ofstream file(filename); // ��������� ���� ��� ���������� ������
    if (file.is_open()) {
        vector<string> words = sortedWords();
        file << endl << " ��������������� ������:" << endl;
        for (const auto& word : words) {
            file << word << endl;
        }
        file.close();
        cout << endl << "���������� ������� �������� � ����: " << filename << endl;
    }
    else {
        cerr << endl << "�� ������� ������� ���� ��� ������: " << filename << endl;
    }
}
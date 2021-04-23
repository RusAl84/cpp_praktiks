// pr10_offtop.cpp : Пример комментариев
// rusal84

#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Функция отправки в армию
/// </summary>
/// <param name="groupName">Наименование группы студентов (БАСО-01-20)</param>
/// <returns>Число годных новобранцев</returns>
int goArmy(string groupName) {
    return 10;
}

int main()
{
    int countRecruit = goArmy("БАСО-05-20");
    std::cout << "Hello World!\n";
}

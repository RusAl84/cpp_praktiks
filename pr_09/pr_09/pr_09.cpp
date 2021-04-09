#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static void display(string filename) {
    string line;
    ifstream in(filename); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::cout << line << std::endl;
        }
    }
    in.close();     // закрываем файл
}
// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    setlocale(LC_ALL, "");
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        int count = 10;
        for(int i=0;i<count;i++){
            int random_number = getRandomNumber(1,100000);
            out << random_number << std::endl;
        }  
    }
    out.close();
    cout << "Файл сгенерирован: " << endl;
    display("D:\\hello.txt");
    cout << "Выполненное задание: " << endl;
    string line;
    ifstream in("D:\\hello.txt"); // окрываем файл для чтения



    //    Записать в файл g комментарий.
    out.open("D:\\out.txt"); // окрываем файл для запис
    if (in.is_open())
    {
        while (getline(in, line))
        {
           /* std::cout << line << std::endl;*/
            int number = atoi(line.c_str());
            string comment = " //";
            //cout << number << endl;
            //1. являющиеся четными числами;
            if (number % 2 == 0) {
                comment += " чётное число";
            }
            //2. делящиеся на 3 и не делящиеся на 7;
            if ((number % 3 == 0) && !(number % 7 == 0)) {
                if (comment == " //") 
                    comment = " // делится на 3 и не делится на 7";
                else
                    comment += ", делится на 3 и не делится на 7";
            }
            //3. являющиеся точными квадратами.
            bool flag = false;
            for (int i = 0; i < 50; i++) {
                int sqr = i * i;
                if (number == sqr) {
                    flag = true;
                }
            }
            if (flag) {
                if (comment == " //")
                    comment = " // точный квадрат";
                else
                    comment += ", точный квадрат";
            }
            if (comment == " //") {
                comment = "";
            }
            out << number << comment << endl;
        }
    }
    out.close();
    in.close();     // закрываем файл
    display("D:\\out.txt");
}


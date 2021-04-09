#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

static void display(string filename) {
    string line;
    ifstream in(filename); // окрываем файл для чтения
    if (in.is_open())
        while (getline(in, line))
            std::cout << line << std::endl;
    in.close();     // закрываем файл
}
// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
static int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}
static double getRandomdoubleNumber (double LO, double HI)
{
    return LO + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (HI - LO)));
}
static void var7() {
    int count = 10; // Количество записей
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < count; i++) {
            int random_number = getRandomNumber(100, 700);
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
    out.open("D:\\out.txt"); // окрываем файл для записи
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


static void var1() {
    int count = 10; // Количество записей
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < count; i++) {
            int random_number = getRandomNumber(0, 10);
            out << random_number << std::endl;
        }
    }
    out.close();
    std::cout << "Файл сгенерирован: " << endl;
    display("D:\\hello.txt");
    std::cout << "Выполненное задание: " << endl;
    string line;
    ifstream in("D:\\hello.txt"); // окрываем файл для чтения
    //    Записать в файл g комментарий.
    out.open("D:\\out.txt"); // окрываем файл для записи
    if (in.is_open())
    {
        vector <int> ve;
        while (getline(in, line))
        {
            /* std::cout << line << std::endl;*/
            int number = atoi(line.c_str());
            //string comment = " //";
            //out << number << comment << endl;
            ve.insert(ve.begin(), number);
        }
        map <int, int> m;
        for (auto const& x : ve) 
            m[x] = 0;
        for (auto const&  x : ve)
            m[x] += 1;
        for (const auto& kv : m) {
            std::cout << kv.first << " has value " << kv.second << std::endl;
        }
        int index=0;
        vector <int> ve1;
        for (int x : ve){
            int val = m[x];
            if (val < 2)
                ve1.insert(ve.begin(), x);
        }
        for (int x : ve1)
            std::cout << x << endl;
    }
    out.close();
    in.close();     // закрываем файл
    display("D:\\out.txt");
}


static void var2() {
    int count = 10; // Количество записей
    std::ofstream out;          // поток для записи
    out.open("D:\\hello.txt"); // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < count; i++) {
            double random_number = getRandomdoubleNumber(0.05, 0.7);
            out << random_number << endl;
        }
    }
    out.close();
    cout << "Файл сгенерирован: " << endl;
    display("D:\\hello.txt");
    cout << "Выполненное задание: " << endl;
    //Найти:
    //5. разность первой и последней компоненты файла f.
    string line;
    ifstream in("D:\\hello.txt"); // окрываем файл для чтения
    //    Записать в файл g комментарий.
    out.open("D:\\out.txt"); // окрываем файл для записи
    if (in.is_open())
    {
        double max_num = -10000;
        double max_abs_num = -10000;
        double min_num_u = 10000;
        double min_num = 10000;
        double first_num;
        double last_num;
        bool flag = true;
        while (getline(in, line))
        {
            if (flag) {
                flag = false;
                first_num = atof(line.c_str());
            }
            /* std::cout << line << std::endl;*/
            double number = std::stof(line.c_str());
            std::cout << number << std::endl;
            string comment = " //";
            //1. наибольшее из значений компонентов f;
            if (number > max_num)
                max_num = number;
            //2. наименьшее из значений компонентов с четными номерами;
            if ((int)number % 2 == 0)
                if (number < min_num_u)
                    min_num_u = number;
            //3. наибольшее из значений модулей компонентов с нечетными номерами;
            if ((int)number % 2 == 1)
                if (abs(number) > max_abs_num)
                    max_abs_num = abs(number);
            //4. сумму наибольшего и наименьшего из значений компонентов файла f;
            if (number < min_num)
                min_num = number;
            //out << number << comment << endl;
            last_num = number;
        }
        cout << "1. наибольшее из значений компонентов f: " << max_num << endl;
        cout << "2. наименьшее из значений компонентов с четными номерами: " << min_num_u << endl;
        cout << "3. наибольшее из значений модулей компонентов с нечетными номерами: " << max_abs_num << endl;
        cout << "4. сумму наибольшего и наименьшего из значений компонентов файла f: " << max_num - min_num << endl;
        cout << "5. разность первой и последней компоненты файла f:" << first_num - last_num << endl;

    }
    out.close();
    in.close();     // закрываем файл
    display("D:\\out.txt");
}





int main()
{
    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
    setlocale(LC_ALL, "");
    var1();
}


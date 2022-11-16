#include <iostream>
#include <ctime>

using namespace std;
const int n = 8;
const int m = 3;
const int firs_value = 1;
const int last_value = 10;

int genRand() {
    // формула генерации случайных чисел по заданному диапазону
    // где firs_value - минимальное число из желаемого диапазона
    // last_value - ширина выборки
    if (rand()> RAND_MAX/2)
        return firs_value + rand() % last_value;
    else
        return (-1)*(firs_value + rand() % last_value);
}

void genNumbers(int numbers[n][m], int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            numbers[i][j] = genRand();
}

void displayNumbers(int numbers[n][m], int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << " " << numbers[i][j];
        cout << "\n";
    }
}

int main()
{
    srand(time(0)); // автоматическая рандомизация
    //Общее задание : осуществить ввод размерности двумерного массива, его элементов с
    //клавиатуры (можно предположить, что максимальная размерность входного массива
    //не более чем 10 на 10).
    // существлять вывод на экран входного массива, результата
    //работы, а также всех промежуточных решений
    // 
    //Вариант работы выбирается по 2 - м последним цифрам студенческого билета(всего
    //    вариантов 15 с 0 - го по 14 - й).
    // Например : последние цифры 12 – 12 вариант; последние
    //цифры 39 вариант – 39 - 15 * 2 = 39 - 30 = 9 вариант; последние цифры 82 вариант – 82 -
    //15 * 5 = 82 - 75 = 7 вариант
    //Номер варианта с текстом задания разместить в начале программы.
    // 
    //Файл именовать : Фамилия_И_О_номерварианта(пример : Семенов_П_С_11
    

    int numbers[n][m];
    genNumbers(numbers,n,m);
    displayNumbers(numbers, n, m);

    //Вариант 6
    //Дан двумерный массив, размером(n⋅на⋅m).
    //Найти максимальный элемент в каждой строке матрицы
    //среди отрицательных элементов.
    //Затем все положительные элементы каждой строки заменить на
    //соответствующий найденный максимальный элемент.
    //При отсутствии положительных элементов в
    //строке данную строку заменить строкой, содержащей минимальный из максимальных
    //отрицательных элементов
    
    //Инициализация массива для хранения максимальных из отрицательных элементов по строкам
    int minus_inf= -1 * last_value - 1;
    int max_elements[n];
    for (int i = 0; i < n; i++)
        max_elements[i] = minus_inf;
    // Заполнение массива максимальными элементами по строкам
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((numbers[i][j] > max_elements[i]) and (numbers[i][j]<0))
                max_elements[i] = numbers[i][j];
    cout << "\n  \n";
    // Вывод на экран массива максимальными элементами по строкам
    for (int i = 0; i < n; i++)
        cout <<"  "<< max_elements[i];
    cout << "\n  \n";
    //Проверка есть ли в строке положительные элементы
    bool is_exist_positive_mas[n];
    for (int i = 0; i < n; i++)
        is_exist_positive_mas[i] = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (numbers[i][j] > 0)
                is_exist_positive_mas[i] = true;
    int min_max_elemnt = firs_value - 1;
    // минимальный из максимальных отрицательных элементов
    for (int i = 0; i < n; i++)
        if (max_elements[i] > min_max_elemnt and max_elements[i]!= minus_inf)
            max_elements[i] = min_max_elemnt;
    //финальное задание
    for (int i = 0; i < n; i++)
        if (is_exist_positive_mas[i])
        {
            for (int j = 0; j < m; j++)
                if (numbers[i][j] > 0)
                    numbers[i][j] = max_elements[i];
        }
        else
        {
            for (int j = 0; j < m; j++)
                numbers[i][j] = min_max_elemnt;
        }
    displayNumbers(numbers, n, m);
 

    
}


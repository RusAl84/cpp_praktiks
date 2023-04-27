#include <iostream>
using namespace std;
class A
{public: void f() { cout << " A";}};
class B: public virtual A
{public: void f() { cout << " B";}};
class C: public virtual A
{public: void f() { cout << " C";}};
class E : public virtual A
{ public: void f() { cout << " E"; }};
class D : public virtual B, public virtual C, public virtual E
{public: void f() { cout << " D"; }};
class F: public virtual D
{  /*public: void f() { cout << " F"; };*/
};
int main()
{
    F object;
    object.f();
    object.A::f();
    object.B::f();
    object.C::f();
    object.D::f();
    object.E::f();
}

/*
[16:02, 27.04.2023] Мерсов: Об'явления классов дать в следующем порядке:А, В,С,Е,D,F
[16:02, 27.04.2023] Мерсов: У тебя идет D,E
[16:04, 27.04.2023] Мерсов: У тебя D производный от Е об'явлено а класс Е еще не об'явлен
[16:04, 27.04.2023] Мерсов: Поэтому и говорит об ошибке
[16:07, 27.04.2023] Мерсов: Еще ошибки есть следующие: если из класса выходят более чем 1 связь тоэтот класс должен быть виртуальным!!!
[16:08, 27.04.2023] Мерсов: Классы А Е С должны при наследовании быть виртуальными
[16:08, 27.04.2023] Rusakov Aleksey: Благодарю
[16:10, 27.04.2023] Мерсов: class D: public B, public virtual C, public virtual E; - для примера  например твоего и соответственно надо посмоьреть остальное*/

/*
https://ru.wikipedia.org/wiki/Microsoft_Foundation_Classes
https://ru.wikipedia.org/wiki/Windows_API#/media/%D0%A4%D0%B0%D0%B9%D0%BB:WinAPI_Scheme.svg
https://vk.com/wall-54530371_254
https://github.com/RusAl84/cpp-cheatsheet
https://quickref.me/cpp
https://www3.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html
Виртуальный означает видимый, но не существующий в реальности.
если из класса выходят более чем 1 связь тоэтот класс должен быть виртуальным!!!
Об'явления классов дать в следующем порядке как на схеме.
*/




//metod example
//#include <iostream>
//using namespace std;
//class A
//{public: void f() { cout << " A";}};
//class B: public virtual A
//{public: void f() { cout << " B";}};
//class D: public virtual A, public virtual B
//{public: void f() { cout << " D";}};
//class C: public virtual B
//{public: void f() { cout << " C";}};
//class E :public virtual C
//{public: void f() { cout << " E"; } };
//class F: public D, public E
//{  /*public: void f() { cout << " F"; };*/
//};
//int main()
//{
//    F object;
//    object.A::f();
//    object.B::f();
//    object.C::f();
//    object.D::f();
//    object.E::f();
//}


//Rusakov task
//#include <iostream>
//using namespace std;
//class A
//{public: void f() { cout << " A";}};
//class B: public virtual A
//{public: void f() { cout << " B";}};
//class C: public virtual B
//{//public: void f() { cout << " C";}
//};
//int main()
//{
//    C object;
//    object.f();
//
//}
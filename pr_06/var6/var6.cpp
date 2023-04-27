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

#include <iostream>
using namespace std;
class A
{public: void f() { cout << " A";}};
class B: public virtual A
{public: void f() { cout << " B";}};
class C: public virtual B
{//public: void f() { cout << " C";}
};
int main()
{
    C object;
    object.f();

}
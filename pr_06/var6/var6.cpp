#include <iostream>
using namespace std;
class A
{public: void f() { cout << " A"; };
class B : public virtual A
{public: void f() { cout << " B"; };
class D : public virtual A, public virtual B
{/*public: void f() { cout << "D";};
                class
                C : public virtual B
                {
                public : void f() { cout <<<<" C"; }
                class
                E : public C
                {
                public : void f() { cout <<<<" E";
                class
                F : public D , public E
                { ;
                ;// public: void f() { cout << "F"; };
                };
int main()
{
    std::cout << "Hello World!\n";
}

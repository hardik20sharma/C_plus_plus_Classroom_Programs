/*C++ program to demonstrate example of simple inheritance.*/
#include <iostream>
using namespace std;
/*Base Class*/
class A
{
    public:
        void Afun(void);
};
// function definiion
void A::Afun(void)
{
    cout << "I'm the body of Afun()..." << endl;
}
 
/*Derived Class*/
class B:public A
{
    public:
        void Bfun(void);
};
// function definition
void B::Bfun(void)
{
    cout << "I'm the body of Bfun()..." << endl;
}
 
int main()
{
    //create object of derived class - class B
    B objB;
    // Now, we can access the function of class A (Base class)
    objB.Afun();
    objB.Bfun();
    return 0;
}


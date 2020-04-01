#include<iostream>
using namespace std;

class Base
{
private:
	int a;
public:
	void setData(int n) { a=n; }
	virtual void getData() { cout << " Base" << a; }
};

class Derived : public Base
{
private:
	int x;
public:
	void setData(int n) { x=n; }
	void getData() { cout << "Derived" << x; }	
};

int main()
{
	Base *b;
	Derived d;

	b = &d;
	b->setData(3);
	b->getData();
}

#include<iostream>
using namespace std;

class Complex
{
private:
	int x, y;

public:
	Complex() {}
	Complex(int a, int b) : x(a), y(b) { }
	
	void addComplex(Complex a, Complex b)
	{
		x = a.x + b.x;
		y = a.y + b.y;	
	}
	
	void printComplex()
	{
		cout << "x=" << x << "\ty=" << y << endl;
	}
};

int main()
{
	Complex c1(3,4);
	c1.printComplex();
	Complex c2(4,3);
	c2.printComplex();
	Complex c3;
	c3.addComplex(c1,c2);
	c3.printComplex();
}

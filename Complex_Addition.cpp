#include<iostream>
using namespace std;

class Complex
{
private:
	float x, y;

public:
	Complex() {	}
	Complex(float a, float b)
	{
		x = a; y = b;	
	}
	
	Complex operator +(Complex c)
	{
		Complex temp;
		temp.x = x+c.x;
		temp.y = y+c.y;	
		
		return temp;
	}
	
	void display()
	{
		cout << x << " + i" << y << endl;
	}
};

int main()
{
	Complex c1, c2, c3;
	c1 = Complex(12, 13);
	c2 = Complex(2, 3);
	c3 = c1+c2;
	c3.display();
}

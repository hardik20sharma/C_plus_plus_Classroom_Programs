#include<iostream>
using namespace std;
#include<math.h>
class Shape
{
protected:
	float a, b, c;
public:
	float pi = 3.141592;
	float result;
	void get_result()
	{
		cout << "Result is " << result;
	}
};

class Triangle : public Shape
{ 
public:
	void get_sides()
	{
		cout << "Enter side 1: "; cin >> a;
		cout << "Enter side 2: "; cin >> b;
		cout << "Enter side 3: "; cin >> c;
	}
	void get_area()
	{
		float s=(a+b+c)/2;
		result = sqrt(s*(s-a)*(s-b)*(s-c));
		get_result();
	}
	void get_perimeter()
	{
		result = a+b+c;
		get_result();
	}
};

class Circle : public Shape
{
public:
	float get_Radius() { cout << "Enter the radius: "; cin >> a; }
	float get_Diameter() { result = 2*a; get_result(); }
	float get_Perimeter() { result = 2*pi*a; get_result(); }
	float get_Area() { result = pi*a*a; get_result(); }
};

class Rectangle : public Shape
{
public:
	float get_sides() 
	{
		cout <<"Enter side 1: "; cin >> a;
		cout <<"Enter side 2: "; cin >> b;
	}
	float get_perimeter() {	result =  2*(a+b); get_result(); }
	float get_area() { result = a*b; get_result(); }
};

int main()
{
	int ch;
	cout << "=========================\n";
	cout << "1. Trianlge\n";
	cout << "2. Circle\n";
	cout << "3. Square\n";
	cout << "4. Rectangle\n";
	cout << "Enter your choice: "; cin >> ch;		
	cout << "=========================\n";
	
	switch(ch)
	{
		case 1:
			Triangle t;
			
	}
}

//Write cpp program to read radius of a circle and display area, circumference, diameter, use class
#include<iostream>
using namespace std;

class circle
{
	private:		//These are the private members of the class, inacessible to others
		float radius, diameter, area, circumference;
		
	public:			//These are the public members of the class, acessible to others
		void getRadius(void);		
		void getDiameter(void);		
		void getArea(void);			
		void getCircumference(void);	
};

void circle::getRadius(void)		//defining getRadius 
{
	cout<<"\nEnter the radius: "; cin>>radius;
}
void circle::getDiameter(void)		//defining getDiameter
{
	diameter=radius*2;
	cout<<"\nDiameter: "<<diameter;
}
void circle::getArea(void)		//defining getArea 
{
	area=3.14*radius*radius;
	cout<<"\nArea: "<<area;
}
void circle::getCircumference(void)		//defining getCircumference
{
	circumference=2*3.14*radius;
	cout<<"\nCircumference: "<<circumference;
}

int main()
{
	circle c;
	c.getRadius();			//calls function getRadius
	c.getDiameter();		
	c.getCircumference();
	c.getArea();	
}

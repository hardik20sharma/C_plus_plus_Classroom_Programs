/*
C++ Inheritance
	--> Only language which captures real world objects.
	--> Reusability of code is possible
	--> Saves time and effort
	--> Increases program structure which results in greater reliability
		 
	Basic Syntax--
		class derived_classname : access specifier baseclassname
	Example--
		class sample : public MyClass	
	
	
	--> Inheritance is the process by which new classes called derived classses are created from exisiting classes called
			base classes.
	--> The derived classes have all the features of  the base class and the programmer can choose to add new functions.


	1. If a member variable declaraing the class is private then they are accessible to members of same class only and cannot
		be accessed from outside the class.
	2. Public members and variables are accessed from outside the class.
	3. Protected members of base class are private members of derviced class.
	
	Public Inheritance
		Public members of base class --> Public members of derived class
		Protected members of base class --> Protected members of derived class
		Private members never acessbile to derived class directly
			Can be accessed through public and protected members of base class
	
	Protected Inheritance
		Public members of base class --> Protected members of derived class
		Protected members of base class --> Protected members of derived class
			
	Private Inheritance
		Public members of base class --> Private members of derived class
		Protected members of base class --> Private members of derived class

Types of Inheritance
	1. Single Class Inheritance
		Single inheritance is the one where you have single base class and single derived class.
	
	2. Mulitple Inheritance
		A derived class from two base classes
	
	3. Multilevel Inheritance
		Base class -> Derived class 1 -> Derived class 2
	
	4. Hierachical class
		Multiple derived class from single base class
	
	5. Hybrid Inheritance
		Class A
	   /	   \
Class B			Class C
	   \       /
	   	Class D

*/
#include<iostream>
using namespace std;

class MyClass
{  	public: 
    	MyClass(void) 
			{ x=0; }   	
		void f(int n1)
			{  x= n1*5; } 
 		void output(void) 
	 		{ cout<<x; } 
 	private:
		int x;
};

class sample: public MyClass	
{ 
	public:
	   	sample(void) 
		   { s1=0; } 
 	void f1(int n1)
	 	{ s1=n1*10; }
 	void output(void) 	
		{ 	
			MyClass::output();   
			cout << s1; 
		}
 	private:
	 	int s1;
}; 

int main(void)
{	
	sample s;
	s.f(10);
	s.output();
	s.f1(20);
	s.output();
	s.func();
}


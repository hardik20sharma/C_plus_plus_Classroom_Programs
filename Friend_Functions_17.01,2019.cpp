/*	
	Access Control
		Public: visible to everyone
		Private: visible only to implementer of this particular class
		Protected: visible to the this class and derviced classes
	
	Friend functions	
		Friend declaration introduce extra coupling between classes
		Once an object is declared as friend, it has access to all non-public members as if they were public
		A friend function of a class is deinfed outside of that class's scope
		Purpose of having friend function is to access private or protected data memeber

	Friend function and frined classes
		Can access private and protected members of another class
		Friend functions are not member functions of class
		
		Properties:
			Cannont be vice-versa
		
		Friend declaration:
			Type friend before the function prototype in the class that is givig friendship
		
		Use:
			To provide more efficent access to data members than the function call
			To accomate operator functions with easy access to private data members
			
		-Friends can have access to everythin, which defeats hiding, so use them carefully
		-Frineds have permission to change the internal state of variables sitting outside the class.Always recommended 
			to use member function over frined function
	
*/


#include <iostream>
using namespace std;

class two;	//forward declaration
class one
{ 
	private:
		int data1;
    public:
	one()		//constructor
	{
		data1=10; 
	}
	friend int accessboth(one,two);	//friend function, consider this as a normal function with classes one and two as parameters
};

class two
{
	private:
		int data2;     
	public:
		two()	//constructor
		{
			data2=20;
		}
		friend int accessboth(one,two);	
}; 

int accessboth(one a,two b)
{
	return(a.data1 + b.data2);
}

int main()
{
	one x;
	two y;
	cout<<accessboth(x,y);
}

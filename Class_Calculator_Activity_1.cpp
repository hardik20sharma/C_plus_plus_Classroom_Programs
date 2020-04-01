/*
	WAP a cpp program to implement simple 6 operations, +, -. *, /, odd, even, % using class and object concept
	use scope resolution operator, use switch case.
*/
#include<iostream>
using namespace std;

class calculator
{
	private:
		float a,b, result;
	
	public:
		void getValues(void);	//	Takes input from user for a and b
		void add(void);			//	a+b
		void subtract(void);	//	a-b
		void multiply(void);	//	a*b
		void divide(void);		//	a/b
		void OddEven(void);		//	Prints if a and b are odd or even
		void modulus(void);		//	a%b
};

void calculator::getValues(void)
{
	cout<<"Enter value 1: "; cin>>a;
	cout<<"Enter value 2: "; cin>>b;
}
void calculator::add(void)
{
	result=a+b;
	cout<<"Result: "<<result;
}
void calculator::subtract(void)
{
	result=a-b;
	cout<<"Result: "<<result;
}
void calculator::divide(void)
{
	result=a/b;
	cout<<"Result: "<<result;
}
void calculator::multiply(void)
{
	result=a*b;
	cout<<"Result: "<<result;
}
void calculator::modulus(void)
{
	result=int(a)%int(b);
	cout<<"Result: "<<result;
}
void calculator::OddEven(void)
{
	if(int(a)%2==0)
		cout<<a<<" is even\n";
	else
		cout<<a<<" is odd\n";
		
	if(int(b)%2==0)
		cout<<b<<" is even";
	else
		cout<<b<<" is odd";
}

int main()
{
	calculator c;
	c.getValues();		
	int i;
	flag:	//If any wrong input is taken, program comes back here
	cout<<"\n1. Add\n2. Subtract\n3. Divide\n4. Multiply\n5. Modulus\n6. Odd Even\n";	//Menu, displays choices to user
	cout<<"Enter your choice: "; cin>>i;
	switch(i)	//Switch case for menu
	{
		case 1: c.add(); 		break;
		case 2: c.subtract();	break;
		case 3: c.divide();		break;
		case 4: c.multiply();	break;
		case 5: c.modulus();	break;
		case 6: c.OddEven();	break;
		default: cout<<"Try Again"; goto flag;	//Takes the program to flag if wrong input comes
	}
}


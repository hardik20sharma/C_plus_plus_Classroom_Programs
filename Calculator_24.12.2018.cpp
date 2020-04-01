/*
	1)	WAP to perform arithmatic calculations using class calculator
*/
#include<iostream>
using namespace std;

class calculator
{
	private:
		float num_1, num_2, res;
		char oper;
		
	public:
		void getnum_1(void);
		void getnum_2(void);
		void addition(void);
		void subraction(void);
		void division(void);
		void multiplication(void);
		void result(void);
		void Operator(void);
} c1;

void calculator::getnum_1(void)
{
	cin>>num_1;
	Operator();
}
void calculator::getnum_2(void)
{
	cin>>num_2;
}
void calculator::addition(void)
{
	res=num_1+num_2;
	Operator();
}
void calculator::subraction(void)
{
	res=num_1-num_2;
	Operator();
}
void calculator::multiplication(void)
{
	res=num_1*num_2;
	Operator();
}
void calculator::division(void)
{
	res=num_1/num_2;
	Operator();
}
void calculator::result(void)
{
	cout<<res<<endl;
}
void calculator::Operator(void)
{
	cin>>oper;
	if(oper=='=')
		{ result(); exit(0); }
	c1.getnum_2();
	switch(oper)
	{
		case '+': addition(); break;
		case '-': subraction(); break;
		case '*': multiplication();	break;
		case '/': division(); break;	
	}
}
int main()
{
	c1.getnum_1();
	c1.Operator();
}

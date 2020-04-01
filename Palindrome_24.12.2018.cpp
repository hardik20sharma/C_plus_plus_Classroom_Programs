// 2) 	WAP to check wheter the string is palidrome using class palindrome
#include<iostream>
using namespace std;
#include<string.h>

class Palindrome{
private:
	char num[10], temp[10];

public:
	void getnum()
	{
		cin>>num;
	}
	
	void check()
	{
		strcpy(temp,num);
		strrev(num);
		if(strcmp(temp,num))
			cout<<"Not a Palindrome";
		else
			cout<<"Palindrome";
	}
}p;

int main()
{
	p.getnum();
	p.check();
}

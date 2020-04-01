// 7)WAP to enter details of the person and print details of a person using class person as well as create array of objects
//		of the same class.

#include<iostream>
using namespace std;

class person
{
	private:	
		char name[30], dob[10]; float income; int age;
	public:
		void input(void);		
		void output(void);	 	
} m[5];			

void person::input(void)	
{
	cout<<"\nEnter name:\t"; fflush(stdin); gets(name);	
	cout<<"Enter age:\t"; cin>>age;						
	cout<<"Enter income:\t"; cin>>income;
	cout<<"Enter date of birth:\t"; fflush(stdin); gets(dob);	
}

void person::output(void)	
{
	cout<<"\n\nName:\t"<<name<<"\nAge:\t"<<age<<"\nIncome:\t"<<income<<"\nDate of Birth:"<<dob<<endl;	
}

int main()
{
	int num;	
	cout<<"Enter the number of persons: "; cin>>num;
	
	for(int i=0; i<num; i++)
		m[i].input();
	for(int i=0; i<num; i++)
		m[i].output();
}

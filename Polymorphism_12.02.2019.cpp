/*
Polymorphism
	Polymorphism means ability to take more than one form.
	An operator may exhibit different behaviour in different instances.
	The behaviour depends upoin the types of data used in the operation.

How can we implement polymorphism
	1. function overloading
	2. function overriding
	3. virtual function
	4. operator overloading
	
Two types of polymorphism
	Compile Time Polymorphism
	Run-time polymorphism
	
Compile Time Polymorphism
	1.It means that an obejct is bounded to its function call at compile time i.e linking to function call to function 
		defination is done at compile time
	2.Function which is being get called is known before.
	3.This is known as earlier binging or stating binding.
	Example: Function overloading and operator overloading
	
Run Time Polymorphism
	1. An object is bounded to its function call at run time i.e. linking to function call to function defination is 
		done at run time
	2. Function which is being get called is unknown until appropiate function selection is odne.
	3. This is know as late binging or dynaminc binding
	Example: Virtual functions
	
Function Overloading
	1. We can use same funciton name to create function that performs variety of different tasks.
	2. We can design multiple function with one function name but different argument lists.
	3. The function would perform different operation depending on the arguments
	Example:
		void add(int a, int b);
		int add(int x, int y);
		int add(int x, int y, int z);
		void add(float a, float b);
*/
//Exercise 1
//Sum of two int
//Sum of two float
//Sum of one int and one float
//Sum of n int passed as array
//SUm of n float passed as array

#include<iostream>
using namespace std;

class Sum
{
private:
	float add;
public:
	int sum(int a, int b)		// Two integers
	{
		return a+b;	
	}
	
	float sum(float a, float b)	// Two floats
	{
		return a+b;
	}
	
	float sum(float a, int b)	// One integer and one float
	{
		return a+b;
	}
	
	int sum(int arr[10], int n)	// Integer array
	{
		int(add) = 0;
		for(int i=0; i<n; i++)
			add += arr[i];
		return add;
	}
	
	float sum(float arr[10], int n) // Float array
	{
		add = 0.0;
		for(int i=0; i<n; i++)
			add += arr[i];
		return add;
	}
};

int main()
{
	Sum s;
	float float_arr[] = {3.0, 2.0, 1.0, 5.5};
	int int_arr[] = {3,2,7,5,9}, n;
	
	cout << s.sum(2,3) << endl;
	
	cout << s.sum(3.0f,5) << endl;
	
	n = sizeof(float_arr) / sizeof(float_arr[0]);
	cout << s.sum(float_arr, n) << endl;
	
	n = sizeof(float_arr) / sizeof(float_arr[0]);
	cout << s.sum(int_arr, n) << endl;
	
	cout << s.sum(4.0f, 9.0f) << endl;
}

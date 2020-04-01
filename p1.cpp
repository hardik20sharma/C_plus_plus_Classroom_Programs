#include<iostream>
using namespace std;

template <typename T>
void print(T ar[], int n)
{
	for(int i=0; i<n; i++)
		cout << ar[i];
	cout << endl;
}
/*
void print(int ar[], int n)
{
	for(int i=0; i<n; i++)
		cout << ar[i];
	cout << endl;
}
*/
int main()
{
	char ar[]="Hello";
	int n = sizeof(ar)/sizeof(ar[0]);
	print(ar,n);
	
	int arr[]={1,2,3,4};
	int x = sizeof(arr)/sizeof(arr[0]);
	print(arr,x);
	
	float a[]={1.0,1.2,1.1};
	int b = sizeof(a)/sizeof(a[0]);
	print(a,b);
}

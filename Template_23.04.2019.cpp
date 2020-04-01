#include<iostream>
using namespace std;

template <typename T>
class Base 
{
private:
	T private_member;

public:
	void setData(T n) { private_member = n; }
	T getData() { return private_member; }
};


int main()
{
	Base <int> base_int_object;
	base_int_object.setData(6);
	cout << base_int_object.getData();
	
	Base <char> base_char_object;
	base_char_object.setData('c');
	cout << base_char_object.getData();
	
	Base <float> base_float_object;
	base_float_object.setData(5.3);
	cout << base_float_object.getData();
}

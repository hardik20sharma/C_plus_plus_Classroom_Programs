#include<iostream>
using namespace std;

class Test
{
private:
	int a;

public:
	void operator -()
		{ cin >> a; }
	void compare(Test t2)
	{ 
		if(a==t2.a)
			cout << "Equal";
		else
			cout << "Not Equal";		
	}
};

int main()
{
	Test t1, t2;
	-t1;
	-t2;
	t1.compare(t2);
}

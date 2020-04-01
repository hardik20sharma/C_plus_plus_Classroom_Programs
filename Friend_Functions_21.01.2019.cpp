/*
	OUTPUT is
	
	Mean value = 35
*/

#include<iostream>
using namespace std;

class sample
{
private:
    int x;
    int y;

    public:
    void setvalue(int a, int b)
    { 
	    x = a;
		y = b; 
    }
	friend float mean(sample);
};

float mean(sample s)

{
	return float(s.x + s.y)/2.0;
}

int main()

{
	sample X;
    X.setvalue(25,45);
    cout<<"Mean value = "<< mean(X) <<endl;
}

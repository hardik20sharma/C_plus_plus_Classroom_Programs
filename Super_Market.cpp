#include<iostream>
using namespace std;
#include<string.h>

class Product
{
protected:	
	long barcode;
	string name;
	
public:
	Product() : barcode(00000), name("Unnamed") {}
	Product(long bar, string na) : barcode(bar), name(na) {}
		
	long getCode()
		{ return barcode; }
	
	void printer()
	{
		cout << "Barcode: " << barcode << endl;
		cout << "Name : " << name << endl;
	}
};

class PrePackedFood : public Product 
{
private:
	float price;

public:
	PrePackedFood() : price(0.0), Product() {}
	
	void enter_data(float pri, long barcode, string name)
	{
		price = pri;
		Product(barcode, name);
	} 
		
	void packed_printer()
	{
		Product : printer();
		cout << "Price: " << price << endl;
	}
};	

class FreshFood : public Product
{
private:
	float price;
	float weight;

public:
	FreshFood() : price(0.0), Product() {}	
	
	void enter_data(float pri, long barcode, string na)
	{
		price = pri;
		Product(barcode, name);
	}
	
	void fresh_printer()
	{
		Product : printer();
		cout << "Weight: " << weight << endl;
		cout << "Price: " << price*weight << endl; 
	}
};

int main()
{
	int ch, ff_num = 0, pf_num = 0;
	long bar;
	string name;
	float price, weight;
	
	FreshFood ff[10];
	PrePackedFood pf[10];
	cout << "\t\tWELCOME !!\n\n";
	
	flag:
	cout << "----------------------------------------\n";
	cout << "1. Enter details of a Fresh Food.\n";
	cout << "2. Enter details of a Packed Food.\n";
	cout << "3. Billing Service.\n";
	cout << "4. Exit.\n";
	cout << "Choose your option: "; cin >> ch;
	cout << "----------------------------------------\n";
	
	switch(ch)
	{
		case 1:
			cout << "Enter barcode: "; cin >> bar;
			cout << "Enter name: "; cin >> name;
			cout << "Enter price per kg: "; cin >> price;
			ff[ff_num++].enter_data(price, bar, name);
			goto flag;
		
		case 2:
			cout << "Enter barcode: "; cin >> bar;
			cout << "Enter name: "; cin >> name;
			cout << "Enter price per kg: "; cin >> price;
			pf[pf_num++].enter_data(price, bar, name);
			goto flag;
		
		case 3:
			cout << "Enter the barcode: "; cin >> bar;
			
			for(int i=0; i<ff_num; i++)
			{
				if(ff[i].getCode() == bar)
					ff[i].fresh_printer();
			}
			
			for(int i=0; i<pf_num; i++)
			{
				if(pf[i].getCode() == bar)
					pf[i].packed_printer();	
			}
			goto flag;
			
		case 4:
			cout << "Exit.";
			exit(0);
		default:
			cout << "Wrong choice !!\t Try Again!\n";
			goto flag;
	}
}

/*
	Continous assessment - exercise 1
	WAP in c++ which has the following description
		create a class for bank processing
			data members are name of the customer, account number, account type, balance amount on date in the account
		function members are methods
			one method for intial value, one more for subsequent deposits at any time, withdraw a amount at any time,
			to display the customer's information after every operation including the balance amount in the account
		
	for initial deposit provide default constructor
	for subsequent deposit use parametized constructor
	withdrawing amount--process to find if min amount is always maintaied in account + all other criteria
	
	account number (generate automatically, 6 digit number), array of objects
	n number of customers
*/
#include<iostream>
using namespace std;
#include<ctype.h>

class Bank_Processing
{
	private:
		char cust_name[30], acc_type[7];
		float balance;
		int acc_number;
	
	public:	
		Bank_Processing()		//Default constructor
		{
			cout<<"Enter your name: "; fflush(stdin); gets(cust_name);
			cout<<"Enter the account type: "; gets(acc_type);
			flag1:
			cout<<"Enter the initial deposit: "; 
			cin>>balance;
			if(balance<0)
			{
				cout<<"Initial Deposit cannot be negative: \n";
				goto flag1;
			}
			else if(balance<500)
			{
				cout<<"Minimum balance should be 500\n";
				goto flag1;
			}
			acc_number=123456;
		}
		
		int get_acc_number()	//Returns account number
		{
			return acc_number;
		}
		
		void deposit(int amount)	//Deposits money
		{
			cout<<"\nDepositing Money...";
			if(amount>=0)
			{
				balance+=amount;
				cout<<"\nAmount Deposited !!";
			}
			else
			{
				cout<<"\nDeposit amount cannot be negative !!";
			}
		}
		
		void print_details()	//Print Details
		{
			cout<<"\n------------------------------";
			cout<<"\nPrinting Details...";
			cout<<"\nAccount Number: "<<acc_number;
			cout<<"\nName of the customer: "<<cust_name;
			cout<<"\nAccount Type: "<<acc_type;
			cout<<"\nBalance: "<<balance;
		}
		
		void withdrawal(int amount)	// Withdraws money
		{
			cout<<"\nWithdrawing Money...";
			if(amount<0)
				cout<<"\nWithdrawal amount cannot be negative...Try Again";
			else if(amount>balance)
				cout<<"\nWithdrawal amount cannot be greater than balance...Try Again";
			else if((balance-amount)<500)
				cout<<"\nMinimum balance should be 500 in account..Try Again";
			else
			{
				balance-=amount;
				cout<<"\nWitdrawal complete";
			}
		}
};

int main()
{
	int choice, i=0, amount, acc_number;
	cout<<"\tWELCOME TO XYZ BANK\n\n";
	cout<<"Creating a new account...\n";
	Bank_Processing c;
	c.print_details();
	
	flag:
	cout<<"\n---------------------------------------------\n";
	cout<<"\nPlease choose one of the following functions:\n";
	cout<<"1. Deposit\n";
	cout<<"2. Withdrawal\n";
	cout<<"3. Print Details\n";
	cout<<"4. Exit\n";
	cout<<"Enter your choice: ";cin>>choice;
	if(isalpha(choice))
	{
		cout<<"Please enter numerical values !";
		goto  flag;
	}

	
	switch(choice)
	{
		case 1:
			cout<<"Enter your account number: "; cin>>acc_number;
			if(c.get_acc_number() != acc_number)
			{
				cout<<"This account number does not exists !";
				goto flag;
			}
			cout<<"Enter the amount to be deposited: "; cin>>amount;
			c.deposit(amount);
			c.print_details();
			goto flag;
		
		case 2:
			cout<<"Enter your account number: "; cin>>acc_number;
			if(c.get_acc_number() != acc_number)
			{
				cout<<"This account number does not exists !";
				goto flag;
			}
			cout<<"Enter the amount to be withdrawn: "; cin>>amount;
			c.withdrawal(amount);
			c.print_details();
			goto flag;
		
		case 3:
			c.print_details();
			goto flag;
		
		case 4:
			exit(0);
			
		default:
			cout<<"Wrong Choice !!\tTry Again\n";
			goto flag;
	}
}

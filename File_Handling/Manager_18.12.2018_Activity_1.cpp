/*
	A company has so many managers read doj, name, salary, age
*/
#include<iostream>
#include<ctype.h>
#include<fstream>
#include<stdio.h>
using namespace std;

class Manager
{
	private:
		char name[30], joining_date[10]; 
		float salary; 
		int age, uid;

	public:
		void input_info(void);			//Function to take information
		void show_info(int num);	 	//Function to show information
		void delete_info(int num);		//Function to delete information
		void update_info(int num);		//Function to update details of employee
};

void Manager::input_info(void)	//Defining the function input of class manager
{
	cout << "\nEnter the Unique Identification number: "; cin >> uid;
	cout << "Enter name:\t"; fflush(stdin); gets(name);		//Using fflush to remove any buffer memory, important in case
	cout << "Enter age:\t"; cin>>age;									//of strings
	cout << "Enter salary:\t"; cin>>salary;
	cout << "Enter date of joining:\t"; fflush(stdin); gets(joining_date);
	
	ofstream fout("Manager.txt", ios::app);	// Opening file to put data at the end
	if(!fout)	// Error opening file
	{
		cout << "Error opening file to input data.";
		exit(0);
	}
	fout << uid << "\t" << name << "\t" << age << "\t" << salary << "\t" << joining_date << "\n";
	fout.close();	// Closing file after inputting data
}

void Manager::show_info(int num)	//Defining the function output of class manager
{
	ifstream fin("Manager.txt", ios::in);
	if(!fin)	// Error opening file
	{
		cout << "Error opening file to input data.";
		exit(0);
	}
	while(!fin.eof() && uid!=num)		// Reading file to scan the desired record
	{
		fin >> uid >> name >> age >> salary >> joining_date;
	}
	
	if(uid == num)
		cout << uid << "\t" << name << "\t" << age << "\t" << salary << "\t" << joining_date;
	else
		cout << "\nRecord not found !!";
	fin.close();	// Closing the text file
}

void Manager::delete_info(int num)
{
	char ch;
	ifstream fin("Manager.txt", ios::in);
	if(!fin)	// Error opening file
	{
		cout << "Error opening file to input data.";
		exit(0);
	}
	while(!fin.eof() && uid!=num)		// Reading file to scan the desired record
	{
		fin >> uid >> name >> age >> salary >> joining_date;
	}
	
	if(uid == num)
	{
		cout << uid << "\t" << name << "\t" << age << "\t" << salary << "\t" << joining_date;
		cout << "\nPress (y/Y) to confirm. "; cin >> ch;
	}
	else
		cout << "\nRecord not found !!";
	fin.close();
	
	if(ch!='y' && ch!='Y')
	{
		return;
	}
	
	fin.open("Manager.txt", ios::in);
	if(!fin)	// Error opening file
	{
		cout << "Error opening file to input data.";
		exit(0);
	}
	ofstream fout("temp.txt", ios::app);
	if(!fout)	// Error opening file
	{
		cout << "Error opening file to input data.";
		exit(0);
	}
	
	while(!fin.eof())		// Copying data from one file to another
	{
		fin >> uid >> name >> age >> salary >> joining_date;
		if(uid==num)
			continue;
		else
			fout << uid << "\t" << name << "\t" << age << "\t" << salary << "\t" << joining_date << "\n";
	}
	fin.close();
	fout.close();
	
	remove("Manager.txt");
	rename("temp.txt","Manager.txt");
}

int main()
{
	int ch, n;
	Manager m;
	
	// Main Screen
	flag1:
	cout << "\n-------------------------";
	cout << "\n1. Enter manager details.";
	cout << "\n2. Show manager details.";
	cout << "\n3. Delete manager details.";
	cout << "\n4. Exit";
	try
	{
		cout << "\nEnter your choice: "; cin >> ch;
		if(isdigit(ch) || ch>4 || ch<1)
			throw ch;
	}
	catch(int ch)
	{
		cout << "\nIncorrect option !";
		goto flag1;
	}
	cout << "\n-------------------------";
	
	//Switch case to call functions
	switch(ch)
	{
		case 1:
			m.input_info();
			goto flag1;
		
		case 2:
			cout << "\nEnter the unique identification number to show the details: "; cin >> n;
			m.show_info(n);
			goto flag1;
		
		case 3:
			cout << "\nEnter the unique identification number to delete the details: "; cin >> n;
			m.delete_info(n);
			goto flag1;
			
		case 4:
			exit(0);
	}
}

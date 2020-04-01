#include<iostream>
using namespace std;
#include<string.h>
#include<ctype.h>

class Employee
{
private:
	string name;	// Name
	string ssn;		// Identification
	double netPay;	

public:
//	Employee();
//	Employee(string theName, string theSsn);

	string getName() const // Returns Name of Employee
		{ return name; }

	string getSsn() const // Returns Identification of Employee
		{ return ssn; }				

	double getNetPay() const // Returns Net Pay of Employee
		{ return netPay; }

	void setName(string newName) // Sets Name of Employee
		{ name = newName; }

	void setSsn(string newSsn) // Sets Identification of Employee
		{ ssn = newSsn; }

	void setNetPay(double newNetPay) // Sets Net Pay of Employee
		{ netPay = newNetPay; }

	void printCheck() const	// Prints check
		{ cout << "\nERROR: undifferentiated employee"; }

	void printEmployee()	// Prints infomation of Employee
		{ cout <<"\nEmployee Name: " << name << "\nEmployee Identification: " << ssn << "\nEmployee's Net pay'" << netPay; }

	virtual void printTaxes() = 0;
	virtual void printPayroll()
	{
		printCheck();
		printTaxes();	
	}	
};

class HourlyEmployee : public Employee
{
private:
	double wageRate;	// Rate of 1 hour
	double hours;		// Number of hours worked in a week

public:
//	HourlyEmployee();
//	HourlyEmployee(string theName, string theSsn, double theWageRate, double theHours);

	void setRate(double newWageRate) // Set wage rate 
		{ wageRate = newWageRate; }	
	
	double getRate() const 			// Returns wage rate
		{ return wageRate; }						
	
	void setHours(double hoursWorked) // Set hours 
		{ hours = hoursWorked; }		
	
	double getHours() const // Returns hours
		{ return hours; }						
	
	void printCheck()	// Prints Income
		{ cout << "\nEmployee's Income: $ " << (hours*wageRate)*0.8; }
	
	void printTaxes()	// prints taxes, for hourly employee
	{
		double tax = 0.2 * (hours*wageRate);
		cout << "\nAmount to State: $ " << 0.1*tax;
		cout << "\nAmount to Federal: $ " << 0.7*tax;
		if(0.2*tax < 100)
		{ 
			cout << "\nAmount to Unemployment Insurance: $ " << 0.1*tax;
			cout << "\nAmount to Social Security: $ " << 0.1*tax;
			cout << "\nRetirement: $ 0";
		}
		else
		{
			cout << "\nAmount to Unemployment Insurance: $ 50";
			cout << "\nAmount to Social Security: $ 50";
			cout << "\nRetirement: $" << 0.8*(tax) - 100;
		}
	}
	
	void printPayroll()
	{
		printEmployee();
		HourlyEmployee::printCheck();
		HourlyEmployee::printTaxes();
	}
};

class SalariedEmployee : public Employee
{
private:
	double salary;	//weekly
	
public:
//	SalariedEmployee();
//	SalariedEmployee (string theName, string theSsn, double theWeeklySalary);
	
	double getSalary() const	// Returns salary
		{ return salary; }

	void setSalary(double newSalary)	// Sets salary
		{ salary = newSalary; }

	void printCheck()
		{ cout << "\nEmployee's Income: " << (salary*2)*0.7; }
	
	void printTaxes()
	{
		double tax = (salary*2*0.3);
		cout << "\nAmount to State: $ " << 0.15*tax;
		cout << "\nAmount to Federal: $ " << 0.75*tax;
		if(0.1*tax < 200)
		{ 
			cout << "\nAmount to Unemployment Insurance: $ " << 0.05*tax;
			cout << "\nAmount to Social Security: $ " << 0.05*tax;
			cout << "\nRetirement: $ 0";
		}
		else
		{
			cout << "\nAmount to Unemployment Insurance: $ 100";
			cout << "\nAmount to Social Security: $ 100";
			cout << "\nRetirement: $" << 0.9*(tax) - 200;
		}
	}
	
	void printPayroll()
	{
		printEmployee();
		printCheck();
		printTaxes();
	}
};

int main()
{
	int ch = 0, i=0, j=0, k;
	string str;
	double d;
	
	SalariedEmployee semp[3];
	HourlyEmployee hemp[3];
	
	flag:
	cout << "\n========================";
	cout << "\n1. Input Hourly Employee.";
	cout << "\n2. Input Salary Employee.";
	cout << "\n3. Output Hourly Employee.";
	cout << "\n4. Output Salary Employee.";
	cout << "\n5. Exit.";
	cout << "\nEnter your choice: "; cin >> ch;
	if(isdigit(ch))
		{ cout << "Please enter a number !"; goto flag; }
	cout << "==========================";
	
	switch(ch)
	{
		case 1:
			cout << "\nEnter the name: "; cin >> str; hemp[i].setName(str);
			cout << "\nEnter the Unique Identification Number: "; fflush(stdin); cin >> str; hemp[i].setSsn(str);
			cout << "\nEnter the netPay: "; cin >> d; hemp[i].setNetPay(d);
			cout << "\nEnter the wage rate (per hour): "; cin >> d; hemp[i].setRate(d);
			cout << "\nEnter the number of hours: "; cin >> d; hemp[i++].setHours(d);
			goto flag;
		
		case 2:
			cout << "\nEnter the name: "; cin >> str; semp[j].setName(str);
			cout << "\nEnter the Unique Identification Number: "; cin >> str; semp[j].setSsn(str);
			cout << "\nEnter the netPay: "; cin >> d; semp[j].setNetPay(d);
			cout << "\nEnter the salary: "; cin >> d; semp[j++].setSalary(d);
			goto flag;
		
		case 3:
			cout << "\nEnter the Unique Identification Number: "; cin >> str;
			for(k=0; k<i; k++)
				if(hemp[k].getSsn() == str)
					break;
			hemp[k].printPayroll();
			goto flag;
		
		case 4:
			cout << "\nEnter the Unique Identification Number: "; cin >> str;
			for(k=0; k<i; k++)
				if(hemp[k].getSsn() == str)
					break;
			semp[k].printPayroll();
			goto flag;
		
		case 5:
			exit(0);
		
		default:
			cout << "\nWrong Choice !!";
			goto flag;
	}
}

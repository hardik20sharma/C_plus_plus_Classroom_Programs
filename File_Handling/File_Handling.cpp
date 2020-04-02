/*
	C++ views files as sequence of bytes
	When a file is opened an object is created and a stream is associated with it
	To process file in c++ iostream and fstream is required
	
	ofstream fout("File_Name.dat", ios::out);
	isftream fout("File_Name.dat", ios::in);
	
	Physical file and logical file
	
		Suppose the following code is written in a program	
			...
			ofstream clientF("clients.dat", ios::out);
			...
		
		Physical files will be clients.dat and the source code of program
		clientF will be logical file, created by compiler
*/
#include<iostream>
using namespace std;
#include<fstream>

int main()
{
	/*
	ofstream clientF("clients.txt", ios::out);
	if(!clientF)
	{
		cout << "Error opening the file";
		exit(0);
	}
	int account; char name[30]; double balance;
	
	while(cin >> account >> name >> balance)
		clientF << account << name << balance;
	clientF.close();	
	*/
	int account; char name[30]; double balance;
	ifstream clientI("clients.txt", ios::in);
	if(!clientI)
	{
		cout << "Error opening the file";
		exit(0);
	}	
	while(clientI >> account >> name >> balance)
		cout << account << name << balance << endl;
	clientI.close();
}

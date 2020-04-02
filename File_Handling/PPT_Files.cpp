#include<iostream> 
#include<fstream> 
using namespace std; 
int main()  
{ 
   ofstream ofile;
   ofile.open ("text.txt");
   ofile << "Hi, Hello How are you?" << endl;
   cout << "Data written to file" << endl;
   ofile.close();
   return 0;
} 


/*
	Inline Functions 
		Any small function which can be coded in single line is called inline functions
		Macros --- #define
		Can be executed faster than normal function
		Can be coded in single line
		
		Disadvantage
			Cannot be used in place of function having code of multilines
			Macros are faster than Inline functions

		An inline function can never be located in a run-time library since the actual core is inserted by the compiler and
		must be therefore to be knows as compile-time
*/
#include <iostream>
using namespace std;
int g =10 ;
void fun ()
{
   g= 5 ; 
   return ; 

}
int main() 
{
  ::g = 15 ; 
  fun();
  cout << ::g << endl ;
	return 0;
}

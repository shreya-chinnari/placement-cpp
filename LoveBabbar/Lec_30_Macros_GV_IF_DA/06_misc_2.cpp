#include <iostream>
using namespace std;

// Global variable
int a = 42;

// Function that accesses address of 'a'
void showAddress(int &var)
{
   cout << "Address of global variable a: " << &var << endl;
   cout << "Value of global variable a: " << var << endl;
}

int main()
{
   int var = 5;
   showAddress(var);
   return 0;
}

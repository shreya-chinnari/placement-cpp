#include <iostream>
using namespace std;

// Global variable
int a = 42;

// Function that accesses address of 'a'
void showAddress()
{
   cout << "Address of global variable a: " << &a << endl;
   cout << "Value of global variable a: " << a << endl;
}

int main()
{
   showAddress();
   return 0;
}

#include <iostream>
using namespace std;

// PASSING BY VALUE
// In C++, when you pass a variable to a function, it is passed by value by default.
// This means that a copy of the variable is made, and any modifications to the parameter inside the function do not affect the original variable.
void modify(int x)
{
   x = x + 10;
}

int main()
{
   int a = 5;
   modify(a);
   cout << a << endl; // Output: 5 (unchanged)
   return 0;
}
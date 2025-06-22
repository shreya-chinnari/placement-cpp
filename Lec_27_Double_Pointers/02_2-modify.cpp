#include <iostream>
using namespace std;

// PASSING BY REFERENCE USING POINTERS

void modify(int *x)
{
   *x = *x + 10;
}

int main()
{
   int a = 5;
   modify(&a);        // Pass address of a
   cout << a << endl; // Output: 15
   return 0;
}
// The function modify now takes a pointer to an integer, allowing it to modify the original variable directly.
// This is an example of passing by reference using pointers, which allows the function to modify the original variable instead of a copy.
// This is useful when you want to modify the original variable or when passing large data structures to avoid the overhead of copying them.
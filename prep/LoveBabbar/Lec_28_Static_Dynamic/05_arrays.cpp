#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter the size of the array: ";
   cin >> n;
   // int arr[n]; // BAD PRACTICE
   return 0;
}

/*

C++ does NOT support variable-length arrays (VLAs) as part of the standard.

The line int arr[n]; is only allowed in GCC as a compiler extension, not in standard C++ (e.g., MSVC will throw an error).

[ [ This is because array sizes must be known at compile time, not runtime. ] ]


🧠 Stack Memory is Limited and Fixed
   > > Arrays like int arr[n] are stored on the stack.
   > > Stack size is very limited (usually 1–8 MB on most systems).
   > > If n is large (user input, or based on data size), you can easily:
   > > Exceed the stack limit
   > > Cause a stack overflow → program crashes
*/
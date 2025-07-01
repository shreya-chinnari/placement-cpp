#include <iostream>
using namespace std;
/*
Function returns a reference to an int (int &).
It takes one argument: n, passed by value (i.e., a copy of the argument is made).
*/
int &passByReference(int n)
{
   int a = 5;    // Local variable a is created and initialized to 5.
   int &ref = a; // ref is now an alias to a — any change to ref will affect a.
   return ref;   // ❌ Dangerous: You return a REFERENCE to local variable `a`.

   /*
   ❗ a is stored in the stack frame of the function.

   When the function finishes, that stack memory is released, but you're still referencing it.

   a (inside the function) is destroyed, but ref still points to its memory → Dangling reference
   */
}
int main()
{
   int a = 5;
   int &b = a;
   /*
   b is a reference to a. Now both a and b refer to the same memory.
   Modifying b would modify a.
   */
   int &ref = passByReference(10); // ref now refers to a destroyed variable!

   cout << "Value of ref (undefined behavior): " << ref << endl; // ref refers to invalid memory (the a from the function no longer exists)

   return 0;
}

// Output : : Value of ref (undefined behavior): 5

/*
Output can vary:

      :   Print a garbage number (random memory content)
      :  Crash the program
      :   Print 0 or some residual value
*/
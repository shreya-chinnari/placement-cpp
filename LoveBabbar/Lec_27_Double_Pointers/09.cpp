#include <iostream>
using namespace std;

int main()
{
   // ❌ WRONG WAY (Causes Runtime Crash)
   /*
   int *p = 0;          // p is a null pointer (points to nothing)
   int first = 110;

   *p = first;          // ❌ ERROR: Dereferencing null pointer (trying to write to address 0)
                        // This will cause a segmentation fault at runtime

   cout << *p << endl;  // ❌ Undefined behavior — program likely crashes
   */

   // ✅ CORRECT WAY 1: Make pointer point to a valid variable
   int first = 110;
   int *p = &first; // p now stores address of variable `first`

   *p = 200; // Now this is VALID: it changes value of `first` to 200

   cout << "[Correct Way 1] Value of first: " << first << endl; // prints 200

   // ✅ CORRECT WAY 2: Dynamically allocate memory
   int *q = new int; // allocate space for one int, q now points to it
   *q = 300;         // valid: sets that memory to 300

   cout << "[Correct Way 2] Value stored in dynamic memory: " << *q << endl;

   delete q; // good practice: free dynamically allocated memory

   return 0;
}

/*
coorect version
--------------


#include <iostream>
using namespace std;

int main() {
    int first = 110;

    // ✅ Fix: Make p point to the address of a valid variable
    int *p = &first;  // p now holds address of `first`

    *p = 200;         // This is safe. Now you're writing 200 into `first`

    cout << "Value of first: " << first << endl; // prints 200

    return 0;
}



*/
#include <iostream>
using namespace std;

// Function 1: Pass by Value (original variable is not changed)
void passByValue(int x)
{
   x = x + 10;
   cout << "[Inside passByValue] x = " << x << endl;
}

// Function 2: Pass by Reference using Pointer (modifies the actual variable)
void passByPointer(int *x)
{
   *x = *x + 10; // dereference and modify the value
   cout << "[Inside passByPointer] *x = " << *x << endl;
}

// Function 3: Pass by Reference using Double Pointer (modifies the pointer itself)
void passByDoublePointer(int **x)
{
   static int newValue = 99; // static so it persists outside the function
   *x = &newValue;           // reassign pointer to point to newValue
   cout << "[Inside passByDoublePointer] **x = " << **x << endl;
}

int main()
{
   int a = 5;
   int *ptr = &a;

   cout << "Initial value of a: " << a << endl;

   // -------- Pass by Value --------
   passByValue(a);
   cout << "[After passByValue] a = " << a << " (unchanged)" << endl;

   // -------- Pass by Pointer --------
   passByPointer(&a);
   cout << "[After passByPointer] a = " << a << " (modified)" << endl;

   // -------- Pass by Double Pointer --------
   cout << "Initial value pointed by ptr: " << *ptr << endl;
   passByDoublePointer(&ptr); // pass address of pointer
   cout << "[After passByDoublePointer] *ptr = " << *ptr << " (ptr now points to 99)" << endl;

   return 0;
}

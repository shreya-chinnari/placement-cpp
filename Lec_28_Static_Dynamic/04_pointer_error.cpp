#include <iostream>
using namespace std;

int *fun(int n)
{
   int *ptr = &n; // ❌ DANGER: 'n' is a local variable, lives only during this function call
   return ptr;    // ❌ Returning a pointer to local variable → leads to undefined behavior
}

int main()
{
   int *p = fun(10);                         // p now points to invalid memory (n is destroyed)
   cout << "Returned value: " << *p << endl; // ⚠️ May crash, print garbage, or seem to work randomly

   return 0;
}

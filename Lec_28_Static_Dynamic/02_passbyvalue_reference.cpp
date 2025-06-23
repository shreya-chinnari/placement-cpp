#include <iostream>
using namespace std;

int passByReference(int &x) // This is pass by reference, not pass by value.
{
   x = x * 2;
   return x;
}

int passByValue(int x)
{
   x = x * 3;
   return x;
}

int main()
{
   int a = 5;

   int &b = a; // b is a reference to a
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;

   passByReference(a);

   cout << "After pass by reference:" << endl;
   cout << "a: " << a << endl;

   cout
       << "b: " << b << endl;

   // difference between pass by value and pass by reference ==============================

   passByValue(a);

   cout << "After pass by value:" << endl;
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;

   return 0;
}

/*
a: 5
b: 5

After pass by reference:
a: 10
b: 10

   So when you call update(a), the function works directly with a — not a copy.

After pass by value:
a: 10
b: 10

   Here x would be a copy of a.
   Any changes to x would not affect a outside the function.
*/
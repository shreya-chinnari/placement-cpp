#include <iostream>
using namespace std;

int main()
{
   int a = 5;
   int &b = a; // b is a reference to a

   cout << "a: " << a << endl;
   cout << "b: " << b << endl;

   a++;
   cout << "\nAfter incrementing a:" << endl;
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;
   b++;
   cout << "\nAfter incrementing b:" << endl;
   cout << "a: " << a << endl;
   cout << "b: " << b << endl;

   int *c = &a; // c is a pointer to a

   return 0;
}

/*
a: 5
b: 5

After incrementing a:
a: 6
b: 6

After incrementing b:
a: 7
b: 7

*/
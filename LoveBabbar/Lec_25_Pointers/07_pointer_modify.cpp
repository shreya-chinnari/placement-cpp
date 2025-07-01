#include <iostream>
using namespace std;

int main()
{
   // Step 1: Initialize a variable and a pointer
   int num = 10;
   int *p = &num; // 'p' holds the address of 'num'

   cout << "Initial values:\n";
   cout << "num = " << num << endl;             // 10
   cout << "*p = " << *p << endl;               // 10
   cout << "Address held by p = " << p << endl; // Address of num

   // Step 2: Change 'num' directly
   num = 20;
   cout << "\nAfter changing num to 20:\n";
   cout << "num = " << num << endl;             // 20
   cout << "*p = " << *p << endl;               // 20
   cout << "Address held by p = " << p << endl; // Still points to num

   // Step 3: Change value via pointer dereferencing
   *p = 30;
   cout << "\nAfter changing *p to 30:\n";
   cout << "num = " << num << endl;             // 30
   cout << "*p = " << *p << endl;               // 30
   cout << "Address held by p = " << p << endl; // Still points to num

   // Step 4: Point 'p' to a new variable
   int another = 50;
   p = &another; // Now 'p' points to 'another', not 'num'

   cout << "\nAfter changing p to point to 'another':\n";
   cout << "num = " << num << endl;             // 30 (unchanged)
   cout << "another = " << another << endl;     // 50
   cout << "*p = " << *p << endl;               // 50
   cout << "Address held by p = " << p << endl; // Now points to another

   return 0;
}

/*
Initial values:
   num = 10
   *p = 10
   Address held by p = 0xa3177ffb14

After changing num to 20:
   num = 20
   *p = 20
   Address held by p = 0xa3177ffb14

After changing *p to 30:
   num = 30
   *p = 30
   Address held by p = 0xa3177ffb14

After changing p to point to 'another':
   num = 30
      another = 50
   *p = 50
   Address held by p = 0xa3177ffb10

*/
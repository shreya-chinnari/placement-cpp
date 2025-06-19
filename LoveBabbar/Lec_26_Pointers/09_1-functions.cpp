#include <iostream>
using namespace std;

void print(int *p)
{
   // Dereference the pointer to get the value it points to
   cout << "Value pointed by p: " << *p << endl;
   // Print the address stored in pointer p
   cout << "Address stored in p: " << p << endl;
}

void update(int *p)
{
   p = p + 1; // Increment the pointer to point to the next integer
   // This function modifies a local copy of the pointer p, not the original pointer in main().
}

int main()
{
   int v = 5;
   int *p = &v; // Pointer p points to the address of v

   print(p);                                             // Call the print function with pointer p
   cout << "Before update, p points to: " << *p << endl; // Print value before update
   cout << "Before update, p address: " << p << endl;    // Print address
   update(p);                                            // Call the update function with pointer p
   cout << "After update, p points to: " << *p << endl;  // Print value after update
   cout << "After update, p address: " << p << endl;     // Print address
   return 0;
}

/*
Value pointed by p: 5
Address stored in p: 0xb1189ffc84
Before update, p points to: 5
Before update, p address: 0xb1189ffc84
After update, p points to: 5
After update, p address: 0xb1189ffc84
*/
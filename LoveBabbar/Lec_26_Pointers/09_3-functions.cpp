#include <iostream>
using namespace std;

void print(int *p)
{
   cout << "Value pointed by p: " << *p << endl;
   cout << "Address stored in p: " << p << endl;
}

void update(int *p)
{
   *p = *p + 1; // Modify the original pointer, update the value
}

int main()
{
   int v = 5;
   int *p = &v;

   print(p);
   cout << "Before update, p points to: " << *p << endl;
   cout << "Before update, p address: " << p << endl;
   update(p); // Pass the address of the pointer to update function
   // Now p points to the next integer (if it exists)
   cout << "After update, p points to: " << *p << endl;
   cout << "After update, p address: " << p << endl;
   return 0;
}

/*
Value pointed by p: 5
Address stored in p: 0x5de69ffc54
Before update, p points to: 5
Before update, p address: 0x5de69ffc54
After update, p points to: 6
After update, p address: 0x5de69ffc54


same adress but value + 1;
*/
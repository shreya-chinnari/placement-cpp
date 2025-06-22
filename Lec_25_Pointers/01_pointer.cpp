#include <iostream>
using namespace std;

int main()
{
   int var = 10;

   cout << var << endl;

   // "address-of" operator : &
   // &var means “give me the memory address of the variable var.”
   // & used in this way is not a bitwise operator or a reference declarator here — it's asking: Where is var stored in memory?

   cout << "address of variable is : " << &var << endl;
   // OP: 0x7ff93ff7fc {hexadecimal format : 0-9, a-z}
   return 0;
}

// pointer stores the adress of variable
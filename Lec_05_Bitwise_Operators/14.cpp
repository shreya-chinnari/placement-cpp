// variables and scopes

#include <iostream>
using namespace std;

int main()
{
   int a = 3;
   cout << "a = " << a << endl;

   if (true)
   {
      int a = 5;                   // a is now local to this block
      cout << "a = " << a << endl; // prints 5
   }

   cout << "a = " << a << endl; // prints 3

   /* output :
         a = 3
         a = 5
         a = 3
   */

   // --------------------------------------------------------------------------------

   int b = 1;
   int b = 10; // error: redeclaration of 'b'

   // --------------------------------------------------------------------------------

   int i = 10;
   for (int i = 0; i < 5; i++) // this i is local to the for loop
   {
      cout << "hey" << i << endl;
   }

   /* output :
   hey0
   hey1
   hey2
   hey3
   hey4
   */

   // --------------------------------------------------------------------------------

   for (;;)
   {
      int b = 10;
      int b = 20; // error: redeclaration of 'b'
   }

   // but we can do this

   for (;;)
   {
      int b = 10;
      if (true)
      {
         int b = 20; // no error
         if (true)
         {
            int b = 30;        // no error
            cout << b << endl; // prints 30
         }
      }
   }

   return 0;
}

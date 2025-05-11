#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   cout << "number from 1 to n is: " << endl;

   for (int i = 1; i <= n; i++)
   {
      cout << i << " ";
   } // 1 2 3 4 5
   cout << endl;
   int i = 1;

   // without for loop conditions
   for (;;)
   {
      if (i <= n)
      {
         cout << i << " ";
      }
      else
      {
         break;
      }
      i++;
   } // 1 2 3 4 5
   cout << endl;

   for (int a = 0, b = 1; a >= 0 && b >= 1; a--, b--)
   {
      cout << a << " " << b << endl;
   }
   return 0;
}
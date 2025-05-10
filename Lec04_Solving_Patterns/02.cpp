/*
reverse pattern -----------------


Enter a number: 5
54321
54321
54321
54321
54321
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int i = 1;
   while (i <= n)
   {
      int j = 1;

      while (j <= n)
      {
         cout << n - j + 1; // important change
         j++;
      }
      cout << endl;
      i++;
   }

   return 0;
}
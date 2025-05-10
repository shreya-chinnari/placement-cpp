/*
   Enter a number: 7
      *
      **
      ***
      ****
      *****
      ******
      *******
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
      while (j <= i) // important change
      {
         cout << "*";
         j++;
      }

      cout << endl;
      i++;
   }
   return 0;
}
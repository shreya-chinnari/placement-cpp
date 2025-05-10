/*
Enter a number: 8
   1
   22
   333
   4444
   55555
   666666
   7777777
   88888888
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
      while (j <= i)
      {
         cout << i; // important change - row ka number hi print karna hai
         j++;
      }
      cout << endl;

      i++;
   }
   return 0;
}
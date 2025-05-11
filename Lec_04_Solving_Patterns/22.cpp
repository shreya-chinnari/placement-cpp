/*
Enter a number: 4
1234
 567
  89
   10
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int i = 1;
   int count = i;

   while (i <= n)
   {
      int space = i - 1;
      int j = 1;

      while (space)
      {
         cout << " ";
         space--;
      }

      while (j <= n - i + 1) // important
      {
         cout << count;
         j++;
         count++; // important
      }

      cout << endl;
      i++;
   }
   return 0;
}
/*
Enter a number: 4
1111
 222
  33
   4
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
      }

      cout << endl;
      count++; // important
      i++;
   }
   return 0;
}
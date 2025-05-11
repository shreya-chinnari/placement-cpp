/*
Enter a number: 4
   1
  23
 456
78910
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;
   int i = 1;
   int count = 1; // outside all loops

   while (i <= n)
   {
      int space = n - i;
      while (space)
      {
         cout << " ";
         space--;
      }

      int j = 1;
      while (j <= i)
      {
         cout << count;
         count++;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}
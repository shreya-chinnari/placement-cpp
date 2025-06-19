/*
Enter a number: 5
    1
   121
  12321
 1234321
123454321

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

      // space

      int space = n - i;
      while (space)
      {
         cout << " ";
         space--;
      }

      // ascending order

      int j = 1;
      while (j <= i)
      {
         cout << j;
         j++;
      }

      // descending order

      int start = i - 1;
      while (start)
      {
         cout << start;
         start--;
      }

      cout << endl;
      i++;
   }
   return 0;
}
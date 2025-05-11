/*
Enter a number: 5
1234554321
1234**4321
123****321
12******21
1********1

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
      // ascending order

      int j = 1;

      while (j <= n - i + 1)
      {
         cout << j;
         j++;
      }

      // stars

      while (j <= n + i - 1)
      {
         cout << "*";
         j++;
      }

      // descending order

      int start = n - i + 1;
      while (start >= 1)
      {
         cout << start;
         start--;
      }

      i++;
      cout << endl;
   }
   return 0;
}
/*
   Enter a number: 4
      1234
      1234
      1234
      1234
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   int i = 1;

   cout << "Enter a number: ";
   cin >> n;

   while (i <= n)
   {
      int j = 1;
      while (j <= n)
      {
         cout << j;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}

/*
The program takes an integer input n and prints a square pattern of numbers.
The outer loop controls the rows, and the inner loop controls the columns.
For each row, the numbers from 1 to n are printed, and this process is repeated n times.
*/

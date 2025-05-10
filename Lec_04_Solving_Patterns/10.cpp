/*
Enter a number: 5
   A B C D E
   B C D E F
   C D E F G
   D E F G H
   E F G H I
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
      char ch = 'A' + i - 1; // ASCII value of 'A' is 65

      int j = 1;
      while (j <= n)
      {
         cout << ch << " ";
         ch++;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}
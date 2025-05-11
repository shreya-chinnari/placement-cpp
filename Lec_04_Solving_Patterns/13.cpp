/*
Enter a number: 4
   A B C D
   B C D E
   C D E F
   D E F G
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
      char ch = 'A' + i - 1; // inside loop
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
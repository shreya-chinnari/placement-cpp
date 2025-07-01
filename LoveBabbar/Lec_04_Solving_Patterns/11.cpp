/*
Enter a number: 4
   A B C D
   A B C D
   A B C D
   A B C D
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
      // char ch = 'A'; // this works too

      int j = 1;
      char ch = 'A' + j - 1;

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
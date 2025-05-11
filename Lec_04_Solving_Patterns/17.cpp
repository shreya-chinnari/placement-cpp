/*
Enter a number: 5
E
D E
C D E
B C D E
A B C D E
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int i = 1;

   // pehla character nikaal lo, phir ch++

   while (i <= n)
   {
      char ch = 'A' + n - i; // important
      int j = 1;
      while (j <= i)
      {
         cout << ch << " ";
         ch++;
         j++;
      }
      i++;
      cout << endl;
   }
   return 0;
}

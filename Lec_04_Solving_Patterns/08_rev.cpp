/*
Enter a number: 6
1
2 1
3 2 1
4 3 2 1
5 4 3 2 1
6 5 4 3 2 1
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

      int j = 1;
      while (j <= i)
      {
         cout << i - j + 1 << " "; // important
         j++;
      }
      i++;
      cout << endl;
   }
   return 0;
}
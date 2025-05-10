/*
Enter a number: 5
1
2 3
3 4 5
4 5 6 7
5 6 7 8 9
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
      int count = i; // important change, moved it inside the loop
      while (j <= i)
      {
         cout << count << " ";
         count++;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}
/*alternative method without using a new variable

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
      int j = 0;    // important
      while (j < i) // important
      {
         cout << i + j << " "; // important
         j++;
      }
      cout << endl;
      i++;
   }

   // while (i <= n)
   // {
   //    int j = 1;
   //    while (j <= i)
   //    {
   //       cout << i + j << " ";
   //       j++;
   //    }
   //    cout << endl;
   //    i++;
   // }
   /*
   Enter a number: 5
      2
      3 4
      4 5 6
      5 6 7 8
      6 7 8 9 10
   */
   return 0;
}
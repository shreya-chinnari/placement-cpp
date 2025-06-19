/*
Enter a number: 5
    *
   **
  ***
 ****
*****
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
      // space print kar lo

      int space = n - i;
      while (space) // = while (space != 0)
      {
         cout << " ";
         space--;
      }
      // star print kar lo
      int j = 1;
      while (j <= i)
      {
         cout << "*";
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}

/*
Iteration 1 (i = 1):
      space = 4 - 1 = 3
      → prints 3 spaces: " "

      j = 1 to i = 1
      → prints 1 asterisk: "*"

            Output: *

Iteration 2 (i = 2):
      space = 4 - 2 = 2
      → prints 2 spaces: " "

      j = 1 to i = 2
      → prints 2 asterisks: "**"

            Output: **

Iteration 3 (i = 3):
      space = 4 - 3 = 1
      → prints 1 space: " "

      j = 1 to i = 3
      → prints 3 asterisks: "***"

            Output: ***

Iteration 4 (i = 4):
      space = 4 - 4 = 0
      → prints 0 spaces: ""

      j = 1 to i = 4
      → prints 4 asterisks: "****"

            Output: ****

*/
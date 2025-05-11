/*
Enter a number: 4
   1
  22
 333
4444
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
      int space = n - i;
      while (space)
      {
         cout << " ";
         space--;
      }

      int j = 1;
      while (j <= i)
      {
         cout << i;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}

/*
🔹 Iteration 1: i = 1

      space = 5 - 1 = 4 → print 4 spaces: " "
      j = 1 to 1 → print "1"

         Output: " 1"

🔹 Iteration 2: i = 2

      space = 5 - 2 = 3 → print 3 spaces: " "
      j = 1 to 2 → print "22"

         Output: " 22"

🔹 Iteration 3: i = 3

      space = 5 - 3 = 2 → print 2 spaces: " "
      j = 1 to 3 → print "333"

         Output: " 333"

🔹 Iteration 4: i = 4

      space = 5 - 4 = 1 → print 1 space: " "
      j = 1 to 4 → print "4444"

         Output: " 4444"

🔹 Iteration 5: i = 5

      space = 5 - 5 = 0 → print 0 spaces
      j = 1 to 5 → print "55555"

         Output: "55555"



*/
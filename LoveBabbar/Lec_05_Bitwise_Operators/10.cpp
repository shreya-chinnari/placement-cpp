#include <iostream>
using namespace std;

int main()
{
   for (int i = 0; i <= 15; i += 2)
   {
      cout << i << " ";

      if (i & 1)
      {
         continue;
      }
      i++;
   }
   // 0 3 5 7 9 11 13 15

   return 0;
}

/*
   : i & 1 checks if i is odd.
   : continue; skips the rest of the loop (including i++ from inside the body).
   : i += 2 happens after each loop iteration.
   : But i++ inside the loop adds an extra increment, unless it's skipped.


   Expression: i & 1 -- This uses a bitwise AND operator '&' to check if a number i is odd.
   Only odd numbers have their last bit set to 1 in binary.
   This checks only the last bit of i:
      : If last bit is 1 → result is 1 (true) → odd
      : If last bit is 0 → result is 0 (false) → even

   Decimal	Binary	LSB (Least Significant Bit)
   0	      0000	         0
   1	      0001	         1
   2	      0010	         0
   3	      0011           1
*/
/*
7. Reverse Integer

   Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

   Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21


   Constraints:
   -231 <= x <= 231 - 1

*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int ans = 0;

   while (n != 0)
   {

      // check for overflow
      if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10))
      {
         cout << "Overflow occurred" << endl;
         return 0;
      }

      int digit = n % 10;
      ans = ans * 10 + digit;

      n = n / 10;
   }
   cout << "Reversed number: " << ans << endl;
   return 0;
}
/*
Given an integer x, return true if x is a palindrome, and false otherwise.

   Example 1:
   Input: x = 121
   Output: true
   Explanation: 121 reads as 121 from left to right and from right to left.

   Example 2:
   Input: x = -121
   Output: false
   Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

   Example 3:
   Input: x = 10
   Output: false
   Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/

#include <iostream>
using namespace std;

bool isPalindrome(int x)
{
   // Negative numbers are not palindromes
   // Numbers ending with 0 (except 0 itself) are not palindromes
   if (x < 0 || (x % 10 == 0 && x != 0))
      return false;

   int reversedHalf = 0;
   while (x > reversedHalf)
   {
      int digit = x % 10;
      reversedHalf = reversedHalf * 10 + digit; // Shifts the previous digits left (like moving from 4 to 40, or 43 to 430). --> Adds the new digit at the rightmost position.
      x /= 10;
   }

   // For even length: x == reversedHalf
   // For odd length: x == reversedHalf / 10 (middle digit is ignored)
   return (x == reversedHalf || x == reversedHalf / 10);
}

int main()
{
   int x;
   cout << "Enter an integer: ";
   cin >> x;

   if (isPalindrome(x))
      cout << "true" << endl;
   else
      cout << "false" << endl;

   return 0;
}

/*
1st loop:
    reversedHalf = 1
    x = 1232

2nd loop:
    reversedHalf = 12
    x = 123

3rd loop:
    reversedHalf = 123
    x = 12

Now x < reversedHalf, so we stop

Check:
   x == reversedHalf / 10 → 12 == 123 / 10 → 12 == 12 ✅

*/
/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0

Constraints:

0 <= num <= 231 - 1
*/

#include <iostream>
using namespace std;

int main(int num)
{
   while (num >= 10)
   { // 38 -------------> 11
      int sum = 0;

      while (num > 0)
      {
         sum = sum + num % 10; // 0+8 = 8                  8+3=11 -------------> 0+1 = 1         1+1=2
         num = num / 10;       // 38/10 = 3 >0             3/10=0 -------------> 11/10 = 1       1/10=0
      }
      num = sum; // 11 -------------> 2
   }
   return 0;
}

/*
While the number has more than one digit (i.e., num >= 10):
   Split the number into digits (using modulo % 10 and division / 10).
   Sum those digits.
   Replace num with the sum.
   When num is less than 10, return it.

Iteration	Initial-num	   Digits-extracted	Sum of Digits	New num (sum)
1	           38	         8, 3	             8 + 3 = 11	      11
2	           11	         1, 1	             1 + 1 = 2	      2
-	           2	         —		                 —           Loop ends(num < 10)

------------------------------------------------------------------------------------------

🔁 Outer Loop #1 (num = 38)
Inner Iteration	Current num	         num % 10	          sum (after addition)        	num (after division)
1	                  38	                  8	                 0 + 8 = 8	                  38 / 10 = 3
2	                  3	                  3	                 8 + 3 = 11	               3 / 10 = 0

   ➡️ End of inner loop: sum = 11
   ➡️ Set num = sum = 11



🔁 Outer Loop #2 (num = 11)
Inner Iteration	Current num	         num % 10	          sum (after addition)	      num (after division)
1	                11	                 1	                 0 + 1 = 1	                    11 / 10 = 1
2	                1	                    1	                 1 + 1 = 2	                    1 / 10 = 0

   ➡️ End of inner loop: sum = 2
   ➡️ Set num = sum = 2
*/
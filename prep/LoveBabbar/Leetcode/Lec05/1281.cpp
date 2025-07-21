/*
Given an integer number n, return the difference between the product of its digits and the sum of its digits.


Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter an integer : ";
   cin >> n;

   int product = 1;
   int sum = 0;

   while (n != 0)
   {
      int digit = n % 10;
      product = product * digit;
      sum = sum + digit;

      n = n / 10;
   }

   int difference = product - sum;
   cout << "Product : " << product << endl;
   cout << "Sum : " << sum << endl;
   cout << "Difference : " << difference << endl;
   return difference;
}

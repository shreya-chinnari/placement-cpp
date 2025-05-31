// find sqrt(x) using BS

/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.
You must not use any built-in exponent function or operator. For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

Example 1:
   Input: x = 4
   Output: 2
Explanation: The square root of 4 is 2, so we return 2.
*/

#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

/*
    Function to calculate the integer part of square root using binary search.
    It returns floor(sqrt(n)).
*/
long long int sqrt_integer(int n)
{
   int start = 0, end = n;
   int ans = -1;

   while (start <= end)
   {
      long long int mid = start + (end - start) / 2;
      long long int square = mid * mid;

      if (square == n)
      {
         return mid; // Found perfect square
      }
      if (square < n)
      {
         ans = mid;       // Store possible result
         start = mid + 1; // Move right
      }
      else
      {
         end = mid - 1; // Move left
      }
   }
   return ans; // Return the floor of sqrt(n)
}

/*
    Function to add decimal precision to the square root result.
    - n: the original number
    - precision: how many decimal places to calculate
    - temp_solution: the integer part from sqrt_integer()
*/
double sqrt_fraction(int n, int precision, int temp_solution)
{
   double factor = 1;
   double ans = temp_solution;

   for (int i = 0; i < precision; i++)
   {
      factor = factor / 10; // Shift to next decimal digit

      // Move in small steps to approximate decimal precision
      for (double j = ans; j * j < n; j = j + factor)
      {
         ans = j;
      }
   }
   return ans;
}

/*
    Main function to demonstrate square root calculation.
*/
int main()
{
   int x;
   cout << "Enter a non-negative integer: ";
   cin >> x;

   if (x < 0)
   {
      cout << "Invalid input. Square root of negative numbers is undefined for integers." << endl;
      return 1;
   }

   int precision = 4; // Change this to get more/less decimal places

   long long int intPart = sqrt_integer(x);
   double finalAnswer = sqrt_fraction(x, precision, intPart);

   cout << "Integer part of sqrt(" << x << ") is: " << intPart << endl;
   cout << fixed << setprecision(precision); // Set decimal precision for output
   cout << "Square root of " << x << " up to " << precision << " decimal places is: " << finalAnswer << endl;

   return 0;
}

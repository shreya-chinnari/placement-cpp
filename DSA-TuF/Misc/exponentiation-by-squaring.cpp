#include <iostream>
using namespace std;

/**
 * Function: power
 * ----------------------
 * Computes {base^exponent} using Exponentiation by Squaring.
 * Efficiently calculates power in O(log exponent) time. // O(log n)
 *
 * Parameters:
 *   - base     : The base of the power expression
 *   - exponent : The exponent to raise the base to
 *
 * Returns:
 *   - The result of base raised to the power exponent
 */
long long power(int base, int exponent)
{
   // Use long long to avoid overflow during multiplication
   long long result = 1;
   long long curr_power = base;

   // Loop until all bits of the exponent are processed
   while (exponent > 0)
   {
      // If the least significant bit is set (i.e., exponent is odd)
      if (exponent % 2 == 1)
      {
         result *= curr_power;
      }

      // Move to the next bit: divide exponent by 2
      exponent /= 2;

      // Square the current power for next round
      curr_power *= curr_power;
   }

   // Final result is base^exponent
   return result;
}

int main()
{
   // Test cases: (base, exponent)
   int bases[] = {2, 3, 5, 7, 10};
   int exponents[] = {3, 4, 2, 5, 6};

   // Run and print results
   for (int i = 0; i < 5; ++i)
   {
      int base = bases[i];
      int exp = exponents[i];
      cout << base << "^" << exp << " = " << power(base, exp) << endl;
   }

   return 0;
}

#include <iostream>
using namespace std;

// TC : : O(n * log(m)) where n is the root and m is the number
// O(n) for the outer loop and O(log(m)) for the inner loop

// Optimized exponentiation by squaring with early stopping
long long power(int base, int exponent, int limit)
{
   long long result = 1;
   long long curr_power = base;

   while (exponent > 0)
   {
      if (exponent % 2 == 1)
      {
         result *= curr_power;
         if (result > limit)
            return result; // early exit
      }

      exponent /= 2;
      if (exponent)
      {
         curr_power *= curr_power;
         if (curr_power > limit)
            return curr_power; // early exit
      }
   }

   return result;
}

// Brute force nth root using optimized power
int nthRootBruteForce(int n, int m)
{
   for (int i = 1; i <= m; ++i)
   {
      long long powResult = power(i, n, m);

      if (powResult == m)
         return i;
      else if (powResult > m)
         break;
   }
   return -1;
}

int main()
{
   int n = 3, m = 27;
   cout << "Nth root of " << m << " for N = " << n << " is: " << nthRootBruteForce(n, m) << endl;

   n = 4, m = 69;
   cout << "Nth root of " << m << " for N = " << n << " is: " << nthRootBruteForce(n, m) << endl;

   return 0;
}

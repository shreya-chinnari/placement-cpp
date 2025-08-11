#include <iostream>
using namespace std;

// TC :  : O(n * m^(1/n)) where n is the root and m is the number
// O(n) for the outer loop and O(m^(1/n)) for the inner loop

int nthRootBruteForce(int n, int num)
{

   for (int root = 1; root <= num; root++)
   {
      long long root_power_n = 1;

      for (int i = 0; i < n; i++)
      {
         root_power_n *= root; // Calculate (root^n)

         if (root_power_n > num)
            break; // If root^n exceeds num, no need to continue further
      }

      if (root_power_n == num)
      {
         return root; // If root^n equals num, we found the nth root
      }

      // The following check is needed to break the outer loop early if root^n exceeds num,
      // since the inner loop only breaks the power calculation, not the root search.
      else if (root_power_n > num)
      {
         break; // If root^n exceeds num, no need to check further roots
      }
   }
   return -1; // If no root found, return -1
}

int main()
{
   int n = 3, m = 27;
   cout << "Nth root of " << m << " for N = " << n << " is: " << nthRootBruteForce(n, m) << endl;

   n = 4, m = 69;
   cout << "Nth root of " << m << " for N = " << n << " is: " << nthRootBruteForce(n, m) << endl;

   return 0;
}
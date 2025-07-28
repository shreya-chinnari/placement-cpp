#include <iostream>
using namespace std;

// Computes mid^n safely and returns the result or exits early if it exceeds m
// Returns -1 if mid^n exceeds m to signal it's "too big"
long long computePower(int mid, int n, int m)
{
   long long result = 1;
   for (int i = 1; i <= n; i++)
   {
      result *= mid;
      if (result > m)
         return -1; // Early exit: too big
   }
   return result;
}

// Function to find the integer nth root of m using binary search
int NthRoot(int n, int m)
{
   if (m == 0)
      return 0;
   if (m == 1)
      return 1;

   int low = 1, high = m;

   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      long long power = computePower(mid, n, m);

      if (power == m)
      {
         return mid; // Found the exact root
      }
      else if (power == -1 || power > m)
      {
         high = mid - 1; // Too large
      }
      else
      {
         low = mid + 1; // Too small
      }
   }

   return -1; // No integer nth root exists
}

int main()
{
   int n = 3, m = 27;
   int ans = NthRoot(n, m);
   cout << "The answer is: " << ans << "\n";

   // Additional test cases
   cout << "Nth root of 16 with n=2: " << NthRoot(2, 16) << "\n"; // Should print 4
   cout << "Nth root of 69 with n=4: " << NthRoot(4, 69) << "\n"; // Should print -1
   cout << "Nth root of 1 with n=6: " << NthRoot(6, 1) << "\n";   // Should print 1
   cout << "Nth root of 0 with n=5: " << NthRoot(5, 0) << "\n";   // Should print 0

   return 0;
}

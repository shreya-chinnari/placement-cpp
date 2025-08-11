
#include <iostream>
using namespace std;

// Helper function to compute mid^n and compare with m
// Returns:
//   1 → mid^n == m
//   0 → mid^n < m
//   2 → mid^n > m
int comparePower(int mid, int n, int m)
{
   long long result = 1;
   for (int i = 1; i <= n; i++)
   {
      result *= mid;
      if (result > m)
         return 2; // Exceeds m
   }
   if (result == m)
   {
      return 1; // Exactly equals m
   }
   else
   {
      return 0; // Less than m
   }
}

// Function to find integer nth root of m using binary search
int NthRoot(int n, int m)
{
   if (m == 0)
      return 0; // Edge case
   if (m == 1)
      return 1; // Edge case

   int low = 1, high = m;

   while (low <= high)
   {
      int mid = low + (high - low) / 2;
      int result = comparePower(mid, n, m);

      if (result == 1)
      {
         return mid; // Found exact nth root
      }
      else if (result == 0)
      {
         low = mid + 1; // Move right
      }
      else
      {
         high = mid - 1; // Move left
      }
   }

   return -1; // No integer root found
}

int main()
{
   int n = 3, m = 27;
   int ans = NthRoot(n, m);
   cout << "The answer is: " << ans << "\n";
   n = 3, m = 0;
   ans = NthRoot(n, m);
   cout << "The answer is: " << ans << "\n";
   n = 1, m = 27;
   ans = NthRoot(n, m);
   cout << "The answer is: " << ans << "\n";
   n = 4, m = 27;
   ans = NthRoot(n, m);
   cout << "The answer is: " << ans << "\n";
   return 0;
}

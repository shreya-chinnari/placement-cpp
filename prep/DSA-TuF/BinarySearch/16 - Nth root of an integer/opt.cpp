#include <iostream>
using namespace std;

// Function to find the square root of a number using Binary Search

int NthRootOfM(int n, int m)
{
   int s = 1, e = m; // search space from 1 to m

   int ans = -1; // variable to store the nth root of m

   if (m == 0)
      return 0; // edge case for m = 0
   if (m == 1)
      return 1; // edge case for m = 1

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      long long mid_power_n = 1; // to store mid^n

      for (int i = 0; i < n; i++)
      {
         mid_power_n *= mid; // Calculate mid^n : calculate mid*mid*...*mid (n times)

         if (mid_power_n > m)
         {
            break; // If mid^n exceeds m, no need to continue further}
         }
      }

      if (mid_power_n == m)
      {
         return mid; // If mid^n equals m, we found the nth root
      }

      else if (mid_power_n < m)
      {
         s = mid + 1;
      }
      else
      {
         e = mid - 1;
      }
   }
   return -1; // If no root found, return -1
}

int main()
{
   int n = 3, m = 27;
   int ans = NthRootOfM(n, m);
   cout << "The answer is: " << ans << "\n";

   m = 0;
   ans = NthRootOfM(n, m);
   cout << "The answer is: " << ans << "\n";

   m = 1;
   ans = NthRootOfM(n, m);
   cout << "The answer is: " << ans << "\n";

   n = 4;
   m = 69;
   ans = NthRootOfM(n, m);
   cout << "The answer is: " << ans << "\n";
   return 0;
}
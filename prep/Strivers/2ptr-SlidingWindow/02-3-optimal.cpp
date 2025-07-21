// Type 2  : Longest Subarray / Substring

// We want to maintain the max length window without unnecessary shrinking (i.e., don’t shrink if current window already gives max length)

// Expand r (right end)
// Shrink l only if needed to maintain sum ≤ k
// Keep updating maxLen only if r - l + 1 is longer than previous

#include <iostream>
using namespace std;

// Function 1: Return only the max length
int maxLength(int arr[], int n, int k)
{
   int maxLen = 0;
   int l = 0, r = 0;
   int sum = 0;

   for (int r = 0; r < n; r++) // expand
   {
      sum += arr[r];

      // Shrink window from left while sum > k

      // changed while to if [O(n+n) --> O(n)]
      if (sum > k && l <= r)
      {
         sum -= arr[l];
         l++;
      }

      // Now sum <= k
      if (sum <= k)
      {
         maxLen = max(maxLen, r - l + 1);
      }
   }
   return maxLen;
}

// does not work for : print subarray, print index
// only for max length

int main()
{
   int arr[10] = {2, 7, 9, 4, 2, 5, 7, 3, 2, 2};
   int k = 19;

   cout << "Max length : " << maxLength(arr, 10, k) << endl;

   return 0;
}
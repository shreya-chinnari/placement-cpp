#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Step 1: Generate all subarrays
// Step 2: Find maximum in each subarray
// Step 3: Add it to the sum
// TC: O(n^2)
// SC: O(1)

int sumOfMaximumInSubarrays(int arr[], int n)
{
   long long sum = 0;
   int mod = 1e9 + 7;

   // for each starting index
   for (int i = 0; i < n; i++)
   {
      int maxEl = arr[i];

      // for each subarray starting at i
      for (int j = i; j < n; j++)
      {
         maxEl = max(maxEl, arr[j]);
         sum = (sum + maxEl) % mod;
      }
   }

   return (int)sum;
}

int main()
{
   int arr[] = {3, 1, 2, 4};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << sumOfMaximumInSubarrays(arr, n) << endl;

   return 0;
}

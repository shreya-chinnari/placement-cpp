#include <bits/stdc++.h>
using namespace std;

// step 1: generate all subarrays
// step 2: find minimum in each subarray
// step 3 : sum of minimums

// TC : O(n^2)
// SC : O(1)

int sumOfMinimumInSubarrays(int arr[], int n)
{
   int sum = 0;

   int mod = (int)(1e9 + 7);
   // we use modulo because the answer can be large

   // for each index
   for (int i = 0; i < n; i++)
   {
      int minEl = arr[i];

      // for each subarray of that index
      for (int j = i; j < n; j++)
      {
         minEl = min(minEl, arr[j]);
         sum = (sum + minEl) % mod;
      }
   }

   return sum;
}

int main()
{
   int arr[] = {3, 1, 2, 4};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << sumOfMinimumInSubarrays(arr, n) << endl;

   return 0;
}
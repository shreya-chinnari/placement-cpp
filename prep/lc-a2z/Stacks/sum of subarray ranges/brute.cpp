#include <bits/stdc++.h>
using namespace std;

// step 1: generate all subarrays
// step 2: find range of each subarray
//    [largest element - smallest element] of subarray
// step 3 : sum of ranges

// TC : O(n^2)
// SC : O(1)

int sumOfSubarrayRanges(int arr[], int n)
{
   int sum = 0;

   for (int i = 0; i < n; i++)
   {
      int largest = arr[i];
      int smallest = arr[i];

      for (int j = i + 1; j < n; j++)
      {
         largest = max(largest, arr[j]);
         smallest = min(smallest, arr[j]);

         sum = sum + (largest - smallest);
      }
   }

   return sum;
}

int main()
{
   int arr[] = {3, 1, 2, 4};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << sumOfSubarrayRanges(arr, n) << endl;

   return 0;
}
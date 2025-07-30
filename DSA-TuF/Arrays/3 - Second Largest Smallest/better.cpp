#include <iostream>
using namespace std;

// without sorting : tc reduced from O(n log n) to O(2n)
// use of 2 traverals, hence O(2n)
// first to find the largest and smallest
// second to find the second largest and second smallest

pair<int, int> secondLargestAndSmallest(int arr[], int n)
{

   // edge case :
   if (n == 0 || n == 1)
   {
      return {-1, -1}; // Not enough elements
   }

   int s = INT_MAX, ss = INT_MAX;
   int l = INT_MIN, sl = INT_MIN;

   // 1. find largest and smallest
   for (int i = 0; i < n; i++)
   {
      s = min(s, arr[i]);
      l = max(l, arr[i]);
   }

   // 2. find second largest and second smallest
   for (int i = 0; i < n; i++)
   {
      if (arr[i] < ss && arr[i] != s)
      {
         ss = arr[i];
      }
      if (arr[i] > sl && arr[i] != l)
      {
         sl = arr[i];
      }
   }
   return {sl, ss}; // return second largest and second smallest
}

int main()
{

   int arr[] = {12, 13, 1, 10, 34};
   int n = sizeof(arr) / sizeof(arr[0]);
   pair<int, int> result = secondLargestAndSmallest(arr, n);
   cout << result.first << " " << result.second << endl; // Output second largest and second smallest

   return 0;
}
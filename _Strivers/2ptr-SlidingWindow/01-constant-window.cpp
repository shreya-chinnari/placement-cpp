// Sliding window - Type 1 : Constant Window

// Given an array of integers arr of size n and an integer k, find the maximum sum of any subarray of size k.
// This is also known as the maximum sum of k consecutive elements in the array.

#include <iostream>
using namespace std;

int maxSubArray(int arr[], int n, int k)
{
   // Step 1: Edge case check
   if (k > n)
      return -1; // Not enough elements

   int sum = 0;
   int start = 0;
   int end = k - 1;

   // Step 2: Calculate the sum of the first window

   for (int i = 0; i < k; i++)
   {
      sum += arr[i];
   }
   cout << "Initial window [start: " << start << ", end: " << end << "] sum = " << sum << endl;

   int max_sum = sum;

   while (end < n - 1)
   {
      sum = sum - arr[start];
      start++;
      end++;
      sum = sum + arr[end];

      cout << "Window [start: " << start << ", end: " << end << "] sum = " << sum << endl;

      sum = max(max_sum, sum);
   }

   return max_sum;
}

int main()
{
   int arr[10] = {3, 8, 2, 8, 3, 1, 0, 2, 9, 5};
   int max_sum = maxSubArray(arr, 10, 4);
   cout << "max_sum = " << max_sum;
   return 0;
};

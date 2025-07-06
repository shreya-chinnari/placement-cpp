#include <iostream>
#include <algorithm>
using namespace std;

int maxSubArray(int arr[], int n, int k)
{
   if (k > n)
      return -1;

   int sum = 0;

   // Initial window sum
   for (int i = 0; i < k; i++)
   {
      sum += arr[i];
   }

   int max_sum = sum;
   int start = 0, end = k - 1;

   // Track max window indices
   int max_start = 0, max_end = k - 1;

   cout << "Initial window [start: " << start << ", end: " << end << "] sum = " << sum << endl;

   // Slide the window
   while (end < n - 1)
   {
      sum -= arr[start];
      start++;
      end++;
      sum += arr[end];

      cout << "Window [start: " << start << ", end: " << end << "] sum = " << sum << endl;

      if (sum > max_sum)
      {
         max_sum = sum;
         max_start = start;
         max_end = end;
      }
   }

   cout << "\nMaximum Sum Subarray of size " << k << ":\n";
   cout << "Start index: " << max_start << ", End index: " << max_end << endl;
   cout << "Maximum Sum: " << max_sum << endl;

   return max_sum;
}

int main()
{
   int arr[10] = {3, 8, 2, 8, 3, 1, 0, 2, 9, 5};
   int max_sum = maxSubArray(arr, 10, 4);
   cout << "max_sum = " << max_sum;
   return 0;
};
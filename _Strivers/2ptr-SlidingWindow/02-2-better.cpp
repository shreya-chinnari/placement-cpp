// Type 2  : Longest Subarray / Substring

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
      while (sum > k && l <= r)
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

// Function 2: Return the start and end indices of the max subarray
pair<int, int> maxLengthIndex(int arr[], int n, int k)
{
   int maxLen = 0, sum = 0, l = 0;
   int start = 0, end = 0;

   for (int r = 0; r < n; r++)
   {
      sum += arr[r];

      while (sum > k && l <= r)
      {
         sum -= arr[l];
         l++;
      }

      if (r - l + 1 > maxLen)
      {
         maxLen = r - l + 1;
         start = l;
         end = r;
      }
   }

   return {start, end};
}

// Function 3: Print the actual subarray with max length and sum <= k
void maxLengthSubarray(int arr[], int n, int k)
{
   pair<int, int> range = maxLengthIndex(arr, n, k);
   cout << "Subarray: ";
   for (int i = range.first; i <= range.second; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main()
{
   int arr[10] = {2, 7, 9, 4, 2, 5, 7, 3, 2, 2};
   int k = 19;

   cout << "Max length : " << maxLength(arr, 10, k) << endl;

   pair<int, int> indices = maxLengthIndex(arr, 10, k);
   cout << "Start index: " << indices.first << ", End index: " << indices.second << endl;

   maxLengthSubarray(arr, 10, k);

   return 0;
}
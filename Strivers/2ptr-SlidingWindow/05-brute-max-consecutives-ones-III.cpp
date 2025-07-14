
// ❓ Problem: Find the maximum length of a subarray with all 1s if you are allowed to flip at most k zeroes.

// TC : O(n^2)
// SC : O(1)

#include <iostream>
using namespace std;

int maxOnes(int arr[], int n, int k)
{
   int maxLen = 0;

   for (int i = 0; i < n; i++) // try all starting points
   {
      int zeros = 0; // reset 0s for each new i

      for (int j = i; j < n; j++) // try all ending points
      {
         if (arr[j] == 0)
            zeros++;

         if (zeros <= k) // valid window
         {
            int len = j - i + 1;
            maxLen = max(maxLen, len);
         }
         else // too many 0s, break
         {
            break;
         }
      }
   }

   return maxLen;
}

int main()
{
   int arr[11] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
   cout << "max len : " << maxOnes(arr, 11, 2);

   return 0;
}

// ❓ Problem: Find the maximum length of a subarray with all 1s if you are allowed to flip at most k zeroes.

// TC : O(2n)
// SC : O(1)

#include <iostream>
using namespace std;

int maxOnes(int arr[], int n, int k)
{
   int l = 0, r = 0;
   int zeros = 0;
   int maxLen = 0, len = 0;

   // Slide the right pointer across the array
   while (r < n)
   {
      // If the current element is 0, increment the zero count
      if (arr[r] == 0)
         zeros++;

      // If number of 0s exceeds k, shrink the window from the left
      while (zeros > k)
      {
         // If we're removing a 0 from the window, decrement zero count
         if (arr[l] == 0)
            zeros--;
         // Move the left pointer to shrink the window
         l++;
      }

      // ✅ Only consider valid windows where number of 0s ≤ k
      if (zeros <= k)
      {
         len = r - l + 1; // ✅ Calculate current window length
         maxLen = max(len, maxLen);
      }
      r++; // expand window
   }

   return maxLen;
}

/* TO RETURN INDEX


      // ✅ Only consider valid windows where number of 0s ≤ k

      if (zeros <= k)
      {
         len = r - l + 1;
         if (len > maxLen)
         {
            maxLen = len;
            start = l;
            end = r;
         }
      }
*/

int main()
{
   int arr[11] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
   cout << "max len : " <<

       return 0;
}
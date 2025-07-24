// unique elements in a rotated sorted array

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n, int k)
{
   int s = 0, e = n - 1, mid;

   while (s <= e)
   {
      // STEP 1: Find mid

      mid = s + (e - s) / 2;

      // STEP 2: Check if mid is the target
      if (arr[mid] == k)
      {
         return mid; // Target found
      }

      // STEP 3: Determine which half is sorted

      // Left half is sorted
      if (arr[s] <= arr[mid])
      {
         // Check if target is in the left half
         if (arr[s] <= k && k < arr[mid])
         {
            e = mid - 1; // Search in left half
         }
         else
         {
            s = mid + 1; // Search in right half
         }
      }
      // Right half is sorted
      else if (arr[mid] <= arr[e])
      {
         // Check if target is in the right half
         if (arr[mid] < k && k <= arr[e])
         {
            s = mid + 1; // Search in right half
         }
         else
         {
            e = mid - 1; // Search in left half
         }
      }
   }
   return -1; // Target not found
}

int main()
{
   vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
   int n = 9, k = 1;
   int ans = search(arr, n, k);
   if (ans == -1)
      cout << "Target is not present.\n";
   else
      cout << "The index is: " << ans << "\n";
   return 0;
}
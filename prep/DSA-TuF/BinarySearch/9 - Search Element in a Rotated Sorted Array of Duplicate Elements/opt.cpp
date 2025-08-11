#include <bits/stdc++.h>
using namespace std;

bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
   int s = 0, e = arr.size() - 1;
   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] == k)
         return true; // Target found

      // If duplicates are present, we cannot determine the sorted half, so keep SHRINKING the search space
      if (arr[s] == arr[mid] && arr[mid] == arr[e])
      {
         s++;      // Move start forward
         e--;      // Move end backward
         continue; // Continue to the next iteration
      }

      // once you are done with shrinking all the duplicates, continue with normal BS logic for unique elements in an array

      // LHS sorted?
      if (arr[s] <= arr[mid])
      {
         // element present?
         if (arr[s] <= k && k <= arr[mid])
         {
            e = mid - 1; // search in left half
         }
         else
         {
            s = mid + 1; // search in right half
         }
      }
      // RHS sorted?
      else if (arr[mid] <= arr[e])
      {
         // element present?
         if (arr[mid] <= k && k <= arr[e])
         {
            s = mid + 1; // search in right half
         }
         else
         {
            e = mid - 1; // search in left half
         }
      }
   }
   return false; // Target not found
}

int main()
{
   vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
   int k = 3;
   bool ans = searchInARotatedSortedArrayII(arr, k);
   if (!ans)
      cout << "Target is not present.\n";
   else
      cout << "Target is present in the array.\n";
   return 0;
}
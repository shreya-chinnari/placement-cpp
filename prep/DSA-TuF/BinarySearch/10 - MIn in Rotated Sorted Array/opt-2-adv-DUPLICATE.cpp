#include <bits/stdc++.h>
using namespace std;

int findMinInRotatedSortedArrayWithDuplicates(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;
   int ans = INT_MAX;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // Case 1: Complete sorted subarray
      if (arr[s] < arr[e])
      {
         ans = min(ans, arr[s]);
         break;
      }

      // Case 2: If duplicates prevent determining sorted side
      if (arr[s] == arr[mid] && arr[mid] == arr[e])
      {
         ans = min({ans, arr[s], arr[mid], arr[e]});
         s++;
         e--;
         continue;
      }

      // Case 3: Left half is sorted
      if (arr[s] <= arr[mid])
      {
         ans = min(ans, arr[s]);
         s = mid + 1;
      }
      // Case 4: Right half is sorted
      else if (arr[mid] <= arr[e])
      {
         ans = min(ans, arr[mid]);
         e = mid - 1;
      }
   }

   return ans;
}

int main()
{
   vector<int> arr = {3, 3, 3, 4, 5, 6, 7, 8, 1, 2, 3}; // rotated with duplicates
   int minElement = findMinInRotatedSortedArrayWithDuplicates(arr);
   cout << "The minimum element is: " << minElement << "\n";
   return 0;
}

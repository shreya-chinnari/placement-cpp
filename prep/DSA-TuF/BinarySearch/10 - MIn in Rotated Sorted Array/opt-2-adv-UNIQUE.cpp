
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;

   int ans = INT_MAX;

   while (s <= e)
   {

      int mid = s + (e - s) / 2;

      // if search space is already sorted,
      // then arr[s] will always be the minimum
      // element in the search space

      if (arr[s] <= arr[e])
      {
         ans = min(ans, arr[s]);
         break; // No need to continue, we found the minimum
      }

      // otherise, we will check which half is sorted
      if (arr[s] <= arr[mid])
      {
         ans = min(ans, arr[s]);
         s = mid + 1;
      }
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
   vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
   int ans = findMin(arr);
   cout << "The minimum element is: " << ans << "\n";
   return 0;
}

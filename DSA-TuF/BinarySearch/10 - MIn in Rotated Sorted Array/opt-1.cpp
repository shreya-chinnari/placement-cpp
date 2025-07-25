
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;

   int ans = INT_MAX;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // is LHS sorted?
      if (arr[s] <= arr[mid])
      {
         // keep the minimum
         ans = min(ans, arr[s]);
         // eliminate the left half, search in right half
         s = mid + 1;
      }

      // is RHS sorted?
      else if (arr[mid] <= arr[e])
      {
         // keep the minimum
         ans = min(ans, arr[mid]);
         // eliminate the right half, search in left half
         e = mid - 1;
      }
   }
   // after the loop ends, we will have the minimum element
   return ans;
}

int main()
{
   vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
   int ans = findMin(arr);
   cout << "The minimum element is: " << ans << "\n";
   return 0;
}

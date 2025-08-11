// code from [find smallest element in rotated sorted array]
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;

   int ans = INT_MAX;

   int index = -1; // add index variable

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // search space is already sorted
      // then arr[low] will always be
      // the minimum in that search space:

      if (arr[s] <= arr[e])
      {
         if (arr[s] < ans)
         {
            index = s; // update index if we found a new minimum
            ans = arr[s];
         }
         break;
      }
      // if left part is sorted:
      if (arr[s] <= arr[mid])
      {
         // keep the minimum:
         if (arr[s] < ans)
         {
            index = s;
            ans = arr[s];
         }
         // eliminate the left part:
         s = mid + 1;
      }
      // if right part is sorted:
      else if (arr[mid] <= arr[e])
      {
         // keep the minimum:
         if (arr[mid] < ans)
         {
            index = mid;
            ans = arr[mid];
         }
         // eliminate the right part:
         e = mid - 1;
      }
   }
   return index;
}

int main()
{
   vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
   int index = findMin(arr);
   cout << "number of rotations = index of smallest number: " << index << "\n";
   return 0;
}

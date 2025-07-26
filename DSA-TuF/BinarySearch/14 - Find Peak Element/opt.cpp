

#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &arr)
{
   int n = arr.size();

   // 1. single elememt case

   if (n == 1)
      return arr[0];

   // 2. check for first element

   if (arr[0] > arr[1])
      return arr[0];

   // 3. check for last element

   if (arr[n - 1] > arr[n - 1])
      return arr[n - 1];

   // 4. check for middle elements

   int s = 1, e = n - 2; // IMPORTANT

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // Check if mid is a peak element
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
      {
         return arr[mid];
      }

      // If the left neighbor is smaller,
      // then arr[mid] is on increasing slope,
      // so the peak lies on the right side

      if (arr[mid] > arr[mid - 1])
      {
         s = mid + 1;
      }

      // If the right neighbor is smaller,
      // then arr[mid] is on decreasing slope,
      // so the peak lies on the left side

      else
      {
         e = mid - 1;
      }
   }

   return -1;
}

int main()
{
   vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
   int ans1 = findPeakElement(arr1);
   cout << "The peak element: " << ans1 << "\n";

   vector<int> arr2 = {1, 2, 1, 3, 1};
   int ans2 = findPeakElement(arr2);
   cout << "The peak element: " << ans2 << "\n";
   return 0;
}

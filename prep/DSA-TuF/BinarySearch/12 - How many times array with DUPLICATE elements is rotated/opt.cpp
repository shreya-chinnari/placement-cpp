#include <bits/stdc++.h>
using namespace std;

int findRotationCountWithDuplicates(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;
   int ans = INT_MAX;
   int index = -1;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // Case 1: Fully sorted subarray
      if (arr[s] < arr[e])
      {
         if (arr[s] < ans)
         {
            ans = arr[s];
            index = s;
         }
         break;
      }

      // Case 2: Duplicates on both ends
      if (arr[s] == arr[mid] && arr[mid] == arr[e])
      {
         if (arr[s] < ans)
         {
            ans = arr[s];
            index = s;
         }
         s++;
         e--;
         continue;
      }

      // Case 3: Left half sorted
      if (arr[s] <= arr[mid])
      {
         if (arr[s] < ans)
         {
            ans = arr[s];
            index = s;
         }
         s = mid + 1;
      }

      // Case 4: Right half sorted
      else if (arr[mid] <= arr[e])
      {
         if (arr[mid] < ans)
         {
            ans = arr[mid];
            index = mid;
         }
         e = mid - 1;
      }
   }

   return index;
}

int main()
{
   vector<int> arr = {3, 3, 3, 4, 5, 6, 7, 8, 1, 2, 3}; // Rotated 8 times
   int rotationCount = findRotationCountWithDuplicates(arr);
   cout << "Array has been rotated " << rotationCount << " times.\n";
   return 0;
}

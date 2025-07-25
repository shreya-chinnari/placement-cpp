// keep [ans] only if required

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;
   int ans = INT_MAX;
   while (s <= e)
   {
      int mid = s + (e - s) / 2;
      if (arr[s] <= arr[e])
      {
         if (arr[s] < ans)
         {
            ans = arr[s];
         }
         break;
      }
      if (arr[s] <= arr[mid])
      {
         if (arr[s] < ans)
         {
            ans = arr[s];
         }
         s = mid + 1;
      }
      else if (arr[mid] <= arr[e])
      {
         if (arr[mid] < ans)
         {
            ans = arr[mid];
         }
         e = mid - 1;
      }
   }
   return ans;
}

int findMinIndex(vector<int> &arr)
{
   int s = 0, e = arr.size() - 1;
   int index = -1;
   int ans = INT_MAX;
   while (s <= e)
   {
      int mid = s + (e - s) / 2;
      if (arr[s] <= arr[e])
      {
         if (arr[s] < ans)
         {
            index = s;
         }
         break;
      }
      if (arr[s] <= arr[mid])
      {
         if (arr[s] < ans)
         {
            index = s;
         }
         s = mid + 1;
      }
      else if (arr[mid] <= arr[e])
      {
         if (arr[mid] < ans)
         {
            index = mid;
         }
         e = mid - 1;
      }
   }
   return index;
}

int main()
{
   vector<int> arr = {4, 5, 6, 7, 1, 2, 3};

   int mini = findMin(arr);
   cout << "minimum element " << mini << "\n\n";

   int index = findMinIndex(arr);
   cout << "index of smallest number: " << index << "\n";
   cout << "number of rotations: " << index << "\n";

   return 0;
}

/*
   minimum element 1

   index of smallest number: 4
   number of rotations: 4
 */
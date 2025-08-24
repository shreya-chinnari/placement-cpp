#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
   int n = arr.size();
   int waterTrapped = 0;

   // For each index, compute leftMax and rightMax manually
   for (int i = 0; i < n; i++)
   {
      // Compute leftMax[i] = max height from 0 → i
      int leftMax = arr[i];
      for (int j = 0; j <= i; j++)
      {
         leftMax = max(leftMax, arr[j]);
      }

      // Compute rightMax[i] = max height from i → n-1
      int rightMax = arr[i];
      for (int j = i; j < n; j++)
      {
         rightMax = max(rightMax, arr[j]);
      }

      waterTrapped += min(leftMax, rightMax) - arr[i];
   }

   return waterTrapped;
}

int main()
{
   vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   cout << "The water that can be trapped is " << trap(arr) << endl;
   return 0;
}

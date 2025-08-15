#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
   int n = arr.size();
   int left = 0, right = n - 1;   // Two pointers at both ends // O(1) space for pointers
   int res = 0;                   // Accumulator for trapped water // O(1) space for accumulator
   int leftMax = 0, rightMax = 0; // Track highest walls seen from each side // O(1) space for max height trackers

   // TC: O(n) time → each element processed at most once, both pointers together traverse N elements
   while (left <= right)
   {
      if (arr[left] <= arr[right])
      {
         // Process left side if left wall is smaller
         if (arr[left] >= leftMax)
         {
            leftMax = arr[left]; // Update leftMax if current is taller, // TC : O(1) update
         }
         else
         {
            res += leftMax - arr[left]; // Water trapped at left, // O(1) computation
         }
         left++;
      }
      else if (arr[right] < arr[left])
      {
         // Process right side if right wall is smaller
         if (arr[right] >= rightMax)
         {
            rightMax = arr[right]; // Update rightMax if current is taller, // TC : O(1) update
         }
         else
         {
            res += rightMax - arr[right]; // Water trapped at right, // O(1) computation
         }
         right--;
      }
   }
   return res;
}

int main()
{
   vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   cout << "The water that can be trapped is " << trap(arr) << endl;
}

/*
--------------------------------------------------
Time Complexity Analysis:
--------------------------------------------------
- Single while loop visiting each index at most once: O(n)

--------------------------------------------------
Space Complexity Analysis:
--------------------------------------------------
- Constant extra variables (pointers & max trackers): O(1)
--------------------------------------------------
*/

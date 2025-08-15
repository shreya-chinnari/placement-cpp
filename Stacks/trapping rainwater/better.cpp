#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
   int n = arr.size();
   if (n == 0)
      return 0;

   // Step 1: Compute suffix max array
   // TC: O(n), SC: O(n)
   vector<int> rightMax(n);
   rightMax[n - 1] = arr[n - 1];
   for (int i = n - 2; i >= 0; i--)
   {
      rightMax[i] = max(rightMax[i + 1], arr[i]);
   }

   // Step 2: Traverse and keep track of prefix max on the fly
   // TC: O(n), SC: O(1) extra
   int leftMax = 0;
   int waterTrapped = 0;
   for (int i = 0; i < n; i++)
   {
      leftMax = max(leftMax, arr[i]); // Update prefix max dynamically
      waterTrapped += min(leftMax, rightMax[i]) - arr[i];
   }

   return waterTrapped;
}

int main()
{
   vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
   cout << "The water that can be trapped is " << trap(arr) << endl;
}

/*
--------------------------------------------------
Overall Time Complexity:
- Step 1: O(n)
- Step 2: O(n)
TOTAL: O(2n) → O(n)

Overall Space Complexity:
- rightMax: O(n)
- leftMax: O(1) (computed on the fly)
TOTAL: O(n)
--------------------------------------------------
*/

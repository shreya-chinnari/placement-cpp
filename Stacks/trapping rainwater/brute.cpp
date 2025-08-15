#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
   int n = arr.size();
   if (n == 0)
      return 0;

   // Step 1: Precompute prefix max array
   // TC: O(n), SC: O(n)
   vector<int> leftMax(n);
   leftMax[0] = arr[0];
   for (int i = 1; i < n; i++)
   {
      leftMax[i] = max(leftMax[i - 1], arr[i]);
   }

   // Step 2: Precompute suffix max array
   // TC: O(n), SC: O(n)
   vector<int> rightMax(n);
   rightMax[n - 1] = arr[n - 1];
   for (int i = n - 2; i >= 0; i--)
   {
      rightMax[i] = max(rightMax[i + 1], arr[i]);
   }

   // Step 3: Calculate trapped water
   // TC: O(n), SC: O(1) extra (excluding leftMax/rightMax storage)
   int waterTrapped = 0;
   for (int i = 0; i < n; i++)
   {
      waterTrapped += min(leftMax[i], rightMax[i]) - arr[i];
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
- Step 3: O(n)
TOTAL: O(3n) → O(n)

Overall Space Complexity:

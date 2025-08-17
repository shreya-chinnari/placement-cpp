#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
   long long subArrayRanges(vector<int> &nums)
   {
      int n = nums.size();

      // Final result variable
      long long res = 0;

      // ---------- Contribution as Maximum ----------
      // Each element contributes as maximum in certain subarrays
      // Use monotonic decreasing stack to find how far it can extend
      stack<int> stMax;

      for (int i = 0; i <= n; i++)
      {
         // For last iteration, force stack emptying by treating nums[i] = +∞
         while (!stMax.empty() && (i == n || nums[stMax.top()] < nums[i]))
         {
            int j = stMax.top();
            stMax.pop();                                 // Current element index
            int left = stMax.empty() ? -1 : stMax.top(); // Previous greater element index
            int right = i;                               // Next greater element index
            long long count = (long long)(j - left) * (right - j);
            // Each occurrence contributes value * number of subarrays
            res += (long long)nums[j] * count;
         }
         stMax.push(i);
      }

      // ---------- Contribution as Minimum ----------
      // Each element contributes as minimum in certain subarrays
      // Use monotonic increasing stack to find how far it can extend
      stack<int> stMin;

      for (int i = 0; i <= n; i++)
      {
         // For last iteration, force stack emptying by treating nums[i] = -∞
         while (!stMin.empty() && (i == n || nums[stMin.top()] > nums[i]))
         {
            int j = stMin.top();
            stMin.pop();                                 // Current element index
            int left = stMin.empty() ? -1 : stMin.top(); // Previous smaller element index
            int right = i;                               // Next smaller element index
            long long count = (long long)(j - left) * (right - j);
            // Subtract contribution as minimum
            res -= (long long)nums[j] * count;
         }
         stMin.push(i);
      }

      // Return final total sum of ranges
      return res;
   }
};

int main()
{
   Solution sol;
   vector<int> nums = {3, 1, 2, 4};          // Example input
   cout << sol.subArrayRanges(nums) << endl; // Output = 13
   return 0;
}

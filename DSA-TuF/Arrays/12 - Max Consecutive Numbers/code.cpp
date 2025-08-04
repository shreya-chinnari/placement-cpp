#include <bits/stdc++.h>
using namespace std;

int maxConsecOnes(vector<int> &nums)
{
   int count = 0, maxi = 0;

   for (int i = 0; i < nums.size(); i++)
   {
      if (nums[i] == 1)
      {
         count++;
         maxi = max(maxi, count);
      }

      else
      {
         count = 0; // reset count if we encounter a 0
      }
   }
   return maxi; // return the maximum count of consecutive 1's
}

int main()
{
   vector<int> nums = {1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0};

   int ans = maxConsecOnes(nums);
   cout << "The maximum  consecutive 1's are :  " << ans;
   return 0;
}
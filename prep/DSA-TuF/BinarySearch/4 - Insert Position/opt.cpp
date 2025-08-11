// same as lowerbound
class Solution
{
public:
   int searchInsert(vector<int> &nums, int target)
   {

      auto it = lower_bound(nums.begin(), nums.end(), target);
      int lb = it - nums.begin();
      return lb;

      // int s = 0 ,  e = nums.size()-1 , ans = nums.size();
      // while(s<=e) {
      //     int mid = s+(e-s)/2 ;
      //     if(nums[mid] >= target) {
      //         ans = mid;  // update index
      //         e = mid -1; // look for smaller index
      //     } else {
      //         s = mid  +1;
      //     }
      // }
      // return ans;
   }
};
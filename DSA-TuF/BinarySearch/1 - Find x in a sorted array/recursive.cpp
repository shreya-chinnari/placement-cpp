#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   // Recursive binary search function
   int binarySearch(vector<int> &nums, int low, int high, int target)
   {
      // Base condition: search space exhausted, target not found
      if (low > high)
         return -1;

      // Mid index calculated using safe formula to avoid overflow
      int mid = low + (high - low) / 2;

      // Target found at mid index
      if (nums[mid] == target)
         return mid;

      // If target is greater, search in right sub-array [mid+1, high]
      else if (target > nums[mid])
         return binarySearch(nums, mid + 1, high, target);

      // Else search in left sub-array [low, mid-1]
      else
         return binarySearch(nums, low, mid - 1, target);
   }

   // Wrapper function for convenience (starts recursion)
   int search(vector<int> &nums, int target)
   {
      return binarySearch(nums, 0, nums.size() - 1, target);
   }
};

// Driver code
int main()
{
   Solution solution;

   // Example input: sorted array and a target value
   vector<int> nums = {-1, 0, 3, 5, 9, 12};
   int target = 9;

   // Call the recursive search
   int result = solution.search(nums, target);

   // Output result
   if (result != -1)
   {
      cout << "Target " << target << " found at index: " << result << endl;
   }
   else
   {
      cout << "Target " << target << " not found in the array." << endl;
   }

   return 0;
}

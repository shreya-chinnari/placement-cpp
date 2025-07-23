#include <iostream>
#include <vector>
using namespace std;

// Iterative Binary Search class
class Solution
{
public:
   // Function to perform binary search on sorted array
   int search(vector<int> &nums, int target)
   {
      int start = 0;
      int end = nums.size() - 1;

      // Standard binary search loop runs until search space is valid
      while (start <= end)
      {
         // Use safe formula to calculate midpoint to avoid overflow
         int mid = start + (end - start) / 2;

         // If target is found at mid, return its index
         if (nums[mid] == target)
            return mid;

         // If target is smaller than mid element, discard right half
         else if (nums[mid] > target)
            end = mid - 1;

         // If target is greater than mid element, discard left half
         else
            start = mid + 1;
      }

      // If not found, return -1 as per problem statement
      return -1;
   }
};

// Entry point of the program
int main()
{
   // Create an instance of the Solution class
   Solution solution;

   // Define a sorted input array (ascending order)
   vector<int> nums = {-1, 0, 3, 5, 9, 12};

   // Define target value to search for
   int target = 9;

   // Call the search function
   int result = solution.search(nums, target);

   // Output the result
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

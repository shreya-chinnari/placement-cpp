/*

33. Search in Rotated Sorted Array

There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

// This function finds the pivot (index of the smallest element) in a rotated sorted array.

#include <iostream>
#include <vector>
using namespace std;

int pivot(vector<int> &nums, int size)
{
   int start = 0, end = size - 1;
   // We continue the binary search as long as the search range has more than 1 element. If start == end, we’ve found the pivot.
   while (start < end)
   {
      int mid = start + (end - start) / 2;
      // This checks if the mid element is in the left (larger) part of the rotated array. It means the smallest element (pivot) is to the right.
      if (nums[mid] >= nums[0])
      {
         start = mid + 1;
      }
      // mid is in the right half, possibly at or before the pivot, so we move end = mid.
      else
      {
         end = mid;
      }
      mid = start + (end - start) / 2;
   }
   return start;
}

int binarySearch(vector<int> &nums, int start, int end, int target)
{

   // int start = 0; -------no need to redeclare
   // int end = nums.size()-1; ------------no need to redeclare
   // int mid = start+(end-start)/2; ------wrong scope, move inside loop

   while (start <= end)
   { // As long as search space is valid.
      int mid = start + (end - start) / 2;
      // If we find the target, return index.
      // If target is greater, move to right half.
      // If smaller, move to left half.
      if (nums[mid] == target)
      {
         return mid;
      }
      else if (nums[mid] < target)
      {
         start = mid + 1;
      }
      else if (nums[mid] > target)
      {
         end = mid - 1;
      }
      mid = start + (end - start) / 2;
   }
   return -1; // If the loop exits, the target was not found.
}

class Solution
{
public:
   int search(vector<int> &nums, int target)
   {
      int n = nums.size();
      int pivotIndex = pivot(nums, nums.size());

      // This checks whether the target lies in the right sorted subarray, which starts at the pivot and ends at n-1.
      if (nums[pivotIndex] <= target && target <= nums[n - 1])
      {
         return binarySearch(nums, pivotIndex, n - 1, target);
      }
      else
      { // Otherwise, we search in the left sorted subarray: 0 to pivotIndex - 1.
         return binarySearch(nums, 0, pivotIndex - 1, target);
      }
   }
};

int main()
{
   Solution sol;
   vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
   int target = 0;

   int index = sol.search(nums, target);
   cout << "Index of [target: " << target << "] is: " << index << endl;

   return 0;
}

/*
A rotated sorted array like [4,5,6,7,0,1,2] is actually two sorted subarrays:

Left part: [4,5,6,7]
Right part: [0,1,2]

Once we find the pivot, we decide which side to search.
*/
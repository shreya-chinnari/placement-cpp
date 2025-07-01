/*
✅ What’s Given:

Two sorted integer arrays:

   - nums1 of size m + n, where:
      -- First m elements are valid.
      -- Last n elements are 0s (extra space).
   - nums2 of size n with n valid elements.

✅ What You Have to Do:

   = Merge all elements from nums2 into nums1.
   = Resulting array (in nums1) must be sorted in non-decreasing order.
   = Do not return a new array — modify nums1 in-place. // uses no extra space (in-place)

✅ Important Points:

   > nums1 already has enough space to hold all elements after merge.
   > Only first m values in nums1 are real data; the rest are just placeholders.
   > You can’t use extra space like creating a new array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
   {
      // start from end of nums1 {actual elements} and nums2
      int i = m - 1, j = n - 1;
      int k = m + n - 1; // pointer for end of nums1 (full size)

      while (i >= 0 && j >= 0)
      {
         if (nums1[i] > nums2[j])
         {
            nums1[k--] = nums1[i--];
            // If nums1[i] is greater, it should go later in the final sorted array (which we are building from the back)
            // Place nums1[i] at position k (end of the array)
            // Decrement both k and i to move backward
         }
         else
         {
            nums1[k--] = nums2[j--];
            // If nums2[j] is greater or equal, place it at position k
         }
      }
      while (j >= 0)
      {
         nums1[k--] = nums2[j--];
         // After the main loop ends, nums2 might still have some values left (if all nums1 values were larger).
         // This loop copies any remaining values from nums2 to the front of nums1.
      }
   }
};

/*
Why not a loop for nums1 leftovers?

    No need!
    If any nums1 elements are left (i >= 0), they’re already in the correct position because they started in nums1
    and we merged from the back without overwriting them.
*/

/*
    We merge from the end to avoid overwriting.
    We compare from the back, always placing the largest remaining element at the end of nums1.
    Any remaining nums2 values are copied over.
*/

int main()
{
   Solution sol;

   // Example input:
   vector<int> nums1 = {1, 2, 3, 0, 0, 0};
   int m = 3;
   vector<int> nums2 = {2, 5, 6};
   int n = 3;

   sol.merge(nums1, m, nums2, n);

   cout << "Merged Array: ";
   for (int val : nums1)
   {
      cout << val << " ";
   }
   cout << endl;

   return 0;
}

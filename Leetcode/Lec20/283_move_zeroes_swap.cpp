/*
You are given an integer array nums.
Your goal is to move all zeroes in the array to the end.
The relative order of non-zero elements must be maintained.
You must perform this in-place — no extra array or copying allowed.
After the operation, all non-zero elements come first (in original order), followed by all zeroes.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   void moveZeroes(vector<int> &nums)
   {
      int i = 0; // Points to the position to place the next non-zero element
      for (int j = 0; j < nums.size(); j++)
      {
         if (nums[j] != 0)
         {
            swap(nums[i], nums[j]);
            i++; // Move to the next insertion point
         }
      }
   }
};

int main()
{
   Solution sol;
   vector<int> nums = {0, 1, 0, 3, 12};

   cout << "Before moving zeroes (swap method): ";
   for (int n : nums)
      cout << n << " ";
   cout << endl;

   sol.moveZeroes(nums); // Function call

   cout << "After moving zeroes: ";
   for (int n : nums)
      cout << n << " ";
   cout << endl;

   return 0;
}

// Before moving zeroes(swap method) : 0 1 0 3 12
// After moving zeroes : 1 3 12 0 0
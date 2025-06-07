// OVERWRITE + FILL ZEROES METHOD

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   void moveZeroes(vector<int> &nums)
   {
      int insertPosition = 0;
      // First pass: move all non-zero elements to the front -- OVERWRITE
      for (int x : nums)
      {
         if (x != 0)
         {
            nums[insertPosition++] = x;
            // Place non-zero at insertPosition and increment insertPosition
         }
      }

      // Second pass: fill the rest with zeros -- FILL ZEROES
      while (insertPosition < nums.size())
      {
         nums[insertPosition++] = 0;
      }
   }
};

int main()
{
   Solution sol; // Create an instance of the Solution class

   vector<int> nums = {0, 1, 0, 3, 12};

   cout << "Before moving zeroes (overwrite method): ";
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

// Before moving zeroes (overwrite method): 0 1 0 3 12
// After moving zeroes : 1 3 12 0 0
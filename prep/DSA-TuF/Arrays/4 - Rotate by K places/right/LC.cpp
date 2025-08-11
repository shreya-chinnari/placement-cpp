#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateRight(vector<int> &nums, int k)
{
   int n = nums.size();
   k = k % n;

   // Step 1: Reverse first n-k
   reverse(nums.begin(), nums.begin() + (n - k));

   // Step 2: Reverse last k
   reverse(nums.begin() + (n - k), nums.end());

   // Step 3: Reverse entire array
   reverse(nums.begin(), nums.end());
}

int main()
{
   vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
   int k = 3;
   rotateRight(nums, k);

   cout << "Array after right rotation by " << k << " places: ";
   for (int x : nums)
      cout << x << " ";

   return 0;
}

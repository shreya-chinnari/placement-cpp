// ❓ You are given an array of n cards laid in a row, each with some points. You can pick exactly k cards from either the start or end of the array. What is the maximum total points you can obtain?
// Can't pick from middle

#include <iostream>
using namespace std;

int brute(int arr[], int n, int k)
{
   int lsum = 0, rsum = 0;
   int maxSum = 0;

   // 1. find sum of first 4 elements
   for (int i = 0; i < k; i++)
   {
      lsum = lsum + arr[i];
      maxSum = lsum;
   }

   // 2. shrink the window and expand from end
   int rightIndex = k - 1;
   for (int i = k - 1; i >= 0; i--)
   {
      lsum = lsum - arr[i];
      rsum = rsum + arr[rightIndex];
      rightIndex--;

      maxSum = max(maxSum, lsum + rsum);
   }
   return maxSum;
}

// TC : O(k+k)
// SC : O(1)

int main()
{

   return 0;
}
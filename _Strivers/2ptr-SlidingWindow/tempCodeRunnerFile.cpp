/*
You are given an array fruits[] where each element represents a type of fruit.

You have 2 baskets, and each basket can only hold 1 type of fruit, but you can pick as many fruits of that type as you want.

You must pick fruits in a row (contiguous subarray) starting from any tree and keep picking until you can't pick anymore (i.e., when you encounter a 3rd fruit type).

Find the length of the longest subarray with at most 2 types of fruits.
*/

// TC : O(n^2)
// SC : O(3)

#include <iostream>
#include <unordered_map>
using namespace std;

int totalFruit(int arr[], int n, int k)
{
   unordered_map<int, int> totalFruit; // Stores count of each fruit type in the window

   int l = 0, r = 0, maxLen = 0;

   while (r < n)
   {
      totalFruit[arr[r]]++; // Add current fruit to the basket (window) (increment frequency/count of that type)

      // if we have more than "k" fruit-types, shrink window from left
      while (totalFruit.size() > k)
      {
         totalFruit[arr[l]]--; // Erase type if count becomes 0

         // if no more fruits of this type, remove it from map
         if (totalFruit[arr[l]] == 0)
         {
            totalFruit.erase(arr[l]);
         }
         l++; // keep shrinking the window from the left
      }
   }

   // Update max length of window (valid subarray)
   if (totalFruit.size() <= k)
   {
      maxLen = max(maxLen, r - l + 1);
      r++; // keep expanding the window to the right
   }

   return maxLen;
}

int main()
{
   int arr[] = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 2;

   cout << "max number of fruits  :  " << totalFruit(arr, n, 2);

   return 0;
}
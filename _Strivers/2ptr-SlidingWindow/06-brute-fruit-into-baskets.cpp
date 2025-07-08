/*
You are given an array fruits[] where each element represents a type of fruit.

You have 2 baskets, and each basket can only hold 1 type of fruit, but you can pick as many fruits of that type as you want.

You must pick fruits in a row (contiguous subarray) starting from any tree and keep picking until you can't pick anymore (i.e., when you encounter a 3rd fruit type).

Find the length of the longest subarray with at most 2 types of fruits.
*/

// TC : O(n^2)
// SC : O(3)

#include <iostream>
#include <set>
using namespace std;

int totalFruit(int arr[], int n, int k)
{
   int maxLen = 0;

   for (int i = 0; i < n; i++)
   {
      set<int> types; // reset at each iteration

      for (int j = i; j < n; j++)
      {
         types.insert(arr[j]);

         if (types.size() <= k)
         {
            maxLen = max(maxLen, j - i + 1);
         }
         else
         {
            break; // more than "k" fruit types, STOP!
         }
      }
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
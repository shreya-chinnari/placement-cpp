// TC : O(2n) --> O(n)
// SC : O(3)
#include <iostream>
#include <unordered_map>
using namespace std;

int totalFruit(int arr[], int n, int k)
{
   unordered_map<int, int> totalFruit;
   int l = 0, r = 0, maxLen = 0;

   while (r < n)
   {
      totalFruit[arr[r]]++;

      // ORIGINAL
      // while (totalFruit.size() > k) // shrink window till valid

      // MORE OPTIMISED VERSION
      if (totalFruit.size() > k) // shrink only once even if still invalid

      {
         totalFruit[arr[l]]--;

         if (totalFruit[arr[l]] == 0)
         {
            totalFruit.erase(arr[l]);
         }

         l++;
      }

      if (totalFruit.size() <= k)
      {
         maxLen = max(maxLen, r - l + 1);
         r++;
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

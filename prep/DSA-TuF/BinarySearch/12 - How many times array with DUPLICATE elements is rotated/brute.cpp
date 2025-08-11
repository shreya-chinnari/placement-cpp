// same as unique

#include <bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &arr)
{
   int n = arr.size();
   int minIndex = 0;

   for (int i = 1; i < n; i++)
   {
      if (arr[i] < arr[minIndex])
      {
         minIndex = i;
      }
   }

   return minIndex;
}

int main()
{
   vector<int> arr = {3, 3, 3, 4, 5, 6, 7, 1, 2, 3}; // Rotated at index 7
   int ans = findKRotation(arr);
   cout << "The array is rotated " << ans << " times.\n";
   return 0;
}

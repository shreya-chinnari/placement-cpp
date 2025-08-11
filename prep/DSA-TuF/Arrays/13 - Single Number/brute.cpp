// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr)
{
   int n = arr.size();

   for (int i = 0; i < n; i++)
   {

      int single = arr[i];
      int count = 0;

      // Count occurrences of 'single' in the array
      for (int j = 0; j < n; j++)
      {
         if (arr[j] == single)
         {
            count++;
         }
      }

      // If 'single' occurs only once, return it
      if (count == 1)
      {
         return single; // return the single element
      }
   }
   return -1; // if no single element is found, return -1
}

int main()
{
   vector<int> arr = {4, 1, 2, 1, 2};
   int ans = getSingleElement(arr);
   cout << "The single element is: " << ans << endl;
   return 0;
}


#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
   int n = arr.size(); // size of the array.

   // If the array has only one element, return it.
   if (n == 1)
      return arr[0];

   for (int i = 0; i < n; i++)
   {

      // Check for first index:
      if (i == 0)
      {
         if (arr[i] != arr[i + 1])
            return arr[i];
      }
      // Check for last index:
      else if (i == n - 1)
      {
         if (arr[i] != arr[i - 1])
            return arr[i];
      }
      // Check for middle indices:
      else
      {
         if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
            return arr[i];
      }
   }

   // dummy return statement:
   return -1;
}

int main()
{
   vector<int> arr1 = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
   int ans1 = singleNonDuplicate(arr1);
   cout << "The single element is: " << ans1 << "\n";
   vector<int> arr2 = {1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
   int ans2 = singleNonDuplicate(arr2);
   cout << "The single element is: " << ans2 << "\n";
   vector<int> arr3 = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6};
   int ans3 = singleNonDuplicate(arr3);
   cout << "The single element is: " << ans3 << "\n";
   return 0;
}

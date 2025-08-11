
#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &arr)
{
   int n = arr.size();

   // edge cases :

   // 1. single element
   if (n == 1)
      return arr[0];
   // 2. first element is unique
   if (arr[0] != arr[1])
      return arr[0];
   // 3. last element is unique
   if (arr[n - 1] != arr[n - 2])
      return arr[n - 1];

   // logic :

   int s = 0, e = n - 1;
   while (s <= e)
   {

      int mid = s + (e - s) / 2;

      // element found :
      if ((arr[mid] != arr[mid - 1]) && (arr[mid] != arr[mid + 1]))
         return arr[mid];

      // 4. we are on LHS, element is on RHS, matchig pair : {even, odd}
      if (mid % 2 == 0 && arr[mid] == arr[mid + 1] || mid % 2 == 1 && arr[mid] == arr[mid - 1])
      {
         s = mid + 1; // move to the right side
      }
      // 5. we are on RHS, element is on LHS, matchig pair : {odd, even}
      else
      {
         e = mid - 1; // move to the left side
      }
   }
   return -1; // dummy return statement, should never reach here
}

int main()
{
   vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
   int ans = singleNonDuplicate(arr);
   cout << "The single element is: " << ans << "\n";
   return 0;
}

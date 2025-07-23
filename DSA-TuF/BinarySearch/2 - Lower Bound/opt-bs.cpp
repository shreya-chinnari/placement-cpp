#include <iostream>
using namespace std;

int lowerBoundBS(int arr[], int n, int x)
{
   int s = 0, e = n - 1, ans = n;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      // mid can be the answer
      if (arr[mid] >= x)
      {
         ans = mid;
         e = mid - 1; // search for smaller value
      }
      // can not be the answer
      else
      {
         s = mid + 1; // search in right half
      }
   }
   return ans;
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 3;
   int result = lowerBoundBS(arr, n, x);
   if (result != n)
   {
      cout << "Lower bound of " << x << " is at index: " << result << endl;
   }
   else
   {
      cout << "No element found greater than or equal to " << x << endl;
   }
   return 0;
}
#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

// Optimized one-pass solution for finding second largest and second smallest elements
// Time complexity is O(n) because we traverse the array only once

int secondLargest(int arr[], int n)
{

   if (n == 0 || n == 1)
      cout << -1 << " " << -1 << endl; // edge case when only one element is present in array

   int l = INT_MIN;
   int sl = INT_MIN;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > l)
      {
         sl = l;
         l = arr[i];
      }
      else if (arr[i] > sl && arr[i] != l)
      {
         sl = arr[i];
      }
   }

   return (sl == INT_MIN) ? -1 : sl;
}

int secondSmallest(int arr[], int n)
{
   if (n == 0 || n == 1)
      cout << -1 << " " << -1 << endl; // edge case when only one element is present in array

   int s = INT_MAX;
   int ss = INT_MAX;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] < s)
      {
         ss = s;
         s = arr[i];
      }
      else if (arr[i] < ss && arr[i] != s)
      {
         ss = arr[i];
      }
   }

   return (ss == INT_MAX) ? -1 : ss;
}

int main()
{
   int arr[] = {1, 1, 7, 2, 4, 6, 7, 5, 5};
   int n = sizeof(arr) / sizeof(arr[0]);

   int sl = secondLargest(arr, n);
   cout << "The second largest element is: " << sl << endl;

   int ss = secondSmallest(arr, n);
   cout << "The second smallest element is: " << ss << endl;

   return 0;
}

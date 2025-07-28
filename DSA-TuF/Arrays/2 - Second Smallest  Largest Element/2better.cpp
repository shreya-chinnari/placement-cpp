#include <iostream>
#include <algorithm>
#include <climits> // For INT_MAX
using namespace std;

// no sorting

// time complexity is O(n+n) = O(2n) because we are traversing the array twice {2 passes}
// space complexity is O(1) because we are using only a constant amount of extra space

int secondLargest(int arr[], int n)
{
   // l = largest
   // sl = second largest

   int l = INT_MIN;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > l)
      {
         l = arr[i];
      }
   }
   int sl = INT_MIN;

   for (int i = 0; i < n; i++)
   {
      if (arr[i] > sl && arr[i] != l)
      {
         sl = arr[i];
      }
   }

   return sl;
}

int secondSmallest(int arr[], int n)
{
   // s = smallest
   // ss = second smallest

   int s = INT_MAX;
   for (int i = 1; i < n; i++)
   {
      if (arr[i] < s)
      {
         s = arr[i];
      }
   }
   int ss = INT_MAX; // Initialize to -1 to handle case with no second largest
   for (int i = 0; i < n; i++)
   {
      if (arr[i] < ss && arr[i] != s)
      {
         ss = arr[i];
      }
   }
   return ss;
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
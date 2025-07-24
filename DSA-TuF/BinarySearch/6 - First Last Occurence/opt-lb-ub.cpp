#include <iostream>
using namespace std;

int lowerBound(int arr[], int n, int x)
{
   int s = 0, e = n - 1;
   int ans = n; // Default to n, meaning no lower bound found

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] >= x)
      {
         ans = mid;   // mid can be the answer
         e = mid - 1; // search for smaller value
      }
      else
      {
         s = mid + 1; // search in right half
      }
   }
   return ans;
}

int upperBound(int arr[], int n, int x)
{
   int s = 0, e = n - 1;
   int ans = n;

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] > x)
      {
         ans = mid;
         e = mid - 1; // search for smaller value
      }
      else
      {
         s = mid + 1; // search in right half
      }
   }
   return ans; // returns index of first element > x, or n if not found
}

pair<int, int> firstAndLastOccureence(int arr[], int n, int x)
{
   int lb = lowerBound(arr, n, x);
   int ub = upperBound(arr, n, x);

   // EDGE CASE ***
   // If lower bound is out of bounds or element at lower bound is not x,
   // it means x is not present in the array
   if (lb == n || arr[lb] != x)
   {
      return {-1, -1};
   }

   return {lb, ub - 1}; // Return pair of first and last occurrence indices
}

int main()
{
   int arr[] = {1, 2, 2, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 2;

   pair<int, int> result = firstAndLastOccureence(arr, n, x);
   if (result.first != -1)
      cout << "First Occurrence: " << result.first << ", Last Occurrence: " << result.second << endl;
   else
      cout << "Element not found in array." << endl;

   return 0;
}
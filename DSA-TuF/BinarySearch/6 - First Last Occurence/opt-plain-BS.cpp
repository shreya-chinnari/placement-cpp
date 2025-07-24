#include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int x)
{
   int s = 0;
   int e = n - 1;
   int ans = n; // Default to n, meaning no first occurrence found

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] == x)
      {
         ans = mid;   // mid can be the answer
         e = mid - 1; // search for smaller index
      }
      else if (arr[mid] < x)
      {
         s = mid + 1; // search in right half
      }
      else
      {
         e = mid - 1; // search in left half
      }
   }
   return ans; // returns index of first occurrence, or n if not found
}

int lastOccurrence(int arr[], int n, int x)
{
   int s = 0;
   int e = n - 1;
   int ans = n; // Default to n, meaning no first occurrence found

   while (s <= e)
   {
      int mid = s + (e - s) / 2;

      if (arr[mid] == x)
      {
         ans = mid;   // mid can be the answer
         s = mid + 1; // search for larger index
      }
      else if (arr[mid] < x)
      {
         s = mid + 1; // search in right half
      }
      else
      {
         e = mid - 1; // search in left half
      }
   }
   return ans; // returns index of first occurrence, or n if not found
}

pair<int, int> firstAndLastOccurrence(int arr[], int n, int x)
{
   int first = firstOccurrence(arr, n, x);

   if (first == -1)
      return {-1, -1}; // If first occurrence not found, return {-1, -1}

   int last = lastOccurrence(arr, n, x);
   return {first, last};
}

int main()
{

   int arr[] = {1, 2, 2, 2, 3, 4, 5};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 2;

   pair<int, int> result = firstAndLastOccurrence(arr, n, x);
   cout << "First Occurrence: " << result.first
        << ", Last Occurrence: " << result.second << endl;

   return 0;
}
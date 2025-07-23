// without using ans variable for storing index

#include <iostream>
using namespace std;

// Find floor index (largest element ≤ x)
int floor(int arr[], int n, int x)
{
   int low = 0, high = n - 1;

   while (low <= high)
   {
      int mid = low + (high - low) / 2;

      if (arr[mid] <= x)
      {
         low = mid + 1; // Go right to find higher floor
      }
      else
      {
         high = mid - 1; // Go left
      }
   }

   // After the loop, high is at the index of the floor
   // If high < 0, floor doesn't exist
   return (high >= 0) ? high : -1;
}

// Find ceil index (smallest element ≥ x)
int ceil(int arr[], int n, int x)
{
   int low = 0, high = n - 1;

   while (low <= high)
   {
      int mid = low + (high - low) / 2;

      if (arr[mid] >= x)
      {
         high = mid - 1; // Go left to find smaller ceil
      }
      else
      {
         low = mid + 1; // Go right
      }
   }

   // After the loop, low is at the index of the ceil
   // If low >= n, ceil doesn't exist
   return (low < n) ? low : -1;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x)
{
   int fIdx = floor(arr, n, x);
   int cIdx = ceil(arr, n, x);

   // Convert indices to actual values (or return -1 if not found)
   int floorVal = (fIdx != -1) ? arr[fIdx] : -1;
   int ceilVal = (cIdx != -1) ? arr[cIdx] : -1;

   return make_pair(floorVal, ceilVal);
}

int main()
{
   int arr[] = {3, 4, 4, 7, 8, 10};
   int n = sizeof(arr) / sizeof(arr[0]);
   int x = 5;

   pair<int, int> result = getFloorAndCeil(arr, n, x);
   cout << "The floor and ceil are: " << result.first
        << " " << result.second << endl;

   return 0;
}

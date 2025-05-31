#include <iostream>
using namespace std;

int pivot(int arr[], int size)
{
   int start = 0, end = size - 1, mid = start + (end - start) / 2;

   while (start < end)
   {
      if (arr[mid] >= arr[0])
      {
         start = mid + 1; // pivot is in the right half
      }
      else
      {
         end = mid; // pivot is in the left half
      }

      mid = start + (end - start) / 2;
   }
   return start; // or end, both will be the same
}

int main()
{
   int arr[] = {4, 5, 6, 7, 0, 1, 2};
   int size = sizeof(arr) / sizeof(arr[0]);
   int pivotIndex = pivot(arr, size);
   cout << "Pivot index is: " << pivotIndex << endl;
   return 0;
}

/*
if (arr[mid] > arr[end])
    start = mid + 1;
else
    end = mid;

   🔁 Logic:
   This checks if arr[mid] is greater than the last element (arr[end]).
   If it is, then we are in the left (greater) part, so the pivot must be to the right → start = mid + 1.
   Otherwise, the pivot is to the left or at mid → end = mid.

==============================================================================================================

if (arr[mid] >= arr[0])
    start = mid + 1;
else
    end = mid;

    🔁 Logic:
   This checks if arr[mid] is greater than or equal to the first element (arr[0]).
   If so, we're in the left sorted part → pivot is to the right → start = mid + 1.
   Else, we’re in the right (rotated) part → pivot is to the left → end = mid.
*/
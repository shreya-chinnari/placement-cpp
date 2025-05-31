// pivot of a rotated sorted array

/*
If the array is not rotated at all, then:
The first element is the smallest, and
The array is fully sorted like [0, 1, 2, 3, 4]
   So, if the first element is less than or equal to the last, there's no rotation.

In rotated sorted arrays, the pivot is the point where the array is rotated.
The smallest element (0) is now in the middle — that’s called the pivot.
We want to find the index of the smallest element, which is also the pivot point of rotation.


*/

#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr)
{
   int start = 0;
   int end = arr.size() - 1;

   // If the array is not rotated at all
   if (arr[start] <= arr[end])
   {
      return 0;
   }

   while (start < end)
   {
      int mid = start + (end - start) / 2;

      // If mid element is greater than the end, pivot is to the right
      if (arr[mid] > arr[end])
      {
         start = mid + 1;
      }
      // Otherwise, pivot is to the left (or at mid)
      else
      {
         end = mid;
      }
   }

   // start == end is the pivot index
   return start;
}

int main()
{
   vector<int> arr = {4, 5, 6, 7, 0, 1, 2};

   int pivotIndex = findPivot(arr);
   cout << "Pivot index is: " << pivotIndex << endl;
   cout << "Pivot element is: " << arr[pivotIndex] << endl;

   return 0;
}

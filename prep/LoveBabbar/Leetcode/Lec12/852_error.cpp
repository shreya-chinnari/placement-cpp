#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   int peakIndexInMountainArray(vector<int> &arr)
   {
      int start = 0;
      int end = arr.size() - 1;
      int mid = start + (end - start) / 2;

      while (start <= end)
      {
         if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
         {
            return mid;
         }
         else if (arr[mid] < arr[mid + 1])
         {
            start = mid + 1;
         }
         else
         {
            end = mid;
         }
         mid = start + (end - start) / 2;
      }
      return start;
   }
};

int main()
{
   Solution sol;

   vector<int> arr = {0, 2, 4, 7, 9, 6, 3, 1};

   int peakIndex = sol.peakIndexInMountainArray(arr);

   cout << "Peak index is: " << peakIndex << endl;
   cout << "Peak element is: " << arr[peakIndex] << endl;

   return 0;
}

// problems ====================

/*
1. Out-of-Bounds Access

   if(arr[mid -1] < arr[mid] && arr[mid] > arr[mid+1])

      When mid == 0, arr[mid - 1] accesses an invalid index (out of bounds).
      When mid == arr.size() - 1, arr[mid + 1] also goes out of bounds.

   This can lead to undefined behavior or segmentation faults.

2. Incorrect Peak Condition

You're not searching for an exact value. You're narrowing toward a peak, and you want start == end as the stopping condition.
The condition start <= end can lead to an infinite loop if the peak is not found correctly.
If the array is not a valid mountain array, the loop may never terminate.

   use : while (start < end)

3. Incorrect Mid Calculation

You calculate mid before the loop, but it must be calculated inside the loop after each update to start or end.
   int mid = start + (end - start) / 2;

*/
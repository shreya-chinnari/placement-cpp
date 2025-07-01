/*
Peak Index in a Mountain Array

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.
Your task is to solve it in O(log(n)) time complexity.

   Example 1:
      Input: arr = [0,1,0]
      Output: 1 // index of 1

   Example 2:
      Input: arr = [0,2,1,0]
      Output: 1 // index of 2
*/

#include <iostream>
using namespace std;

int findPeak(int arr[], int size)
{
   for (int i = 1; i < size - 1; i++)
   {
      if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) // because there will be only 1 peak in a mountain array
      {
         return i; // found peak
      }
   }
   return -1; // no peak found (shouldn't happen in valid mountain array)
}

int main()
{
   int arr[] = {1, 3, 5, 7, 6, 4, 2};
   int size = sizeof(arr) / sizeof(arr[0]);

   int peakIndex = findPeak(arr, size);

   if (peakIndex != -1)
   {
      cout << "Peak found at index: " << peakIndex << " with value: " << arr[peakIndex] << endl;
   }
   else
   {
      cout << "No peak found." << endl;
   }

   return 0;
}

// time complexity: O(n) for linear search
// space complexity: O(1) as we are using a constant amount of space
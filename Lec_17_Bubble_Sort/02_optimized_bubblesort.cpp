#include <iostream>
using namespace std;

int bubbleSort(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      bool swapped = false; // Track if a swap occurred

      for (int j = 0; j < n - i; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            swap(arr[j], arr[j + 1]);
         }
         swapped = true; // A swap occurred
      }

      // If no swaps occurred, the array is already sorted
      if (!swapped) // if(swapped == false)
      {
         break; // Exit early if the array is sorted
      }
   }
   return 0;
}

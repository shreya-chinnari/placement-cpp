#include <iostream>
using namespace std;

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
}

void recursiveSelectionSort(int arr[], int start, int n)
{
   if (start >= n - 1)
      return;

   int minIndex = start;
   cout << "\nFinding minimum from index " << start << " to " << n - 1 << ":\n";

   for (int i = start + 1; i < n; i++)
   {
      cout << "  Comparing arr[" << i << "] = " << arr[i]
           << " with arr[" << minIndex << "] = " << arr[minIndex];

      if (arr[i] < arr[minIndex])
      {
         minIndex = i;
         cout << "  --> New minIndex = " << minIndex;
      }
      cout << endl;
   }

   cout << "Swapping arr[" << start << "] = " << arr[start]
        << " with arr[" << minIndex << "] = " << arr[minIndex] << endl;

   swap(arr[start], arr[minIndex]);

   cout << "Array after step " << start + 1 << ": ";
   printArray(arr, n);

   recursiveSelectionSort(arr, start + 1, n);
}

int main()
{
   int arr[] = {25, 64, 12, 22, 11};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Original array: ";
   printArray(arr, n);
   cout << endl;

   recursiveSelectionSort(arr, 0, n);

   cout << "\nSorted array: ";
   printArray(arr, n);
   return 0;
}

/*
Original array: 25 64 12 22 11


Finding minimum from index 0 to 4:
  Comparing arr[1] = 64 with arr[0] = 25
  Comparing arr[2] = 12 with arr[0] = 25  --> New minIndex = 2
  Comparing arr[3] = 22 with arr[2] = 12
  Comparing arr[4] = 11 with arr[2] = 12  --> New minIndex = 4
Swapping arr[0] = 25 with arr[4] = 11
Array after step 1: 11 64 12 22 25

Finding minimum from index 1 to 4:
  Comparing arr[2] = 12 with arr[1] = 64  --> New minIndex = 2
  Comparing arr[3] = 22 with arr[2] = 12
  Comparing arr[4] = 25 with arr[2] = 12
Swapping arr[1] = 64 with arr[2] = 12
Array after step 2: 11 12 64 22 25

Finding minimum from index 2 to 4:
  Comparing arr[3] = 22 with arr[2] = 64  --> New minIndex = 3
  Comparing arr[4] = 25 with arr[3] = 22
Swapping arr[2] = 64 with arr[3] = 22
Array after step 3: 11 12 22 64 25

Finding minimum from index 3 to 4:
  Comparing arr[4] = 25 with arr[3] = 64  --> New minIndex = 4
Swapping arr[3] = 64 with arr[4] = 25
Array after step 4: 11 12 22 25 64

Sorted array: 11 12 22 25 64
*/
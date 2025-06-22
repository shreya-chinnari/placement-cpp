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

   // Base case: if start index is at the last element or beyond, return
   // This means the array is already sorted
   if (start >= n - 1)
      return;

   // Find index of the minimum element in the unsorted part
   int minIndex = start;
   for (int i = start + 1; i < n; i++)
   {
      if (arr[i] < arr[minIndex])
         minIndex = i; // Update minIndex if a smaller element is found
   }

   // Swap the minimum element with the first unsorted element
   swap(arr[start], arr[minIndex]);

   // Recursive call for the rest of the array
   recursiveSelectionSort(arr, start + 1, n);
}

int main()
{
   int arr[] = {64, 25, 12, 22, 11};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Original array: ";
   printArray(arr, n);

   recursiveSelectionSort(arr, 0, n);

   cout << "Sorted array: ";
   printArray(arr, n);
   return 0;
}

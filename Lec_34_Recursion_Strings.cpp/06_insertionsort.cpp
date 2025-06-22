#include <iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int n)
{
   // Base case: one element is already sorted
   if (n <= 1)
      return;

   // Sort the first n-1 elements
   recursiveInsertionSort(arr, n - 1);

   // Insert the last element at its correct position
   int last = arr[n - 1]; // the n-th element, the element to insert (like a key in insertion sort)
   int j = n - 2;         // start comparing from the (n-2)-th element

   while (j >= 0 && arr[j] > last)
   {
      arr[j + 1] = arr[j]; // shift the larger element right
      j--;                 // move left
   }
   // Place the last element at its correct position
   // After the while loop, j is at the position where last should be inserted
   arr[j + 1] = last;
}

void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
}

int main()
{
   int arr[] = {12, 11, 13, 5, 6};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "Original array: ";
   printArray(arr, n);

   recursiveInsertionSort(arr, n);

   cout << "Sorted array: ";
   printArray(arr, n);
   return 0;
}

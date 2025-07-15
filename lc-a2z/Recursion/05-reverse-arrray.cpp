#include <iostream>
using namespace std;

// Two pointers method
void reverseArrayTwoPointers(int arr[], int size)
{
   int start = 0;
   int end = size - 1;

   while (start < end)
   {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
      start++;
      end--;
   }
}

// Recursion with two indices
void reverseArrayRecursive(int arr[], int start, int end)
{
   if (start >= end)
      return;

   int temp = arr[start];
   arr[start] = arr[end];
   arr[end] = temp;

   reverseArrayRecursive(arr, start + 1, end - 1);
}

// Recursion with single index
void reverseArrayRecursiveSingleIndex(int arr[], int i, int size)
{
   if (i >= size / 2)
      return;

   int temp = arr[i];
   arr[i] = arr[size - i - 1];
   arr[size - i - 1] = temp;

   reverseArrayRecursiveSingleIndex(arr, i + 1, size);
}

// Print utility
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; ++i)
      cout << arr[i] << " ";
   cout << endl;
}

int main()
{
   int arr1[] = {1, 2, 3, 4, 5};
   int arr2[] = {1, 2, 3, 4, 5};
   int arr3[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr1) / sizeof(arr1[0]);

   reverseArrayTwoPointers(arr1, size);
   cout << "Reversed array (two pointers): ";
   printArray(arr1, size);

   reverseArrayRecursive(arr2, 0, size - 1);
   cout << "Reversed array (recursive): ";
   printArray(arr2, size);

   reverseArrayRecursiveSingleIndex(arr3, 0, size);
   cout << "Reversed array (recursive, single index): ";
   printArray(arr3, size);

   return 0;
}
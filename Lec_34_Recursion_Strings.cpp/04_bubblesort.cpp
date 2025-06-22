#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
   // Base case: if size is 1, the array is already sorted
   if (size == 1 || size == 0)
      return;

   // One pass of bubble sort - puts largest element at the end

   for (int i = 0; i < size - 1; i++)
   {
      // Compare adjacent elements
      if (arr[i] > arr[i + 1])
      {
         // Swap if elements are in wrong order
         swap(arr[i], arr[i + 1]);
      }
   }

   // Recursive call for the remaining array
   BubbleSort(arr, size - 1);
}

int main()
{
   int arr[] = {3, 8, 1, 5, 9};
   int size = sizeof(arr) / sizeof(arr[0]);

   // Bubble Sort
   BubbleSort(arr, size);
   cout << "Sorted array: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
   return 0;
}
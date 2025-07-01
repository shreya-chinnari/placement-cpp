#include <iostream>
using namespace std;

// Function to perform selection sort using while loop
void selectionSortWhileLoop(int arr[], int n)
{
   int i = 0;

   // Outer loop to iterate over the array
   while (i < n - 1)
   {
      int minIndex = i; // Assume current index is minimum
      int j = i + 1;

      // Inner loop to find the minimum in the unsorted part
      while (j < n)
      {
         if (arr[j] < arr[minIndex])
            minIndex = j; // Update min index if smaller value found
         j++;
      }

      // Swap the smallest element with the current element
      swap(arr[i], arr[minIndex]);
      i++; // Move to the next position
   }
}

// Function to print elements of the array
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
}

int main()
{
   int arr[] = {64, 25, 12, 22, 11};     // Sample array
   int n = sizeof(arr) / sizeof(arr[0]); // Calculate number of elements

   selectionSortWhileLoop(arr, n); // Sort using while loop version
   cout << "Sorted array using while loop: ";
   printArray(arr, n); // Output the sorted array

   return 0;
}

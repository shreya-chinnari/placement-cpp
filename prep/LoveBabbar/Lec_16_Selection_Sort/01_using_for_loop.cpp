#include <iostream>
using namespace std;

// Function to perform selection sort using for loop
void selectionSortForLoop(int arr[], int n)
{
   // Loop through each element in the array except the last one
   for (int i = 0; i < n - 1; i++)
   {
      // Assume the current index has the minimum value
      int minIndex = i;

      // Find the actual minimum value in the remaining unsorted array
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[minIndex])
            minIndex = j; // Update index of the new minimum
      }

      // Swap the found minimum element with the element at index i
      swap(arr[i], arr[minIndex]);
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

   selectionSortForLoop(arr, n); // Sort using for loop version
   cout << "Sorted array using for loop: ";
   printArray(arr, n); // Output the sorted array

   return 0;
}

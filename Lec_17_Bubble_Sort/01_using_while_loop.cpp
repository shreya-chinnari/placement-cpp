#include <iostream>
using namespace std;

// Function to perform bubble sort using while loops
void bubbleSortWhileLoop(int arr[], int n)
{
   int i = 0;

   // Outer while loop for passes
   while (i < n - 1)
   {
      int j = 0;

      // Inner while loop for comparisons and swaps
      while (j < n - i - 1)
      {
         if (arr[j] > arr[j + 1])
         {
            // Swap elements if they are in the wrong order
            swap(arr[j], arr[j + 1]);
         }
         j++; // Move to the next pair
      }
      i++; // Move to the next pass
   }
}

// Function to print the array
void printArray(int arr[], int n)
{
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";
   cout << endl;
}

int main()
{
   int arr[] = {64, 34, 25, 12, 22, 11, 90}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]);     // Calculate number of elements

   bubbleSortWhileLoop(arr, n); // Call the sorting function
   cout << "Sorted array using while loop: ";
   printArray(arr, n); // Print sorted array

   return 0;
}

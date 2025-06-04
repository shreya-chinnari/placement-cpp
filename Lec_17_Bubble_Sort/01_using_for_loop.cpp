#include <iostream>
using namespace std;

// Function to perform bubble sort using for loops
void bubbleSortForLoop(int arr[], int n)
{
   // Outer loop for number of passes
   for (int i = 0; i < n - 1; i++)
   {
      // Inner loop for pairwise comparisons
      for (int j = 0; j < n - i - 1; j++)
      {
         // If current element is greater than the next one, swap them
         if (arr[j] > arr[j + 1])
         {
            swap(arr[j], arr[j + 1]);
         }
      }
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

   bubbleSortForLoop(arr, n); // Call the sorting function
   cout << "Sorted array using for loop: ";
   printArray(arr, n); // Print sorted array

   return 0;
}

#include <iostream>
using namespace std;

// Function to perform insertion sort using for loops
void insertionSortForLoop(int arr[], int n)
{
   // Loop over elements starting from index 1 (first element is considered sorted)
   for (int i = 1; i < n; i++)
   {
      int key = arr[i]; // Current element to insert into sorted part
      int j = i - 1;

      // Move elements greater than key to one position ahead
      // of their current position to make space for the key
      while (j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j]; // Shift element to the right
         j--;
      }

      arr[j + 1] = key; // Place key at its correct position
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
   int arr[] = {12, 11, 13, 5, 6}; // Sample array
   int n = sizeof(arr) / sizeof(arr[0]);

   insertionSortForLoop(arr, n); // Sort the array
   cout << "Sorted array using for loop: ";
   printArray(arr, n);

   return 0;
}

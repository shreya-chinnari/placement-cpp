#include <iostream>
using namespace std;

// Function to perform insertion sort using while loops
void insertionSortWhileLoop(int arr[], int n)
{
   int i = 1;
   // Start from second element since the first is already "sorted"

   while (i < n)
   {
      int key = arr[i]; // Element to be inserted into sorted part
      int j = i - 1;

      // Shift elements to the right to create space for the key
      while (j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j]; // Shift larger element one position ahead
         j--;
      }

      arr[j + 1] = key; // Insert the key into its correct location
      i++;              // Move to the next element
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

   insertionSortWhileLoop(arr, n); // Sort the array
   cout << "Sorted array using while loop: ";
   printArray(arr, n);

   return 0;
}

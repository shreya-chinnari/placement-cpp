/*

Original array: 12 11 13 5 6

// we assume 12 is sorted

Inserting element 11 into sorted subarray: 12
  arr[0] = 12 > 11 --> shift arr[0] to arr[1]
  Current array: 12 12
Placed 11 at position 0: 11 12

Inserting element 13 into sorted subarray: 11 12
Placed 13 at position 2: 11 12 13

Inserting element 5 into sorted subarray: 11 12 13
  arr[2] = 13 > 5 --> shift arr[2] to arr[3]
  Current array: 11 12 13 13
  arr[1] = 12 > 5 --> shift arr[1] to arr[2]
  Current array: 11 12 12 13
  arr[0] = 11 > 5 --> shift arr[0] to arr[1]
  Current array: 11 11 12 13
Placed 5 at position 0: 5 11 12 13

Inserting element 6 into sorted subarray: 5 11 12 13
  arr[3] = 13 > 6 --> shift arr[3] to arr[4]
  Current array: 5 11 12 13 13
  arr[2] = 12 > 6 --> shift arr[2] to arr[3]
  Current array: 5 11 12 12 13
  arr[1] = 11 > 6 --> shift arr[1] to arr[2]
  Current array: 5 11 11 12 13
Placed 6 at position 1: 5 6 11 12 13

Sorted array: 5 6 11 12 13


*/
#include <iostream>
using namespace std;

void recursiveInsertionSort(int arr[], int n)
{
   // Base case: one element is already sorted
   if (n <= 1)
      return;

   recursiveInsertionSort(arr, n - 1); // It says: “Forget about the n-th element for now. Let me make sure that the first n-1 elements are already sorted.”
   /*
   Imagine: You're building a tower one brick at a time.
   You're calling someone below:
      “Hey! Sort everything below me first, I’ll figure out where I belong once you’re done.”
   So we’re recursively shrinking the array until we hit just 1 element (base case), and then start inserting back one by one.
   */

   int last = arr[n - 1]; // Grab the last element: the current key to insert which is the one prior to the n-th element
   int j = n - 2;         // Start comparing it with the previous elements

   while (j >= 0 && arr[j] > last)
   {
      arr[j + 1] = arr[j]; // Shift the element right
      j--;                 // Move to the previous element
   }
   arr[j + 1] = last; // Place the key in its rightful position
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

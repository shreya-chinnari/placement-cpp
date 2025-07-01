#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
   if (size == 0 || size == 1)
   {
      return true; // Base case: an empty or single-element array is sorted
   }

   // Check if the first element is less than or equal to the second
   if (arr[0] > arr[1])
   {
      return false; // If the first element is greater than the second, it's not sorted
   }
   // Recursive call to check the rest of the array

   return isSorted(arr + 1, size - 1);
   // Here, we pass the array starting from the second element and reduce the size by 1
   // This effectively checks the rest of the array for sorted order

   //  else { bool remainingPart = isSorted(arr + 1, size - 1);
   //  return remainingPart; // Return the result of the recursive call }
}

int main()
{

   int arr[] = {1, 2, 8, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   bool ans = isSorted(arr, size);

   ans ? cout << "Array is sorted" : cout << "Array is not sorted";

   return 0;
}
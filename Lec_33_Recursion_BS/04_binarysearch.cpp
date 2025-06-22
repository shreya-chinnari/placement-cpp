#include <iostream>
using namespace std;

// Recursive Binary Search
bool binarySearch(int arr[], int s, int e, int key)
{
   // Base case: start > end means key is not found
   if (s > e)
      return false;

   // Calculate mid index safely
   int mid = s + (e - s) / 2;

   // Check if mid element is the key
   if (arr[mid] == key)
      return true;

   // If key is smaller, search in left half
   else if (key < arr[mid])
      return binarySearch(arr, s, mid - 1, key);

   // If key is larger, search in right half
   else
      return binarySearch(arr, mid + 1, e, key);
}
/*
    if (arr[mid] == key) {
        return true;  // Key found
    }
    else if (key < arr[mid]) {
        return binarySearch(arr, start, mid - 1, key);
    }
    else {
        return binarySearch(arr, mid + 1, end, key);
    }
*/
int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   int key = 3;
   int s = 0;
   int e = size - 1;

   bool ans = binarySearch(arr, s, e, key);

   // Output result
   ans ? cout << "Element found.\n" : cout << "Element not found.\n";

   return 0;
}

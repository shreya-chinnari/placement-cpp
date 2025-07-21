#include <iostream>
using namespace std;

// Recursive Binary Search Function
int elementIndex(int *arr, int start, int end, int X)
{
   if (start > end)
      return -1; // Base case: not found

   int mid = start + (end - start) / 2;

   if (arr[mid] == X)
      return mid;
   else if (arr[mid] > X)
      return elementIndex(arr, start, mid - 1, X);
   else
      return elementIndex(arr, mid + 1, end, X);
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int X = 3;
   int size = sizeof(arr) / sizeof(arr[0]);

   int index = elementIndex(arr, 0, size - 1, X);
   if (index != -1)
      cout << "Element " << X << " found at index: " << index << endl;
   else
      cout << "Element " << X << " not found in the array." << endl;

   return 0;
}

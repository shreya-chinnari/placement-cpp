#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
   for (int i = 0; i < n - 1; i++)
   {
      if (arr[i] > arr[i + 1])
      // if(arr[i] < arr[i + 1]) return false; // for descending order
      {
         return false; // for ascending order
      }
   }
   return true; // if no such condition is met, the array is sorted
}

int main()
{
   int arr1[] = {1, 2, 3, 4, 5};
   int n1 = sizeof(arr1) / sizeof(arr1[0]);
   +

       int arr2[] = {5, 4, 3, 2, 1};
   int n2 = sizeof(arr2) / sizeof(arr2[0]);

   cout << isSorted(arr1, n1) << endl; // Output: 1 (true)
   cout << isSorted(arr2, n2) << endl; // Output: 0 (
   return 0;
}
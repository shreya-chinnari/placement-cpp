#include <iostream>
using namespace std;

// we will use 2 for-loops to check if the array is sorted
// TC : O(n^2) because of nested loops
// SC : O(1) because we are using a fixed amount of space

// pehle "false" return kar do, phir final "true"

bool isSorted(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      for (int j = 1; j < n; j++)
      {
         if (arr[i] > arr[j]) // for ascending order
            return false;
         // if(arr[i] < arr[j]) return false; // for descending order
      }
      return true; // if no such condition is met, the array is not sorted
   }
}
int main()
{
   int arr1[] = {1, 2, 3, 4, 5};
   int n1 = sizeof(arr1) / sizeof(arr1[0]);

   int arr2[] = {5, 4, 3, 2, 1};
   int n2 = sizeof(arr2) / sizeof(arr2[0]);

   cout << isSorted(arr1, n1) << endl; // Output: 1 (true)
   cout << isSorted(arr2, n2) << endl; // Output: 0 (
   return 0;
}
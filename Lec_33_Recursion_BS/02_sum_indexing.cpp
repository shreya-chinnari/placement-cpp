
#include <iostream>
using namespace std;

int Sum(int arr[], int size)
{
   int sum = 0;

   // Base case: if size is 0, return sum
   if (size == 0)
   {
      return sum;
   }

   // Recursive case: add the last element to sum and call Sum for the rest of the array
   sum = arr[size - 1] + Sum(arr, size - 1);
   return sum;
   // [arr[size-1]] is the current {last} element of the array
   // [Sum(arr, size - 1)] is the sum of the rest of the array
   // The function continues to call itself until it reaches the base case where size is 0
}

/*

Always accesses the last element via indexing
Works backward from the end of the array toward the front **************

*/

int main()
{

   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   int sum = Sum(arr, size);
   cout << "Sum of array elements: " << sum << endl;
   return 0;
}
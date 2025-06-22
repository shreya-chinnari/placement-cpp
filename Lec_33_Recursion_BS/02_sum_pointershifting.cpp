// Pointer Shifting Approach

#include <iostream>
using namespace std;

int Sum(int *arr, int size)
{
   if (size == 0)
   {
      return 0; // Base case: if size is 0, return sum as 0
   }

   if (size == 1)
   {
      return arr[0]; // Base case: if size is 1, return the only element
   }

   int remainingSum = Sum(arr + 1, size - 1); // Recursive call to get sum of the rest of the array
   int sum = arr[0] + remainingSum;           // Add the first element to the sum of the restof the array
   return sum;                                // Return the total sum
}

/*
Instead of using indexing (arr[i]), you move the pointer forward (arr + 1)

arr[0] always refers to the current element

You process the first element and then move the pointer to the rest of the array
*/

int main()
{

   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   int sum = Sum(arr, size);
   cout << "Sum of array elements: " << sum << endl;
   return 0;
}
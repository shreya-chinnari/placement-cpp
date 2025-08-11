#include <iostream>
using namespace std;

// here also, we will return the size of the array with unique elements

// but we will use 2 pointer approach

// both pointers will start at the beginning of the array
// [j] one pointer will traverse the array, [i] and the other pointer will keep track of the last unique

int removeDuplicates(int arr[], int n)
{

   int i = 0; // i will point to the last unique element
   for (int j = 1; j < n; j++)
   {
      if (arr[j] != arr[i])
      {
         i++;             // increment i only if a unique element is found
         arr[i] = arr[j]; // copy the unique element to the next position
      }
   }

   return (i + 1); // return the size of the array with unique elements
}

int main()
{

   int arr[] = {12, 12, 12, 13, 13, 13, 15, 15}; // example array with duplicates
   int n = sizeof(arr) / sizeof(arr[0]);         // size of the array

   int k = removeDuplicates(arr, n);

   for (int i = 0; i < k; i++)
   {
      cout << arr[i] << " ";
   }

   return 0;
}
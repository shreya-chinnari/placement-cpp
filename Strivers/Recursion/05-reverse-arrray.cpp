// reverse an array using different methods in C++

#include <iostream>

void reverseArrayTwoPointers(int arr[], int size)
{
   int start = 0;
   int end = size - 1;

   while (start < end)
   {
      // Swap elements at start and end indices
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;

      // Move towards the center
      start++;
      end--;
   }
}

void reverseArrayRecursive(int arr[], int start, int end)
{
   if (start >= end)
      return;

   // Swap elements at start and end indices
   int temp = arr[start];
   arr[start] = arr[end];
   arr[end] = temp;

   // Recursive call with incremented start and decremented end
   reverseArrayRecursive(arr, start + 1, end - 1);
}

#include <iostream>

// Reverse Array Using Recursion with a Single Index Variable
void reverseArrayRecursiveSingleIndex(int arr[], int i, int size)
{
   if (i >= size / 2)
      return;

   // Swap arr[i] with arr[size - i - 1]
   int temp = arr[i];
   arr[i] = arr[size - i - 1];
   arr[size - i - 1] = temp;

   // Recursive call
   reverseArrayRecursiveSingleIndex(arr, i + 1, size);
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   // Reverse using two pointers method
   reverseArrayTwoPointers(arr, size);

   std::cout << "Reversed array (two pointers method): ";
   for (int i = 0; i < size; i++)
   {
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;

   // Reverse using recursion
   reverseArrayRecursive(arr, 0, size - 1);

   std::cout << "Reversed array (recursive method): ";
   for (int i = 0; i < size; i++)
   {
      std::cout << arr[i] << " ";
   }
   std::cout << std::endl;

   // Reverse using recursive function with single index
   reverseArrayRecursiveSingleIndex(arr, 0, size);

   std::cout << "Reversed array (recursive, single index): ";
   for (int i = 0; i < size; ++i)
      std::cout << arr[i] << " ";
   std::cout << std::endl;

   return 0;
}

// reverse the array

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
   cout << "array elements: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

void reverseArray(int arr[], int size)
{
   int start = 0;
   int end = size - 1; // these are positions

   while (start <= end)
   {
      // swap elements at start and end positions
      swap(arr[start], arr[end]);

      start++;
      end--;
   }
}

int main()
{
   int arr[5] = {0, 1, 3, 5, 4};
   printArray(arr, 5);
   reverseArray(arr, 5);
   printArray(arr, 5);

   return 0;
}

/*
OP:
   array elements: 0 1 3 5 4
   array elements: 4 5 3 1 0

*/
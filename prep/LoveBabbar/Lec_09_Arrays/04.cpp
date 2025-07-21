//  Find the max or min in an array

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

int max_element(int arr[], int size)
{
   int max_elem = arr[0];
   // int max_elem = INT_MIN;
   for (int i = 1; i < size; i++)
   {
      if (max_elem < arr[i])
      {
         max_elem = arr[i];
      }
   }

   cout << "max element in the array: " << max_elem;
   return max_elem;
}

int min_element(int arr[], int size)
{
   int min_elem = arr[0];
   // int min_elem = INT_MAX;
   for (int i = 1; i < size; i++)
   {
      if (min_elem > arr[i])
      {
         min_elem = arr[i];
      }
   }
   cout << "min element in the array: " << min_elem;
   return min_elem;
}

int main()
{
   int arr[10] = {2, 6, 20, 49, 1, 5, 6, 22, 67, 2};
   printArray(arr, 10);

   max_element(arr, 10);
   cout << endl;
   min_element(arr, 10);
   return 0;
}

/*
array elements: 2 6 20 49 1 5 6 22 67 2
max element in the array: 67
min element in the array: 1
*/
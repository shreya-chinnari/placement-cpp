#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int bubbleSort(int arr[], int n)
{
   for (int i = 1; i < n; i++)
   {
      for (int j = 0; j < n - i; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            swap(arr[j], arr[j + 1]);
         }
      }
   }
   return 0;
}

int main()
{
   int arr[] = {64, 25, 12, 22, 11};
   int n = sizeof(arr) / sizeof(arr[0]);
   cout << "Original array: " << endl;
   printArray(arr, n);
   bubbleSort(arr, n);
   cout << "Sorted array: " << endl;
   printArray(arr, n);

   return 0;
}

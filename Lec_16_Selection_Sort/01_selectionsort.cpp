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

int selectionSort(int arr[], int n)
{
   for (int i = 0; i < n; i++)
   {
      int minIndex = i;
      for (int j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[minIndex])
            minIndex = j;
      }
      swap(arr[i], arr[minIndex]);
   }
   return 0;
}
int main()
{
   int arr[] = {64, 25, 12, 22, 11};
   int n = sizeof(arr) / sizeof(arr[0]);
   selectionSort(arr, n);
   cout << "Sorted array: " << endl;
   printArray(arr, n);
   ;
   return 0;
}
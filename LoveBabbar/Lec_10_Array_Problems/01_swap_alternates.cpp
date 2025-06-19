// swap alternates

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

void swap_alternates(int arr[], int size)
{
   for (int i = 0; i < size; i = i + 2)
   {
      if (i + 1 < size)
      {
         int temp = arr[i];
         arr[i] = arr[i + 1];
         arr[i + 1] = temp;
         // swap(arr[i], arr[i+1]);
      }
   }
}

int main()
{

   int arr_even[5] = {1, 2, 3, 4, 5};
   printArray(arr_even, 5);
   swap_alternates(arr_even, 5);
   printArray(arr_even, 5);

   int arr_odd[6] = {1, 2, 3, 4, 5, 6};
   printArray(arr_odd, 6);
   swap_alternates(arr_odd, 6);
   printArray(arr_odd, 6);
   return 0;
}

/*
O/P:

array elements: 1 2 3 4 5
array elements: 2 1 4 3 5

array elements: 1 2 3 4 5 6
array elements: 2 1 4 3 6 5

*/
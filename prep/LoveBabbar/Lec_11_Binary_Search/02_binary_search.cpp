#include <iostream>
using namespace std;

int binary_search(int arr[], int size, int key)
{
   int start = 0;
   int end = size - 1;
   int mid = start + (end - start) / 2; // to avoid integer overflow

   while (start <= end)
   {
      if (arr[mid] == key)
      {
         return mid; // key found at index mid
      }
      else if (key > arr[mid])
      {
         start = mid + 1; // key is in the right half
      }
      else
      {
         end = mid - 1; // key is in the left half
      }
      mid = start + (end - start) / 2; // recalculate mid
   }
   return -1; // key not found
}

int main()
{
   int arr_even[6] = {1, 2, 3, 4, 5, 6};
   int arr_odd[5] = {1, 2, 3, 4, 5};
   int key = 3;

   int even_index = binary_search(arr_even, 6, key);
   cout << "Key found at index (even array): " << even_index << endl;
   int odd_index = binary_search(arr_odd, 5, key);
   cout << "Key found at index (odd array): " << odd_index << endl;

   return 0;
}
// find total number of occurrences of an element "key" in sorted array

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

int first_occurrence(int arr[], int size, int key)
{
   int start = 0, end = size - 1, index = -1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         index = mid;
         end = mid - 1; // Search in left half
      }
      else if (arr[mid] < key)
      {
         start = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
   }
   return index;
}

int last_occurrence(int arr[], int size, int key)
{
   int start = 0, end = size - 1, index = -1;
   while (start <= end)
   {
      int mid = start + (end - start) / 2;
      if (arr[mid] == key)
      {
         index = mid;
         start = mid + 1; // Search in right half
      }
      else if (arr[mid] < key)
      {
         start = mid + 1;
      }
      else
      {
         end = mid - 1;
      }
   }
   return index;
}

int total_occurrences(int arr[], int size, int key)
{
   int first = first_occurrence(arr, size, key);
   int last = last_occurrence(arr, size, key);

   if (first == -1 || last == -1)
      return 0;

   return last - first + 1; // Total occurrences = last index - first index + 1
}

int main()
{
   int arr[12] = {1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);
   int key = 3;

   cout << "Total occurrences of " << key << ": " << total_occurrences(arr, size, key) << endl;
   return 0;
}

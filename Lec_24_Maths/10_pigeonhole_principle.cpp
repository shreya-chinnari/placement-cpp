/*
✅ Problem:
   You're given an array of n+1 integers where each integer is in the range 1 to n.
   By the Pigeonhole Principle, there must be at least one duplicate.
*/

#include <iostream>
using namespace std;

int findDuplicate(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      for (int j = i + 1; j < size; j++)
      {
         if (arr[i] == arr[j])
         {
            return arr[i]; // Found duplicate
         }
      }
   }
   return -1; // No duplicate found (shouldn't happen due to pigeonhole)
}

int main()
{
   int arr[] = {1, 3, 4, 2, 5, 3}; // 6 elements, values 1 to 5 → must repeat
   int size = sizeof(arr) / sizeof(arr[0]);

   int duplicate = findDuplicate(arr, size);
   if (duplicate != -1)
      cout << "Duplicate found: " << duplicate << endl;
   else
      cout << "No duplicate found" << endl;
}

#include <iostream>
using namespace std;

bool hasDuplicates(int arr[], int size)
{
   for (int i = 0; i < size - 1; i++)
   {
      for (int j = i + 1; j < size; j++)
      {
         if (arr[i] == arr[j])
         {
            return true; // Duplicate found
         }
      }
   }
   return false; // No duplicates
}

int main()
{
   int arr[] = {4, 2, 7, 3, 2}; // Change this to test different inputs
   int size = sizeof(arr) / sizeof(arr[0]);

   cout << "Array elements: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;

   if (hasDuplicates(arr, size))
   {
      cout << "Duplicates found in the array." << endl;
   }
   else
   {
      cout << "No duplicates in the array." << endl;
   }

   return 0;
}

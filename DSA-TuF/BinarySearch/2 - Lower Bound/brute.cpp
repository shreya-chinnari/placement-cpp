#include <iostream>
using namespace std;

int linearSearchLowerBound(int arr[], int size, int n)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] >= n)
      {
         return i; // Return the index of the first element >= n
      }
   }
   return -1;
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);
   int n = 3;
   int result = linearSearchLowerBound(arr, size, n);

   if (result != -1)
   {
      cout << "Lower bound of " << n << " is at index: " << result << endl;
   }
   else
   {
      cout << "No element found greater than or equal to " << n << endl;
   }

   n = 93;
   result = linearSearchLowerBound(arr, size, n);
   if (result != -1)
   {
      cout << "Lower bound of " << n << " is at index: " << result << endl;
   }
   else
   {
      cout << "No element found greater than or equal to " << n << endl;
   }
   return 0;
}

// TC O(n) - Linear search through the array
// SC O(1) - No extra space used
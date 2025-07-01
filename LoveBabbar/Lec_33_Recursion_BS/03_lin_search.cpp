#include <iostream>
using namespace std;

bool LinearSearch(int arr[], int size, int key)
{

   if (size == 0)
   {
      return false; // Base case: if size is 0, element not found
   }

   if (arr[0] == key)
   {
      return true; // Element found
   }

   // Recursive case: check the rest of the array
   return LinearSearch(arr + 1, size - 1, key);
   // Here, we pass the array starting from the next element and reduce the size by 1
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   bool ans = LinearSearch(arr, size, 3);
   ans ? cout << "Element found" : cout << "Element not found";
   return 0;
}
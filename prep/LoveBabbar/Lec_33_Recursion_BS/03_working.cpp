#include <iostream>
using namespace std;

void print(int arr[], int size)
{
   // size
   cout << "Size of Array: " << size << endl;
   // elements
   cout << "Elements of Array: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

bool LinearSearch(int arr[], int size, int key)
{

   print(arr, size);

   if (size == 0)
   {
      return false;
   }

   if (arr[0] == key)
   {
      return true;
   }
   return LinearSearch(arr + 1, size - 1, key);
}
/*
Size of Array: 5
Elements of Array: 1 2 3 4 5
Size of Array: 4
Elements of Array: 2 3 4 5
Size of Array: 3
Elements of Array: 3 4 5
Element found
*/
int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int size = sizeof(arr) / sizeof(arr[0]);

   bool ans = LinearSearch(arr, size, 3);
   ans ? cout << "Element found" : cout << "Element not found";
   return 0;
}
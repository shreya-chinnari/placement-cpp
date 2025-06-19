// linear search

#include <iostream>
using namespace std;

bool linear_search(int arr[], int size, int key)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] == key)
      {
         return 1;
      }
   }
   return 0;
}

int main()
{
   int arr[5] = {1, 2, 3, 4, 5};

   int key;
   cout << "enter element to find (key) : ";
   cin >> key;

   bool found = linear_search(arr, 5, key);
   if (found)
   {
      cout << "FOUND!";
   }
   else
   {
      cout << "NOT FOUND!";
   }
   return 0;
}
// enter element to find (key) : 3
// FOUND !
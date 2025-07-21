// array scope
// if we update array in another function, it will get updated in main function too

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

void update(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      arr[i] = arr[i] * 2;
   }
   cout << " array in update function: " << endl;
   printArray(arr, size);
}

int main()
{
   int arr[5] = {1, 2, 3, 4, 5};
   cout << " array in main function: " << endl;
   printArray(arr, 5);

   update(arr, 5);

   cout << " array in main function after update(): " << endl;
   printArray(arr, 5);

   return 0;
}

/*

 array in main function:
1 2 3 4 5
 array in update function:
2 4 6 8 10
 array in main function after update():
2 4 6 8 10

*/
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

int main()
{
   int a[10] = {};
   printArray(a, 10);
   // to find size of array if we don't know the number of elements in it
   cout << "size of 'a': " << sizeof(a) / sizeof(int);
   // cout << "size of 'arr': " << sizeof(arr) / sizeof(char);
   // cout << "size of 'arr': " << sizeof(arr) / sizeof(float);
   // cout << "size of 'arr': " << sizeof(arr) / sizeof(doubt);
   // cout << "size of 'arr': " << sizeof(arr) / sizeof(bool);

   return 0;
}
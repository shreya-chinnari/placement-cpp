#include <iostream>
using namespace std;

int getSum(int arr[], int size)
{

   cout << "\nsize: " << sizeof(arr) << endl; // This will not work, as arr is a pointer, not an array
   // size: 8, why?
   // because arr is a pointer to the first element of the array,
   // and arr[i] is equivalent to *(arr + i), which dereferences the pointer

   // int getSum(int arr[], int size) : here arr is a pointer to the first element of the array,
   // not an array itself. When you pass an array to a function in C++, it decays to a pointer to its first element.
   int sum = 0;
   for (int i = 0; i < size; i++)
   {
      sum += arr[i]; // Accessing elements using array notation
   }
   return sum;
}

int main()
{
   int arr[5] = {10, 20, 30, 40, 50};
   int *p = arr; // Pointer p points to the first element of arr

   cout << "sum: " << getSum(arr, 5) << endl;
   return 0;
}
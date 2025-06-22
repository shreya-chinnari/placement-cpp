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

   // benefit:
   // 1. faster: because we don't need to copy the array
   // 2. more memory efficient: because we don't need to copy the array
   // 3. we can pass large arrays without worrying about stack overflow
   // 4. we can pass arrays of different sizes to the same function
   // 5. we can use pointer arithmetic to access the elements of the array
   // 6. we can send "part" of the array to the function, not the whole array ****
   // 7. we can use pointer notation to access the elements of the array
   int sum = 0;
   for (int i = 0; i < size; i++)
   {
      sum += arr[i]; // Accessing elements using array notation
      // sum += i[arr]; // both are same
   }
   return sum;
}

int main()
{
   int arr[5] = {10, 20, 30, 40, 50};
   int *p = arr; // Pointer p points to the first element of arr

   cout << "sum: " << getSum(arr, 5) << endl;     // Passing the whole array, 150
   cout << "sum: " << getSum(arr + 3, 2) << endl; // Passing a part of the array, 90
   // Here, arr + 3 points to the 4th element of the array
   return 0;
}
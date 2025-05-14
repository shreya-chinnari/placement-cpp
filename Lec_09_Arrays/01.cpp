// initialise entire array with same digit

#include <iostream>
#include <array>
#include <algorithm>

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
   // ✅ Uninitialised array

   int empty_arr[20];
   printArray(empty_arr, 20); // -1865934784 32759 -1865935547 32759 -576895888 651 0 0 0 0 0 1 -593495664 250 -1865934568 32759 -576895888 651 0 1
   // because the array empty_arr is not initialized { garbage values }

   // ✅ Accessing index outside array size

   int new_arr[5] = {1, 2, 3, 4, 5};
   cout << "new_arr[10]: " << new_arr[10] << endl; // random garbage value

   // ✅ For zero initialization:

   int a[10] = {};
   printArray(a, 10); // 0 0 0 0 0 0 0 0 0 0

   // ✅ For non-zero initialization, use a loop:

   int b[10];
   for (int i = 0; i < 10; ++i)
   {
      b[i] = 42;
   }
   printArray(b, 10); // 42 42 42 42 42 42 42 42 42 42

   int b2[10];
   std::fill_n(b2, 10, 42); // (arr, size, digit)
   printArray(b2, 10);      // 42 42 42 42 42 42 42 42 42 42

   return 0;
}
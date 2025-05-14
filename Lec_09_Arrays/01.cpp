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
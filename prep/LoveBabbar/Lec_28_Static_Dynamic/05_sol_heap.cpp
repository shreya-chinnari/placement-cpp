#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter size of array: ";
   cin >> n;

   // ✅ Good: heap allocation using new
   int *arr = new int[n]; // Allocates memory on heap dynamically
   // Note: This is a pointer to the first element of the array
   // new int[n] = 5, You canNOT assign a single value (= 5) to an entire dynamically allocated array in this way.

   // Initialize array
   for (int i = 0; i < n; ++i)
      arr[i] = i * 10;

   // Print array
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";

   cout << endl;

   /*
   ✅ Don't forget to free heap memory

   You're asking the system to reserve memory on the heap for n integers. That memory is not automatically released when the function or program ends.

   |  So to avoid a memory leak, you must release it using:
   */
   delete[] arr;

   return 0;
}

/*
Enter size of array: 8
0 10 20 30 40 50 60 70

*/
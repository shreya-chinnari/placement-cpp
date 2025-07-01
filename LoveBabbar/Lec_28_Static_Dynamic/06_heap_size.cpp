#include <iostream>
using namespace std;

int main()
{
   int a = 5;
   cout << sizeof(a) << endl; // Size of int (usually 4 bytes)

   int *p = &a;
   cout << sizeof(p) << endl; // Size of pointer (usually 8 bytes on 64-bit systems)

   // total = 12 bytes

   char ch = 'w';
   cout << sizeof(ch) << endl; // Size of char (1 byte)
   char *pc = &ch;             // 8 bytes
   cout << sizeof(pc) << endl;

   // total = 9 bytes

   /*=====================================*/

   // 🔸 Stack Memory
   int *arr = nullptr; // 'arr' is a pointer variable → stored on stack (8 bytes on 64-bit systems)

   // 🔸 Heap Memory
   arr = new int[10]; // Creates an array of 10 integers on the heap (10 * 4 = 40 bytes)

   // Print contents and memory addresses
   cout << "Address of pointer 'arr' (on stack): " << &arr << endl;
   cout << "Address of first element in heap (arr points to): " << arr << endl;

   // Print size of stack variable (the pointer itself)
   cout << "Size of pointer 'arr' (on stack): " << sizeof(arr) << " bytes" << endl;

   // Print size of each element in the heap array
   cout << "Size of one int element: " << sizeof(arr[0]) << " bytes" << endl;

   // Total heap memory = 10 elements * size of int
   cout << "Total size of dynamic array (on heap): " << sizeof(arr[0]) * 10 << " bytes" << endl;

   // Clean up heap memory
   delete[] arr;

   return 0;
}

/*
Address of pointer 'arr' (on stack): 0xf5d93ffa68
Address of first element in heap (arr points to): 0x2f408036780

Size of pointer 'a' (on stack): 8 bytes
Size of one int element: 4 bytes
Total size of dynamic array (on heap): 40 bytes

Heap values:
arr[0] = 10 at address 0x2f408036780
arr[1] = 20 at address 0x2f408036784
arr[2] = 30 at address 0x2f408036788
arr[3] = 40 at address 0x2f40803678c
arr[4] = 50 at address 0x2f408036790
arr[5] = 60 at address 0x2f408036794
arr[6] = 70 at address 0x2f408036798
arr[7] = 80 at address 0x2f40803679c
arr[8] = 90 at address 0x2f4080367a0
arr[9] = 100 at address 0x2f4080367a4
*/
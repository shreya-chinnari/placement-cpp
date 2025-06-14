#include <iostream>
using namespace std;

int main()
{
   // The array 'arr' is stored as a contiguous block of memory.
   // In the symbol table: 'arr' is associated with a fixed memory address (e.g., 0x1000),
   // and cannot be reassigned like a pointer (hence, arr = arr + 1; would be illegal).
   int arr[5] = {10, 20, 30, 40, 50};

   // Pointer 'p' is created and initialized to point to the base address of 'arr'.
   // In the symbol table: 'p' is stored as a separate variable (e.g., at 0x2000)
   // and contains the address 0x1000 (assuming arr starts at 0x1000).
   int *p = arr;

   // Prints the address currently stored in 'p' (address of arr[0])
   // Symbol table is not directly involved here, but memory pointed by p is used.
   cout << "p: " << p << endl;

   // Pointer arithmetic: p = p + 1 moves the pointer to the next int (4 bytes ahead)
   // New address in 'p' = 0x1000 + sizeof(int) = 0x1004
   p = p + 1;

   // Now p points to arr[1]; this prints the updated address
   cout << "p: " << p << endl;

   return 0;
}

/*
Symbol Table Overview:
-----------------------
Name     | Type         | Address (Example) | Value Stored
---------|--------------|-------------------|--------------------------
arr      | int[5]       | 0x1000            | {10, 20, 30, 40, 50}
p        | int*         | 0x2000            | Initially 0x1000, then 0x1004

Important Notes:
- 'arr' is a constant pointer to the first element and cannot be reassigned.
- 'p' is a pointer variable that stores memory addresses and supports arithmetic.
- When p = p + 1, it moves 4 bytes forward (assuming int = 4 bytes),
  thus pointing from arr[0] to arr[1].

Sample Output:
--------------
p: 0x8d0a5ffa40  // Address of arr[0]
p: 0x8d0a5ffa44  // Address of arr[1] = previous address + 4
*/

/*
✅ What is Padding?
Padding is the extra space added by the compiler to align data members in memory, based on their data type’s alignment requirements.

✅ What is Alignment?
Alignment is a requirement that certain data types should start at memory addresses that are multiples of their size (typically for performance reasons).

✅ What is Greedy Alignment?
It means the compiler lays out structure members in order of declaration, inserting padding wherever necessary to maintain proper alignment.
*/

#include <iostream>
using namespace std;

class A
{
public:
   char a; // 1 byte
   int b;  // 4 bytes
   char c; // 1 byte
};

// Rearranged version of A to reduce padding
class B
{
public:
   int b;  // 4 bytes
   char a; // 1 byte
   char c; // 1 byte
};

// Packed structure (compiler-specific; requires pragma or attributes)
// Only works on GCC/Clang with __attribute__((packed))
// You can use #pragma pack in MSVC or GCC too
#pragma pack(1)
class C
{
public:
   char a; // 1 byte
   int b;  // 4 bytes
   char c; // 1 byte
};
#pragma pack() // Reset to default

int main()
{
   A objA;
   B objB;
   C objC;

   cout << "Size of class A: " << sizeof(A) << " bytes" << endl;
   cout << "Size of class B (reordered): " << sizeof(B) << " bytes" << endl;
   cout << "Size of class C (packed): " << sizeof(C) << " bytes" << endl;

   return 0;
}

/*
Size of class A: 12 bytes
Size of class B (reordered): 8 bytes
Size of class C (packed): 6 bytes


class A:
      char a;   // 1 byte
               // 3 bytes padding to align next int
      int b;    // 4 bytes
      char c;   // 1 byte
               // 3 bytes padding to align object size to multiple of 4 or 8

class B:
      int b;    // 4 bytes
      char a;   // 1 byte
      char c;   // 1 byte
               // 2 bytes padding to align object size to multiple of 4 or 8

class C:
      char a;   // 1 byte
      int b;    // 4 bytes
      char c;   // 1 byte
               // No padding needed due to #pragma pack
               // ⚠️ But this may hurt performance on some architectures because misaligned accesses are slower or even cause crashes (e.g., on ARM).
*/
#include <iostream>
using namespace std;

int main()
{
   while (true)
   {
      int *ptr = new int;
   }

   /*
   🧨 Why This Is Dangerous:

🔁 1. Infinite Allocation Without Freeing

   Every time the loop runs, new int allocates 4 bytes (typically) on the heap.
   The pointer ptr is redeclared inside the loop and goes out of scope immediately.
   But the memory on the heap stays allocated — it’s never freed using delete.

🔗 2. No delete ptr; → Memory Leak

   Every allocated block becomes unreachable after one iteration.
   This is a local variable inside the {} block of the loop.
   Each iteration, a new pointer variable ptr is created, used, and destroyed at the end of the iteration.

   Result: Memory keeps filling up → until the system runs out.

   Every time the loop runs:
      int* ptr = new int;
      👉 Allocates 4 bytes (int) on the heap, returns a pointer to it
      👉 ptr (on stack) stores that address

But...

   As soon as that iteration ends, the stack variable ptr goes out of scope and is destroyed

   But the memory allocated on the heap is still there, and you’ve lost the address to access it

   So it's a memory leak — memory is still occupied but you can't delete it anymore

📉 What Happens Over Time

   Heap memory usage increases steadily.
   Your program becomes slower.
   Eventually, the OS may kill the process due to:
      - std::bad_alloc (if new throws)
      - Out-of-memory crash

   */

   // Corrected version
   while (true)
   {
      int *ptr = new int;
      // use ptr...
      delete ptr; // ✅ Frees heap memory properly
   }

   while (true)
   {
      int i = 6;
   }
   // har instance of time, only one variable i is created on the stack
   // It is created and destroyed in each iteration, but no memory leak occurs.
   // see image 08_png

   return 0;
}
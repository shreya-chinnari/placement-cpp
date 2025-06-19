#include <iostream>
using namespace std;

int main()
{
   // using
   char *c = "abcde";
   // is risky and dangerous for the following reasons:

   /*
   ⚠️ 1. String Literal is Stored in Read-Only Memory
"abcde" is a string literal.

In most modern C++ compilers, string literals are stored in read-only (RO) memory.

char *c implies that the string is modifiable, but it's not safe to modify a string literal.

   Example (undefined behavior):
   char *c = "abcde";
   c[0] = 'z';  // ❌ May cause a segmentation fault!
*/

   /*
   ⚠️ 2. Violates const Safety

   The type should always be:

   const char *c = "abcde";

   This signals that the string data shouldn't be changed, and the compiler can enforce it.

   ⚠️ 3. Compiler Might Not Warn You
   Even though it's unsafe, most compilers allow char *c = "abcde" for legacy C compatibility.

   But modifying it results in undefined behavior, which is very dangerous and can crash your program.



   ✅ Safe Alternatives
Unsafe	               |      Safe Equivalent
------------------------------------------------------
char *c = "abcde";	   |      const char *c = "abcde";
(modifiable string)	   |      char c[] = "abcde"; (creates copy in stack)
   */
   return 0;
}
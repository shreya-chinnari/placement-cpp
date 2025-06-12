#include <iostream>
using namespace std;

int main()
{
   int a, b, m;
   // basic properties
   /* (a + b) % m = ((a % m) + (b % m)) % m;
      (a - b) % m = ((a % m) - (b % m) + m) % m;
      (a * b) % m = ((a % m) * (b % m)) % m;
   */

   // fast exponentiation

   /* --- SIMPLE FORMULA ---
   long long result = 1;
   for (long long i = 0; i < b; i++) {
      result = result * a;
   }
   return result;
   */

      return 0;
}
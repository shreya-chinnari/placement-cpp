// You are given three integers X, N, and M.
// Your task is to compute : (X ^ N) % M
// -- -- -- -- -- --
// normal way : O(n)
// fast exponentiation : o(log n)

#include <iostream>
using namespace std;

long long modularPower(long long x, long long n, long long m)
{
   long long result = 1;
   x = x % m; // Take mod first to avoid overflow

   // while (n > 0)
   // {
   //    if (n % 2 == 1)
   //    {
   //       result = (result * x) % m;
   //    }
   //    x = (x * x) % m;
   //    n = n / 2;
   // }
   while (n > 0)
   {
      if (n & 1)
      {
         // odd
         result = (result * x) % m; // ✅ Take mod here
      }
      x = (x * x % m); // ✅ Take mod here
      n = n >> 1;
   }

   return result;
}

int main()
{
   long long X, N, M;
   cout << "Enter X, N, M: ";
   cin >> X >> N >> M;

   cout << "(" << X << "^" << N << ") % " << M << " = " << modularPower(X, N, M) << endl;
   return 0;
}

/*
while (n > 0)
   - Keep looping as long as the exponent n is greater than 0.
   - We reduce n in each step by halving it.

if (n & 1)
   - This checks whether n is odd using bitwise AND.
   - (n & 1) is 1 if n is odd, 0 if n is even.

If n is odd, we multiply result by the current x.
   - result = result * x;
   - When n is odd, we include x in our result (because of how binary exponentiation works).

x = x * x;
   - Square the base x. This is part of the binary exponentiation method:
      > If you're processing the bit at position k in n, you square x 'k' times.
      > It keeps track of powers of 2 in the exponent.

n = n >> 1;
   - This is bitwise right shift, equivalent to integer division by 2.
   - It removes the least significant bit (the one we just processed).
   - Effectively, this reduces n to process the next bit.

*/
#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long factorialMod(int n)
{
   long long result = 1;
   for (int i = 2; i <= n; i++)
   {
      result = (result * i) % MOD; // Take mod at every step
   }
   return result;
}

int main()
{
   int n = 212;
   cout << n << "! % " << MOD << " = " << factorialMod(n) << endl;
   return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<long long> computeCatalan(int n)
{
   vector<long long> C(n + 1, 0);
   C[0] = 1;

   for (int i = 1; i <= n; i++)
   {
      for (int j = 0; j < i; j++)
      {
         C[i] += C[j] * C[i - 1 - j];
      }
   }
   return C;
}

int main()
{
   int n = 10;
   vector<long long> catalan = computeCatalan(n);
   for (int i = 0; i <= n; i++)
   {
      cout << "Catalan[" << i << "] = " << catalan[i] << endl;
   }
}

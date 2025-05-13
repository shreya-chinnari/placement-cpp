// ncr

#include <iostream>
using namespace std;

int factorial(int a)
{
   int fact = 1;
   for (int i = 1; i <= a; i++)
   {
      fact = fact * i;
   }
   return fact;
}

int nCr(int n, int r)
{
   int numR = factorial(n);
   int denR = factorial(r) * factorial(n - r);
   int nCr = numR / denR;

   return nCr;
}

int main()
{
   int n;
   cout << "Enter 'n': " << endl;
   cin >> n;
   int r;
   cout << "Enter 'r': " << endl;
   cin >> r;

   int result = nCr(n, r);
   cout << "nCr: " << result;
   return 0;
}
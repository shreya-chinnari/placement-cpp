// factorial using recursion

#include <iostream>
using namespace std;

// Parametric way: Accumulate factorial by passing the product as an argument.
int parametricFactorial(int n, int product)
{
   if (n == 0 || n == 1)
   {
      return product;
   }

   return parametricFactorial(n - 1, product * n);
}

// Functional way: No additional parameters other than n, simply multiply down.
int functionalFactorial(int n)
{
   if (n == 0 || n == 1)
      return 1;

   return n * functionalFactorial(n - 1);
}

int main()
{

   int n = 5;

   cout << "Factorial of " << n << " using parametric recursion: "
        << parametricFactorial(n, 1) << endl;

   cout << "Factorial of " << n << " using functional recursion: "
        << functionalFactorial(n) << endl;

   return 0;
}
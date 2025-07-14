// factorial using recursion

#include <iostream>
using namespace std;

// Parametric way: Accumulate factorial by passing the product as an argument.
int parametricFactorial(int n, int product)
{
   if (n == 0 || n == 1)
   {
      return 1;
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

int factorialForLoop(int n)
{
   int fact = 1;
   for (int i = 2; i <= n; i++)
   {
      fact *= i;
   }
   return fact;
}

int factorialWhileLoop(int n)
{
   int fact = 1;
   int i = 2;
   while (i <= n)
   {
      fact *= i;
      i++;
   }
   return fact;
}

int main()
{

   int n = 5;

   cout << "Factorial of " << n << " using parametric recursion: "
        << parametricFactorial(n, 1) << endl;

   cout << "Factorial of " << n << " using functional recursion: "
        << functionalFactorial(n) << endl;

   cout << "Factorial using for loop: " << factorialForLoop(n) << endl;
   cout << "Factorial using while loop: " << factorialWhileLoop(n) << endl;
   return 0;
}
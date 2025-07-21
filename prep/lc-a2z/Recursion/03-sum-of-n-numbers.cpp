// sum of first n natural numbers using recursion
// - paramerised way
// - functional way

#include <iostream>
using namespace std;

// Parametric way: Accumulate sum by passing the sum as an argument.
int parametricSum(int n, int sum)
{
   if (n < 1)
   {
      return sum;
   }

   return parametricSum(n - 1, sum + n);
}

// Parametric way (i to n): Accumulate sum by passing the sum and index (i) as arguments.
int parametricSumItoN(int i, int n, int sum)
{
   if (i > n)
   {
      return sum;
   }

   return parametricSumItoN(i + 1, n, sum + i);
}

// Functional way: No additional parameters other than n, simply add up.
int functionalSum(int n)
{
   if (n == 0)
      return 0;

   return n + functionalSum(n - 1);
}

// Functional way: Functional Recursive Code to Find Sum from i to n:
int functionalSumFromIToN(int i, int n)
{
   if (i > n)
      return 0;

   return i + functionalSumFromIToN(i + 1, n);
}

int main()
{
   cout << "Sum of first 5 natural numbers (parametric): " << parametricSum(5, 0) << endl;
   cout << "Sum of first 5 natural numbers (parametric i to n): " << parametricSumItoN(1, 5, 0) << endl;
   cout << "Sum of first 5 natural numbers (functional): " << functionalSum(5) << endl;
   cout << "Sum of first 5 natural numbers (functional i to n): " << functionalSumFromIToN(1, 5) << endl;

   return 0;
}
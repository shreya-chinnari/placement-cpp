#include <iostream>
using namespace std;

// Parametric way: Accumulate product by passing product as an argument.
int parametricProduct(int n, int product)
{
   if (n < 1)
      return product;

   return parametricProduct(n - 1, product * n);
}

// Parametric way (i to n): Accumulate product by passing index (i) and product.
int parametricProductItoN(int i, int n, int product)
{
   if (i > n)
      return product;

   return parametricProductItoN(i + 1, n, product * i);
}

// Functional way: No additional parameters other than n, simply multiply.
int functionalProduct(int n)
{
   if (n == 0 || n == 1)
      return 1;

   return n * functionalProduct(n - 1);
}

// Functional way (i to n): Functional Recursive Code to Find Product from i to n.
int functionalProductFromIToN(int i, int n)
{
   if (i > n)
      return 1;

   return i * functionalProductFromIToN(i + 1, n);
}

int main()
{
   cout << "Product of first 5 natural numbers (parametric): " << parametricProduct(5, 1) << endl;
   cout << "Product of first 5 natural numbers (parametric i to n): " << parametricProductItoN(1, 5, 1) << endl;
   cout << "Product of first 5 natural numbers (functional): " << functionalProduct(5) << endl;
   cout << "Product of first 5 natural numbers (functional i to n): " << functionalProductFromIToN(1, 5) << endl;

   return 0;
}

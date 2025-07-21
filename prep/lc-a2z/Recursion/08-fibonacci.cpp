#include <iostream>
using namespace std;

// Brute force - recursive approach
// TC - O(2^n) - exponential, because each call branches into two recursive calls.
// SC - O(n) - due to recursion stack space
int fibRecursive(int n)
{
   if (n <= 1)
      return n;
   return fibRecursive(n - 1) + fibRecursive(n - 2);
}

// Iterative approach (better approach)
// TC - O(n) - linear, as we compute each Fibonacci number once.
// SC - O(1) - constant space, as we only use a few variables.
int fibIterative(int n)
{
   if (n <= 1)
      return n;

   int a = 0, b = 1;
   for (int i = 2; i <= n; ++i)
   {
      int temp = b;
      b = a + b;
      a = temp;
   }
   return b;
}

// Optimized iterative approach
// TC - O(n), SC - O(1)
int fibOptimized(int n)
{
   if (n <= 1)
      return n;

   int a = 0, b = 1;
   for (int i = 2; i <= n; ++i)
   {
      int next = a + b;
      a = b;
      b = next;
   }
   return b;
}

int main()
{
   int n;
   cout << "Enter the value of n: ";
   cin >> n;

   cout << "Brute Force (Recursive): " << fibRecursive(n) << endl;
   cout << "Iterative: " << fibIterative(n) << endl;
   cout << "Optimized Iterative: " << fibOptimized(n) << endl;
   return 0;
}
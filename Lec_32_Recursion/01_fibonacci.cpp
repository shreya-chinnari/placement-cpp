// TO CALCULATE (n)th FIBONACCI NUMBER USING RECURSION

#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci of n
int fibonacci(int n)
{
   // Base cases
   if (n == 0)
      return 0; // 0th Fibonacci number is 0
   if (n == 1)
      return 1; // 1st Fibonacci number is 1

   // Recursive calls:
   // Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
   return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
   int n;

   cout << "Enter number of terms: ";
   cin >> n;

   cout << "Fibonacci Series up to " << n << " terms:" << endl;

   for (int i = 0; i < n; i++)
   {
      cout << fibonacci(i) << " ";
   }

   cout << endl;
   return 0;
}

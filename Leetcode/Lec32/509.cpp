#include <iostream>
using namespace std;

class Solution
{
public:
   int fib(int n)
   {
      long long a = 1, b = 0;
      if (n == 1)
         return 1;
      if (n == 0)
         return 0;
      for (int i = 0; i < n - 1; i++)
      {
         swap(a, b);
         a += b;
      }
      return a;
   }
};

int main()
{
   Solution sol; // Create object of Solution class
   int n;

   cout << "Enter a number (n): ";
   cin >> n;

   int result = sol.fib(n); // Call fib() method
   cout << "Fibonacci(" << n << ") = " << result << endl;

   return 0;
}

// a^b : odd and even

#include <iostream>
using namespace std;

int power(int a, int b)
{
   // Base case
   if (b == 0)
   {
      return 1; // a^0 = 1
   }

   if (b == 1)
   {
      return a; // a^1 = a
   }

   // Recursive case

   int ans = power(a, b / 2);
   // if b is even
   if (b % 2 == 0)
   {
      return ans * ans; // a^(b/2) * a^(b/2) = a^b
   }
   // if b is odd
   else
   {
      return a * ans * ans; // a * a^(b/2) * a^(b/2) = a^b
   }
}

int main()
{
   int a, b;
   cout << "Enter two integers (a and b): ";
   cin >> a >> b;

   cout << power(a, b) << endl;
   return 0;
}
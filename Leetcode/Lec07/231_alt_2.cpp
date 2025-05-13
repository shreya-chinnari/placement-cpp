#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int ans = 1;
   for (int i = 0; i <= 30; i++)
   {

      if (ans == n)
      {
         return true;
      }
      // for 0, runtime error, can not be represented as 2^x
      if (ans < INT_MAX / 2) // After multiplying, ans * 2 will still be ≤ INT_MAX. It is safe to do the multiplication without causing overflow.

      {
         ans = ans * 2;
      }
   }
   return false;
}
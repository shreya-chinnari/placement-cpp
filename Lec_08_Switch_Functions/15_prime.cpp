// prime

#include <iostream>
using namespace std;

bool isPrime(int n)
{
   for (int i = 2; i < n; i++)
   {
      if (n % i == 0)
      {
         return 0; // true, is Prime yes
      }
   }
   return 1;
}

int main()
{
   int n;
   cout << "enter number: " << endl;
   cin >> n;

   // if (isPrime) // this is not actually calling the function. It just checks if the function name isPrime itself exists (which always evaluates to true in this context, because it's a valid function pointer).
   if (isPrime(n))
   {
      cout << "prime!";
   }
   else
   {
      cout << "not prime!";
   }
   return 0;
}
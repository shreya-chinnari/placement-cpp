// prime number

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   // 0,1 are not prime numbers

   if (n <= 1)
   {
      cout << n << " is not a prime number." << endl;
      return 0;
   }

   // for a number 'n'

   bool isPrime = true;

   for (int i = 2; i < n; i++) // i=2 to n-1
   {
      if (n % i == 0)
      {
         isPrime = false;
         break;
      }
   }

   if (isPrime)
   {
      cout << n << " is a prime number." << endl;
   }
   else
   {
      cout << n << " is not a prime number." << endl;
   }

   return 0;
}
#include <iostream>
using namespace std;

int fact(int n)
{
   // Base case
   if (n == 0 || n == 1)
   {
      return 1;
   }
   // Recursive case

   /*
   int smallerFact = fact(n - 1);
   int biggerFact = n * smallerFact;
   return biggerFact;
   */

   /*
   int smallerFact = fact(n - 1);
   return n * smallerFact;
   */

   return n * fact(n - 1);
}

int main()
{
   int n;
   cin >> n;
   int ans = fact(n);
   cout << ans << endl;
   return 0;
}
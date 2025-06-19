// gcd is highest common factor : GCD[24,72] = 24

// Euclid's algorithm

// gcd(a,b) = gcd(a-b, b) = gcd(a%b, b)

/*
GCD(a, b) = GCD(a - b, b) (when a > b)
   It means: Subtract the smaller number from the larger number until both are equal.
*/

#include <iostream>
using namespace std;

/*
Base cases:
   If either number is 0, return the other (because GCD(a, 0) = a).
   This also prevents division by zero.
*/
int gcd(int a, int b)
{
   if (b == 0)
      return a;

   if (a == 0)
      return b;
   // tab tak gcd nikalna jab tak a ya b 0 na ho jaye
   /*
   Keep subtracting the smaller number from the larger one.
   Loop runs until both numbers become equal.
   That common value is the GCD.
   */
   while (a != b)
   {
      if (a > b)
      {
         a = a - b;
      }
      else
      {
         b = b - a;
      }
   }
   return a; // At this point, both a and b are equal (a == b), so it doesn't matter whether you return a or b. But we return a for consistency.
}

int main()
{
   int a, b;
   cout << "enter 2 numbers: " << endl;
   cin >> a >> b;
   cout << "gcd of " << a << " and " << b << " is: " << gcd(a, b);
   return 0;
}
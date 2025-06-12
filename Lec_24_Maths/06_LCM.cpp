#include <iostream>
using namespace std;

// Function to compute GCD using Euclidean Algorithm (modulus version)
int gcd(int a, int b)
{
   while (b != 0)
   {
      int temp = b;
      b = a % b; // get the remainder
      a = temp;
   }
   return a; // when b becomes 0, a holds the GCD
}

// Function to compute LCM using the relation: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b)
{
   if (a == 0 || b == 0)
      return 0; // LCM of 0 with any number is 0

   int gcdValue = gcd(a, b);  // get the GCD first
   return (a / gcdValue) * b; // to prevent overflow: divide first then multiply
}

// Main function to test the code
int main()
{
   int a, b;
   cout << "Enter two numbers: ";
   cin >> a >> b;

   cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
   cout << "LCM of " << a << " and " << b << " is: " << lcm(a, b) << endl;

   return 0;
}

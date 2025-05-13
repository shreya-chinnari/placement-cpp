// total number of setbits in 2 integers {1s}
#include <iostream>
using namespace std;

int count(int n)
{
   int count = 0;
   while (n != 0)
   {
      if (n & 1)
      {
         count++;
      }
      n = n >> 1;
   }
   return count;
}

int main()
{

   int a, b;
   cout << "Enter first number: ";
   cin >> a;

   cout << "Enter second number: ";
   cin >> b;

   int totalSetBits = count(a) + count(b);
   cout << "Total number of set bits (1s) in both numbers: " << totalSetBits << endl;

   return 0;
}
// even odd

#include <iostream>
using namespace std;

bool isEven(int n)
{
   if (n & 1)
   {
      return false; // odd
   }
   else
   {
      return true; // even
   }
}

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   if (isEven(n))
   {
      cout << n << " is even." << endl;
   }
   else
   {
      cout << n << " is odd." << endl;
   }
   return 0;
}

/*
How It Works:
   - n & 1 checks the least significant bit of n.
      : If the least significant bit is 1, the number is odd.
      : If the least significant bit is 0, the number is even.

Explanation:

   - Odd number: The least significant bit is 1. For example, 3 in binary is 11, where the least significant bit is 1.
   - Even number: The least significant bit is 0. For example, 4 in binary is 100, where the least significant bit is 0.

*/
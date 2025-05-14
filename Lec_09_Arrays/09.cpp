// revision

// if number if pow(2)

#include <iostream>
using namespace std;

// Function to count set bits (1s) in binary representation
bool isPowerOf2(int n)
{
   if (n <= 0)
      return false; // Negative numbers and 0 are not powers of 2

   int count = 0;
   while (n > 0)
   {
      if (n & 1) // Check if the last bit is 1
         count++;
      n = n >> 1; // Right shift the number by 1
   }

   return (count == 1); // Only one bit should be set in power of 2
}
/*
💡 Why does count == 1 mean it's a power of 2?
A number that is a power of 2 (like 1, 2, 4, 8, 16, ...) has a unique binary pattern:

Decimal	Binary
1	      00000001
2	      00000010
4	      00000100
8	      00001000
16	      00010000

*/
int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   if (isPowerOf2(n))
      cout << "Yes, it is a power of 2." << endl;
   else
      cout << "No, it is not a power of 2." << endl;

   return 0;
}

// Int -> Binary

// ⚠️ Note: This method works only for small values of n, since it stores binary as a decimal integer (e.g., 1111111111 as int becomes inaccurate for large binary values). For large numbers, it's better to store the binary as a "string or use a vector<int>".
// int : (-2^31) to (2^31)-1

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int ans = 0;
   int i = 0;

   while (n != 0)
   {
      int bit = n & 1; // Check if the last bit is 1 (AND operator, 1 & 1 = 1; 0 & 1 = 0; 1 & 0 = 0; 0 & 0 = 0);

      ans = (bit * pow(10, i)) + ans; // If the last bit is 1, add it to the answer at the current position (i)

      n = n >> 1; // Right shift the number by 1 bit
      i++;        // Increment the position for the next bit
   }

   cout << "Binary representation: " << ans << endl;
   return 0;
}
/* O/P -
Enter a number: 4
Binary representation: 100
*/

/*
Initial values:

   n = 5
   ans = 0
   i = 0

Iteration 1:

   n = 5 (binary: 101)
   bit = 5 & 1 = 1
   ans = (1 * 10^0) + 0 = 1
   n = 5 >> 1 = 2
   i = 1

Iteration 2:

   n = 2 (binary: 10)
   bit = 2 & 1 = 0
   ans = (0 * 10^1) + 1 = 1
   n = 2 >> 1 = 1
   i = 2

Iteration 3:

   n = 1 (binary: 1)
   bit = 1 & 1 = 1
   ans = (1 * 10^2) + 1 = 100 + 1 = 101
   n = 1 >> 1 = 0
   i = 3

Loop Ends:
   n = 0, so while (n != 0) condition fails.

*/
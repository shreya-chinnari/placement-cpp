#include <iostream>
using namespace std;

// Function to find the FLOOR VALUE of square root of a number using brute force
int sqrt(int n)
{
   if (n < 0)
   {
      cout << "Negative input not allowed." << endl;
      return -1; // Return -1 for negative input
   }

   int ans = 0; // Initialize answer variable to store the result

   for (int i = 0; i <= n; i++)
   {
      if (i * i <= n)
      {
         ans = i; // i is a potential candidate for the integer square root
      }
      else
      {
         break;
         // The moment (i^2 > n), we break the loop, because all future i values will also have (i^2 > n), so no point in checking further.
      }
   }
   return ans; // Return the last valid i which is the floor value of the square root
}

/*
int floorSqrt(int n) {
    int ans = 0;

    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}


[ (n * 1ll) ensures (n) is promoted to long long to match val's type in the comparison, avoiding implicit type conversion or overflow bugs. ]

*/
int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;
   int result = sqrt(n);
   cout << "Square root of " << n << " is " << result << endl;

   return 0;
}
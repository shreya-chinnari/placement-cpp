#include <iostream>
using namespace std;

int floorOfSqrt(int n)
{
   int s = 1, e = n; // search space from 1 to n
   int ans = 0;      // variable to store the floor value of the square root

   while (s <= e)
   {
      long long mid = s + (e - s) / 2;
      long long square = mid * mid;

      if ((square) <= n)
      {
         ans = mid;   // mid is a potential candidate for the integer square root
         s = mid + 1; // move to the right half to find a potentially larger floor value
      }
      else
      {
         e = mid - 1; // move to the left half as mid^2 is greater than n
      }
   }
   return ans; // return the last valid mid which is the floor value of the square root
   // return e; // alternatively, we could return e as it will be the largest integer such that e^2 <= n
}

int main()
{
   int n = 28;
   int ans = floorOfSqrt(n);
   cout << "The floor of square root of " << n
        << " is: " << ans << "\n";
   return 0;
}
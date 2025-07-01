#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n;
   cout << "Enter a binary number: ";
   cin >> n;

   int i = 0, ans = 0;

   while (n != 0)
   {
      int digit = n % 10; // Get the last digit (0 or 1)

      if (digit == 1)
      {
         ans = ans + pow(2, i);
      }
      n = n / 10; // Remove the last digit
      i++;        // Move to the next position
   }
   cout << "Decimal representation: " << ans << endl;
   return 0;
}
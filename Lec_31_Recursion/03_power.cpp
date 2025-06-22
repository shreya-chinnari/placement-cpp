#include <iostream>
using namespace std;

int power(int n)
{
   // Base case
   if (n == 0)
   {
      return 1;
   }

   // int smallerPower = power(n - 1);
   // int biggerPower = 2 * smallerPower;
   // int biggerPower = 2 * power(n - 1);
   // return biggerPower;

   // Recursive case
   return 2 * power(n - 1);
}

int main()
{
   int n;
   cout << "Enter the power of 2: ";
   cin >> n;
   int ans = power(n);
   cout << "2 raised to the power of " << n << " is: " << ans << endl;
   return 0;
}
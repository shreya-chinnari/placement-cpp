#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int ans = 1;
   for (int i = 0; i <= 30; i++) // overflow error, because i=0 : ans = 1*2 = 2 = 2^1 , i=30 : ans = 2^31
   {

      if (ans == n)
      {
         return true;
      }
      int ans = ans * 2; // declared it again here, so will always return 1
   }
   return false;
}
#include <iostream>
using namespace std;

int power(int a, int b)
{
   int ans = 1;

   for (int i = 1; i <= b; i++)
   {
      ans = ans * a;
   }
   return ans;
}
int main()
{
   // int a, b;
   // cout << "Enter first number: ";
   // cin >> a;
   // cout << "Enter second number: ";
   // cin >> b;

   // int ans = power(a, b);
   // cout << "Power : " << ans;

   int c, d;
   cout << "Enter first number: ";
   cin >> c;
   cout << "Enter second number: ";
   cin >> d;

   int res = power(c, d);
   cout << "Power : " << res;
   return 0;
}
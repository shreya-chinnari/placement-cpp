#include <iostream>
using namespace std;

int power() // removed parameters
{
   int c, d;
   cout << "Enter first number: ";
   cin >> c;
   cout << "Enter second number: ";
   cin >> d;
   // moved here ^^^
   int ans = 1;

   for (int i = 1; i <= d; i++)
   {
      ans = ans * c;
   }
   return ans;
}
int main()
{

   int res = power();
   cout << "Power : " << res;
   return 0;
}
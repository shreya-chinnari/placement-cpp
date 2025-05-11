// fibonacci series

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int a = 0;
   int b = 1;
   cout << "Fibonacci series up to " << n << " is: " << a << " " << b << " ";

   for (int i = 1; i <= n; i++)
   {
      int nextNum = a + b;
      cout << nextNum << " ";
      // update the values of a and b
      a = b;
      b = nextNum;
   }
   cout << endl;

   return 0;
}
#include <iostream>
using namespace std;

int computeAP(int n, int d)
{
   return 3 * n + d;
}

int main()
{
   int n, d;

   cout << "Enter the term number (n): ";
   cin >> n;

   cout << "Enter the common difference (d): ";
   cin >> d;

   int result = computeAP(n, d);
   cout << "The " << n << "th term of the AP (3*n + d) is: " << result << endl;

   return 0;
}
#include <iostream>
using namespace std;

void print(int n)
{
   if (n == 0)
   {
      return; // Base case: stop when n reaches 0
   }

   cout << n << " "; // Print the current value of n
   print(n - 1);     // Recursive call with n-1
}

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;
   print(n);
   return 0;
}
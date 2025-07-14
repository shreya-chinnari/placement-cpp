#include <iostream>
using namespace std;

// 1. Print i to n using recursion (top-down)
void printItoN_recursive(int i, int n)
{
   if (i > n)
      return;
   cout << i << " ";
   printItoN_recursive(i + 1, n);
}

// 2. Print n to i using recursion (top-down)
void printNtoI_recursive(int i, int n)
{
   if (n < i)
      return;
   cout << n << " ";
   printNtoI_recursive(i, n - 1);
}

// 3. Print i to n using backtracking (bottom-up)
void printItoN_backtrack(int i, int n)
{
   if (i > n)
      return;
   printItoN_backtrack(i + 1, n);
   cout << i << " ";
}

// 4. Print n to i using backtracking (bottom-up)
void printNtoI_backtrack(int i, int n)
{
   if (n < i)
      return;
   printNtoI_backtrack(i, n - 1);
   cout << n << " ";
}

int main()
{
   int i = 3, n = 7;

   cout << "1. i to n using recursion: ";
   printItoN_recursive(i, n);
   cout << "\n";

   cout << "2. n to i using recursion: ";
   printNtoI_recursive(i, n);
   cout << "\n";

   cout << "3. i to n using backtracking: ";
   printItoN_backtrack(i, n);
   cout << "\n";

   cout << "4. n to i using backtracking: ";
   printNtoI_backtrack(i, n);
   cout << "\n";

   return 0;
}

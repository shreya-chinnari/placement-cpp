#include <iostream>
using namespace std;

// =================== HEAD RECURSION ===================
void headRecursion(int n)
{
   // Base case: stop when n reaches 0
   if (n == 0)
      return;

   // Recursive call FIRST (go deeper before doing anything)
   headRecursion(n - 1);

   // Work AFTER recursive call
   cout << "Head Recursion: " << n << endl;
}

// =================== TAIL RECURSION ===================
void tailRecursion(int n)
{
   // Base case: stop when n reaches 0
   if (n == 0)
      return;

   // Work BEFORE recursive call
   cout << "Tail Recursion: " << n << endl;

   // Recursive call LAST (do work first, then go deeper)
   tailRecursion(n - 1);
}

// =================== MAIN FUNCTION ===================
int main()
{
   int number = 3;

   cout << "=== HEAD RECURSION ===" << endl;
   headRecursion(number); // Output: 1 2 3

   cout << "\n=== TAIL RECURSION ===" << endl;
   tailRecursion(number); // Output: 3 2 1

   return 0;
}

/*
=== HEAD RECURSION ===
Head Recursion: 1
Head Recursion: 2
Head Recursion: 3

=== TAIL RECURSION ===
Tail Recursion: 3
Tail Recursion: 2
Tail Recursion: 1

*/
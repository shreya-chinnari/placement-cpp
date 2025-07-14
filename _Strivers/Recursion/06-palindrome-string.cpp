// check if a string is a palindrome using recursion

#include <iostream>
#include <string>
using namespace std;

// 1. Iterative method using for loop
bool isPalindromeIterative(const string &str)
{
   int start = 0;
   int end = str.length() - 1;

   while (start < end)
   {
      if (str[start] != str[end])
         return false;
      start++;
      end--;
   }
   return true;
}

// 2. Recursive method using two pointers
bool isPalindromeRecursiveTwoPtr(const string &str, int start, int end)
{
   if (start >= end)
      return true;
   if (str[start] != str[end])
      return false;
   return isPalindromeRecursiveTwoPtr(str, start + 1, end - 1);
}

// 3. Recursive method using single variable (start only)
bool isPalindromeRecursiveSingleIndex(const string &str, int i)
{
   int n = str.length();
   if (i >= n / 2)
      return true;
   if (str[i] != str[n - i - 1])
      return false;
   return isPalindromeRecursiveSingleIndex(str, i + 1);
}

int main()
{
   string input;
   cout << "Enter a string: ";
   cin >> input;

   // Method 1
   cout << "Iterative: ";
   if (isPalindromeIterative(input))
      cout << "Palindrome\n";
   else
      cout << "Not a palindrome\n";

   // Method 2
   cout << "Recursive (two pointers): ";
   if (isPalindromeRecursiveTwoPtr(input, 0, input.length() - 1))
      cout << "Palindrome\n";
   else
      cout << "Not a palindrome\n";

   // Method 3
   cout << "Recursive (single index): ";
   if (isPalindromeRecursiveSingleIndex(input, 0))
      cout << "Palindrome\n";
   else
      cout << "Not a palindrome\n";

   return 0;
}

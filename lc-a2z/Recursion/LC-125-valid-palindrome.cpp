#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// ✅ Helper: Check if a character is alphanumeric
bool isValid(char ch)
{
   return ((ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z') ||
           (ch >= '0' && ch <= '9'));
}

// ✅ Helper: Convert character to lowercase
char toLower(char ch)
{
   if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
      return ch;
   return ch - 'A' + 'a';
}

// ✅ Helper: Check if cleaned string is palindrome (two-pointer)
bool checkPalindrome(const string &str)
{
   int s = 0, e = str.length() - 1;
   while (s <= e)
   {
      if (str[s] != str[e])
         return false;
      s++;
      e--;
   }
   return true;
}

// ✅ Recursive helper function
bool isPalindromeRec(const string &str, int s, int e)
{
   if (s >= e)
      return true;
   if (str[s] != str[e])
      return false;
   return isPalindromeRec(str, s + 1, e - 1);
}

// ✅ 1. Brute Force
// Clean string -> reverse -> compare
// TC: O(n), SC: O(n)
bool isPalindromeBrute(string s)
{
   string temp = "";
   for (char ch : s)
   {
      if (isValid(ch))
      {
         temp += toLower(ch);
      }
   }

   string reversed = temp;
   reverse(reversed.begin(), reversed.end());
   return temp == reversed;
}

// ✅ 2. Better Approach
// Clean string -> two-pointer check
// TC: O(n), SC: O(n)
bool isPalindromeBetter(string s)
{
   string temp = "";
   for (char ch : s)
   {
      if (isValid(ch))
      {
         temp += toLower(ch);
      }
   }
   return checkPalindrome(temp);
}

// ✅ 3. Optimized Approach
// Use two pointers directly on original string
// TC: O(n), SC: O(1)
bool isPalindromeOptimized(string s)
{
   int left = 0, right = s.length() - 1;

   while (left < right)
   {
      // If the current character is not alphanumeric, skip it.
      while (left < right && !isValid(s[left]))
         left++;
      while (left < right && !isValid(s[right]))
         right--;

      if (toLower(s[left]) != toLower(s[right]))
         return false;

      left++;
      right--;
   }

   return true;
}

// ✅ 4. Recursive Approach
// Clean string -> recursive palindrome check
// TC: O(n), SC: O(n)
bool isPalindromeRecursive(string s)
{
   string temp = "";
   for (char ch : s)
   {
      if (isValid(ch))
      {
         temp += toLower(ch);
      }
   }
   return isPalindromeRec(temp, 0, temp.length() - 1);
}

int main()
{
   string input;
   cout << "Enter a string: ";
   getline(cin, input);

   cout << "\nChecking if the string is a palindrome:\n";

   cout << "Brute Force: " << (isPalindromeBrute(input) ? "Yes" : "No") << endl;
   cout << "Better Approach: " << (isPalindromeBetter(input) ? "Yes" : "No") << endl;
   cout << "Optimized Approach: " << (isPalindromeOptimized(input) ? "Yes" : "No") << endl;
   cout << "Recursive Approach: " << (isPalindromeRecursive(input) ? "Yes" : "No") << endl;

   return 0;
}

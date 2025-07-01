#include <iostream>
using namespace std;

bool isPalindrome(string str, int i, int j)
{
   // base case
   if (i > j)
   {
      return true; // If indices cross, it's a palindrome
   }

   if (str[i] != str[j])
   {
      return false; // If characters don't match, it's not a palindrome
   }

   // Recursive case
   else
   {
      return isPalindrome(str, i + 1, j - 1); // Move towards the center
   }
}

int main()
{
   string str1 = "amma";
   string str2 = "apple";

   bool res1 = isPalindrome(str1, 0, str1.length() - 1);
   bool res2 = isPalindrome(str2, 0, str2.length() - 1);

   res1 ? cout << str1 << " is a palindrome.\n" : cout << str1 << " is not a palindrome.\n";
   res2 ? cout << str2 << " is a palindrome.\n" : cout << str2 << " is not a palindrome.\n";
   return 0;
}
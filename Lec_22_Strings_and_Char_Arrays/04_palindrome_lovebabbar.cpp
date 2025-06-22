#include <iostream>
#include <cstring> // for strlen

using namespace std;

bool isPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      if (str[start] != str[end])
      {
         return false; // Characters don't match, not a palindrome
      }
      start++;
      end--;
   }

   return true; // All characters matched, it is a palindrome
}

int main()
{
   char s1[] = "madam";
   char s2[] = "hello";

   cout << s1 << " is palindrome? " << (isPalindrome(s1) ? "Yes" : "No") << endl;
   cout << s2 << " is palindrome? " << (isPalindrome(s2) ? "Yes" : "No") << endl;

   return 0;
}

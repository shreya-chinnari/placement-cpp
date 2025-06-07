#include <iostream>
#include <cctype>  // for isalnum and tolower
#include <cstring> // for strlen

using namespace std;

bool isPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      // Skip non-alphanumeric from start
      while (start < end && !isalnum(str[start]))
      {
         start++;
      }

      // Skip non-alphanumeric from end
      while (start < end && !isalnum(str[end]))
      {
         end--;
      }

      // Compare lowercase characters
      if (tolower(str[start]) != tolower(str[end]))
      {
         return false; // mismatch found
      }

      start++;
      end--;
   }

   return true; // passed all checks, palindrome
}

int main()
{
   char s1[] = "A man, a plan, a canal: Panama";
   char s2[] = "race a car";
   char s3[] = "No lemon, no melon";

   cout << "\"" << s1 << "\" is palindrome? " << (isPalindrome(s1) ? "Yes" : "No") << endl;
   cout << "\"" << s2 << "\" is palindrome? " << (isPalindrome(s2) ? "Yes" : "No") << endl;
   cout << "\"" << s3 << "\" is palindrome? " << (isPalindrome(s3) ? "Yes" : "No") << endl;

   return 0;
}

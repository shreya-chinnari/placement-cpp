#include <iostream>
#include <cstring> // for strlen
#include <cctype>  // for isalnum, isspace

using namespace std;

// Custom toLowerChar: converts uppercase A-Z to lowercase a-z, else returns ch as-is
char toLowerChar(char ch)
{
   if (ch >= 'A' && ch <= 'Z')
   {
      return ch - 'A' + 'a';
   }
   return ch;
}

// Custom toUpperChar: converts lowercase a-z to uppercase A-Z, else returns ch as-is
char toUpperChar(char ch)
{
   if (ch >= 'a' && ch <= 'z')
   {
      return ch - 'a' + 'A';
   }
   return ch;
}

// 1. Basic palindrome check (includes everything)
bool isBasicPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      if (str[start] != str[end])
         return false;
      start++;
      end--;
   }
   return true;
}

// 2. Ignore whitespace only
bool isWhitespaceIgnoredPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      while (start < end && isspace(str[start]))
         start++;
      while (start < end && isspace(str[end]))
         end--;

      if (str[start] != str[end])
         return false;
      start++;
      end--;
   }
   return true;
}

// 3. Ignore case only
bool isCaseInsensitivePalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      if (toLowerChar(str[start]) != toLowerChar(str[end]))
         return false;
      start++;
      end--;
   }
   return true;
}

// 4. Ignore non-alphanumeric (case-sensitive)
bool isAlphaNumOnlyPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      while (start < end && !isalnum(str[start]))
         start++;
      while (start < end && !isalnum(str[end]))
         end--;

      if (str[start] != str[end])
         return false;
      start++;
      end--;
   }
   return true;
}

// 5. Fully normalized (ignore non-alphanumeric + case-insensitive)
bool isNormalizedPalindrome(const char str[])
{
   int start = 0;
   int end = strlen(str) - 1;

   while (start < end)
   {
      while (start < end && !isalnum(str[start]))
         start++;
      while (start < end && !isalnum(str[end]))
         end--;

      if (toLowerChar(str[start]) != toLowerChar(str[end]))
         return false;
      start++;
      end--;
   }
   return true;
}

int main()
{
   const char test[] = "A man, a plan, a canal: Panama";

   cout << "Original string: " << test << endl;

   cout << "\n1. Basic palindrome check: "
        << (isBasicPalindrome(test) ? "Yes" : "No");

   cout << "\n2. Ignore whitespaces: "
        << (isWhitespaceIgnoredPalindrome(test) ? "Yes" : "No");

   cout << "\n3. Case-insensitive: "
        << (isCaseInsensitivePalindrome(test) ? "Yes" : "No");

   cout << "\n4. Alphanumeric only (case-sensitive): "
        << (isAlphaNumOnlyPalindrome(test) ? "Yes" : "No");

   cout << "\n5. Normalized (alphanumeric + ignore case): "
        << (isNormalizedPalindrome(test) ? "Yes" : "No");

   return 0;
}

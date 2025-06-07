#include <iostream>
#include <string>
#include <cctype> // For isspace, isalnum, tolower

using namespace std;

// 1. Basic palindrome check (case-sensitive, includes all characters)
bool isBasicPalindrome(const string &str)
{
   int start = 0, end = str.length() - 1;

   while (start < end)
   {
      if (str[start] != str[end])
         return false;
      start++;
      end--;
   }
   return true;
}

// 2. Ignore whitespaces (but case- and character-sensitive)
bool isWhitespaceIgnoredPalindrome(const string &str)
{
   int start = 0, end = str.length() - 1;

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

// 3. Ignore case only (but includes symbols and spaces)
bool isCaseInsensitivePalindrome(const string &str)
{
   int start = 0, end = str.length() - 1;

   while (start < end)
   {
      if (tolower(str[start]) != tolower(str[end]))
         return false;
      start++;
      end--;
   }
   return true;
}

// 4. Ignore non-alphanumeric characters (but case-sensitive)
bool isAlphaNumOnlyPalindrome(const string &str)
{
   int start = 0, end = str.length() - 1;

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

// 5. Fully normalized: ignore case and non-alphanumeric characters
bool isNormalizedPalindrome(const string &str)
{
   int start = 0, end = str.length() - 1;

   while (start < end)
   {
      while (start < end && !isalnum(str[start]))
         start++;
      while (start < end && !isalnum(str[end]))
         end--;

      if (tolower(str[start]) != tolower(str[end]))
         return false;
      start++;
      end--;
   }
   return true;
}

int main()
{
   string test = "A man, a plan, a canal: Panama";

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

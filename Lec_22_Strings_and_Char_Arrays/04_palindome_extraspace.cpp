#include <iostream>
#include <cstring> // for strlen

using namespace std;

// Function to reverse the input string and return the reversed string
void reverseString(const char str[], char reversed_str[])
{
   int length = strlen(str);

   for (int i = 0; i < length; i++)
   {
      reversed_str[i] = str[length - 1 - i]; // Copy characters from end to start
   }

   reversed_str[length] = '\0'; // Null terminate the reversed string
}

// Function to check if a string is a palindrome by using reverseString
bool isPalindrome(const char str[])
{
   int length = strlen(str);
   char *reversed_str = new char[length + 1]; // Create array for reversed string

   reverseString(str, reversed_str); // Get reversed string

   // Compare original and reversed strings
   for (int i = 0; i < length; i++)
   {
      if (str[i] != reversed_str[i])
      {

         return false; // Not palindrome if mismatch found
      }
   }
   return true; // Palindrome if all matched
}

int main()
{
   char s1[] = "madam";
   char s2[] = "hello";

   cout << s1 << " is palindrome? " << (isPalindrome(s1) ? "Yes" : "No") << endl;
   cout << s2 << " is palindrome? " << (isPalindrome(s2) ? "Yes" : "No") << endl;

   return 0;
}

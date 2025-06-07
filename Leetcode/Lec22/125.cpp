#include <iostream>
#include <string>
#include <cctype> // for isalnum and tolower

using namespace std;

// Class containing the palindrome-checking logic
class Solution
{
public:
   bool isPalindrome(string s)
   {
      int left = 0;
      int right = (int)s.size() - 1;

      while (left < right)
      {
         // Skip non-alphanumeric characters from the left side
         while (left < right && !isalnum(s[left]))
         {
            left++;
         }

         // Skip non-alphanumeric characters from the right side
         while (left < right && !isalnum(s[right]))
         {
            right--;
         }

         // Convert both characters to lowercase for case-insensitive comparison
         if (tolower(s[left]) != tolower(s[right]))
         {
            return false; // Not a palindrome
         }

         // Move both pointers inward
         left++;
         right--;
      }

      return true; // All characters matched
   }
};

// Driver code
int main()
{
   Solution sol;

   string s1 = "A man, a plan, a canal: Panama";
   string s2 = "race a car";
   string s3 = "No lemon, no melon";

   cout << "\"" << s1 << "\" is palindrome? " << (sol.isPalindrome(s1) ? "Yes" : "No") << endl;
   cout << "\"" << s2 << "\" is palindrome? " << (sol.isPalindrome(s2) ? "Yes" : "No") << endl;
   cout << "\"" << s3 << "\" is palindrome? " << (sol.isPalindrome(s3) ? "Yes" : "No") << endl;

   return 0;
}

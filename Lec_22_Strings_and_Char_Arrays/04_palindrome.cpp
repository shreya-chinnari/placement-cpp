#include <iostream>
using namespace std;

/*
Concept:
A string is a palindrome if it reads the same forward and backward.
Logic:
Compare characters from both ends toward the center.
*/

int main()
{
   char str[] = "madam";
   int length = 0;
   bool isPalindrome = true;

   // Find length
   while (str[length] != '\0')
   {
      length++;
   }

   // Check characters from both ends
   for (int i = 0; i < length / 2; ++i)
   {
      if (str[i] != str[length - 1 - i])
      {
         isPalindrome = false;
         break;
      }
   }

   cout << "Is the string a palindrome? (without STL): " << (isPalindrome ? "Yes" : "No") << endl;
   return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
Concept:
A string is a palindrome if it equals its reverse.
Logic:
Use std::reverse to get reversed copy and compare it to the original.
*/

int main()
{
   string str = "madam";

   // Create reversed copy
   string reversed = str;
   reverse(reversed.begin(), reversed.end());

   // Compare original and reversed
   bool isPalindrome = (str == reversed);

   cout << "Is the string a palindrome? (with STL): " << (isPalindrome ? "Yes" : "No") << endl;
   return 0;
}

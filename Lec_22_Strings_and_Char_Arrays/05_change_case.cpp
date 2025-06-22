#include <iostream>
using namespace std;

// Function to convert a character to lowercase (A-Z → a-z)
char toLowerChar(char ch)
{
   if (ch >= 'A' && ch <= 'Z')
   {
      return ch - 'A' + 'a'; // ASCII conversion
   }
   return ch; // Return as-is if not uppercase
}

// Function to convert a character to uppercase (a-z → A-Z)
char toUpperChar(char ch)
{
   if (ch >= 'a' && ch <= 'z')
   {
      return ch - 'a' + 'A'; // ASCII conversion
   }
   return ch; // Return as-is if not lowercase
}

int main()
{
   char ch1 = 'D';
   char ch2 = 'g';
   char ch3 = '5';
   char ch4 = '#';

   // Test toLowerChar
   cout << "Original: " << ch1 << " -> toLowerChar: " << toLowerChar(ch1) << endl;
   cout << "Original: " << ch2 << " -> toLowerChar: " << toLowerChar(ch2) << endl;

   // Test toUpperChar
   cout << "Original: " << ch2 << " -> toUpperChar: " << toUpperChar(ch2) << endl;
   cout << "Original: " << ch1 << " -> toUpperChar: " << toUpperChar(ch1) << endl;

   // Non-alphabet characters
   cout << "Original: " << ch3 << " -> toLowerChar: " << toLowerChar(ch3) << " | toUpperChar: " << toUpperChar(ch3) << endl;
   cout << "Original: " << ch4 << " -> toLowerChar: " << toLowerChar(ch4) << " | toUpperChar: " << toUpperChar(ch4) << endl;

   return 0;
}

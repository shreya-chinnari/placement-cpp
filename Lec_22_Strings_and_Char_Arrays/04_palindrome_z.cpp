#include <iostream>
using namespace std;

char toLowerChar(char ch)
{
   // If character is between 'A' and 'Z', convert to lowercase
   if (ch >= 'A' && ch <= 'Z')
   {
      return ch - 'A' + 'a'; // Convert by ASCII difference
   }
   // Else, return character as-is (already lowercase or non-alphabetic)
   return ch;
}

int main()
{

   return 0;
}
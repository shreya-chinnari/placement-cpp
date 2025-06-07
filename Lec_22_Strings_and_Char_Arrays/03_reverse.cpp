#include <iostream>
using namespace std;

/*
Concept:
Reverse a char array manually by swapping characters from both ends.
Logic:
Use two pointers, one at the start and one at the end. Swap and move toward center.
*/

int main()
{
   char str[] = "Hello";
   int length = 0;

   // Find length manually
   while (str[length] != '\0')
   {
      length++;
   }

   // Reverse the string in-place
   for (int i = 0; i < length / 2; ++i) // Loop until the middle of the string because we are swapping
   {
      char temp = str[i];           // Store the current character
      str[i] = str[length - 1 - i]; // Swap with the corresponding character from the end
      str[length - 1 - i] = temp;   // Place the stored character at the end
   }
   // here, we swap characters from both ends until we reach the middle

   cout << "Reversed string (without STL): " << str << endl;
   return 0;
}

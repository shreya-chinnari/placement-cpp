#include <iostream>
using namespace std;

/*
Concept:
Measure the number of characters until null character '\0' is found in a char array.
Logic:
Traverse the array with a loop and count characters.
*/

int main()
{
   char str[] = "OpenAI"; // C-style string (char array)

   // using while loop================================================
   int length = 0;
   // Loop until null terminator is encountered
   while (str[length] != '\0')
   {
      length++;
   }
   cout << "Length of the string (without STL): " << length << endl;

   // using for loop==================================================

   int count = 0;
   for (int i = 0; str[i] != '\0'; i++)
   {
      count++;
   }
   cout << "Length of the string (using for loop): " << count << endl;
   return 0;
}
// Output: Length of the string (without STL): 6
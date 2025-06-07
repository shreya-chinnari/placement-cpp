#include <iostream>
#include <string>

using namespace std;

int main()
{
   // Declare a char array with embedded null characters
   char arr[] = {'a', 'b', '\0', 'c', 'd', '\0'};

   // Printing the char array directly
   cout << "Output using cout on char array: " << arr << endl;

   // Manually printing each character in the char array
   cout << "Printing each char manually: ";
   for (int i = 0; i < sizeof(arr); i++)
   {
      if (arr[i] == '\0')
      {
         cout << "\\0" << ' '; // Display \0 explicitly
      }
      else
      {
         cout << arr[i] << ' ';
      }
   }
   cout << endl;

   // Creating a string from the char array (only up to the first null character)
   string str1(arr); // std::string will stop at first '\0'
   cout << "std::string constructed from char array (default): " << str1 << endl;

   return 0;
}

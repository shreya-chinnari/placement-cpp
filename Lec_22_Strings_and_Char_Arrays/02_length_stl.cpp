#include <iostream>
#include <string>
using namespace std;

/*
Concept:
Use std::string which has built-in `.length()` method.
Logic:
Call str.length() to get the size.
*/

int main()
{
   string str = "OpenAI"; // C++ string class

   // Using built-in length() function of std::string
   cout << "Length of the string (with STL): " << str.length() << endl;
   return 0;
}
// Output: Length of the string (with STL): 6
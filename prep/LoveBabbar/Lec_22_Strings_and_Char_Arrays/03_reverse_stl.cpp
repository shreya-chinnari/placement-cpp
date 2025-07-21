#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
using namespace std;

/*
Concept:
Use STL’s std::reverse algorithm to reverse a string.
Logic:
Pass iterators to std::reverse to reverse the string in-place.
*/

int main()
{
   string str = "Hello";

   // std::reverse from <algorithm> modifies string in-place
   reverse(str.begin(), str.end());

   cout << "Reversed string (with STL): " << str << endl;
   return 0;
}

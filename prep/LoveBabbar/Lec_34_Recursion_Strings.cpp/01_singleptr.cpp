// using pointer only for "i" instead of "i and j"

#include <iostream>
using namespace std;

void reverse(string &str, int start, int size)
{

   int end = size - start - 1; // Calculate end index based on start and size
   if (start > end)
   {
      return;
   }

   swap(str[start], str[end]);
   // start++;
   // end--;
   // reverse(str, start, end);
   reverse(str, start + 1, size); // Recursive call with incremented start
   // Note: end is not decremented here because it is calculated based on size and start
}

int main()
{
   string str = "abcde";
   int size = str.length();
   cout << "Original string: " << str << endl;

   reverse(str, 0, size - 1);
   cout << "Reversed string: " << str << endl;
   return 0;
}

// Original string: abcde
// Reversed string : dcbae
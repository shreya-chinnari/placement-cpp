#include <iostream>
using namespace std;

// void reverse(string str, int start, int end) : This means you're modifying a copy, not the original string.
void reverse(string &str, int start, int end)
{
   // base case
   if (start > end)
   {
      return;
   }

   // swap characters at start and end
   swap(str[start], str[end]);
   // reverse(str, start++, end--); : Post-increment (start++) passes the old value of start to the next function call, so the recursion doesn’t move forward correctly.
   start = start + 1;        // increment start
   end = end - 1;            // decrement end
   reverse(str, start, end); // recursive call
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
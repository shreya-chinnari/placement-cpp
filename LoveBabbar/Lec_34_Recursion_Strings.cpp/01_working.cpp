
#include <iostream>
using namespace std;

void reverse(string &str, int start, int end)
{
   // print
   cout << "Reversing from index " << start << " to " << end << endl;
   cout << "Current string: " << str << endl;

   if (start > end)
   {
      return;
   }

   swap(str[start], str[end]);
   start++;
   end--;
   reverse(str, start, end);
}
/*
Original string: abcde

Reversing from index 0 to 4
Current string: abcde
Reversing from index 1 to 3
Current string: ebcda
Reversing from index 2 to 2
Current string: edcba
Reversing from index 3 to 1
Current string: edcba

Reversed string: edcba
*/
int main()
{
   string str = "abcde";
   int size = str.length();
   cout << "Original string: " << str << endl
        << endl;
   reverse(str, 0, size - 1);
   cout << "\nReversed string: " << str << endl;
   return 0;
}
// 3. Reverse a C-style null-terminated string (char[]) using manual length calculation (safe for C-strings)
// Unsafe for C-strings, but no '\0' check needed since we calculate length manually

#include <iostream>
using namespace std;

void reverseString(char s[])
{
   int length = 0;
   while (s[length] != '\0')
   {
      length++;
   }

   for (int i = 0; i < length / 2; i++)
   {
      char temp = s[i];
      s[i] = s[length - 1 - i];
      s[length - 1 - i] = temp;
   }
}

int main()
{
   char s[] = "Hello";
   reverseString(s);

   cout << "Reversed C-style string: " << s << endl;

   return 0;
}

// 1. Reverse a std::vector<char> using vector.size() (no unsafe '\0' check)

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
   int length = s.size(); // Get vector size directly

   for (int i = 0; i < length / 2; i++)
   {
      char temp = s[i];
      s[i] = s[length - 1 - i];
      s[length - 1 - i] = temp;
   }
}

int main()
{
   vector<char> s = {'H', 'e', 'l', 'l', 'o'};
   reverseString(s);

   cout << "Reversed vector<char>: ";
   for (char c : s)
      cout << c;
   cout << endl;

   return 0;
}

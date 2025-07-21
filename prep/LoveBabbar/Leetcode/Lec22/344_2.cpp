// 2. Reverse a std::vector<char> with two-pointer swap using std::swap (still safe, no '\0' check)

#include <iostream>
#include <vector>
#include <utility> // for std::swap
using namespace std;

void reverseString(vector<char> &s)
{
   int start = 0;
   int end = s.size() - 1;

   while (start < end)
   {
      swap(s[start], s[end]);
      start++;
      end--;
   }
}

int main()
{
   vector<char> s = {'W', 'o', 'r', 'l', 'd'};
   reverseString(s);

   cout << "Reversed vector<char> with swap: ";
   for (char c : s)
      cout << c;
   cout << endl;

   return 0;
}

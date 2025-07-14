// print a string multiple times using recursion

#include <iostream>
using namespace std;

void recFunc(string s, int n)
{
   cout << s << " ";
   if (n <= 0)
      return;
   n--;
   recFunc(s, n);
}
int main()
{
   recFunc("Hello", 5);
   return 0;
}
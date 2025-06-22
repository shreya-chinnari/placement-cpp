
#include <iostream>
using namespace std;

int main()
{
   char ch[] = "ab";
   char *ptr = ch;

   cout << *ptr << endl;      // prints: a
   cout << *(ch + 1) << endl; // prints: b
   return 0;
}
#include <iostream>
using namespace std;

int main()
{
   char ch = 'a';
   char *c = &ch;

   cout << "ch           : " << ch << endl; // Prints 'a'
   cout << "c            : " << c << endl;  // Prints address of 'ch'
   return 0;
}
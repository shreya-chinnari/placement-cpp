#include <iostream>
using namespace std;

int main()
{
   int num = 4;
   int *p_int = &num;

   cout << "size of int is: " << sizeof(num) << endl;
   cout << "size of ptr is: " << sizeof(p_int) << endl;

   // size of int is : 4
   // size of ptr is : 8

   char ch = 'a';
   char *p_ch = &ch;

   cout << "size of char is: " << sizeof(ch) << endl;
   cout << "size of ptr is: " << sizeof(p_ch) << endl;

   // size of char is: 1
   // size of ptr is : 8

   // pointer ka size hamesha hi 8 aane wala hai for any datatype
   return 0;
}
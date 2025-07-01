#include <iostream>
#include <string>
using namespace std;

int main()
{
   // Deleting array
   int *arr = new int[5];
   delete[] arr;

   // Deleting char
   char *ch = new char;
   delete ch;

   // Deleting string
   string *str = new string("Hello");
   delete str;

   // Deleting single int
   int *num = new int(10);
   delete num;

   return 0;
}

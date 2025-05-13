// nested switch

#include <iostream>
using namespace std;

int main()
{
   int num = 1;
   char ch = '1';

   switch (num)
   {
   case 1: // int
      switch (ch)
      {
      case '0': // char
         cout << "Case char ch = '0'" << endl;
         break;
      case '1':
         cout << "Case char ch = '1'" << endl;
         break;
      case '2':
         cout << "Case char ch = '2'" << endl;
         break;
      }
      break;

   case 2:
      cout << "Case 2" << endl;
      break;
   default:
      cout << "Default case" << endl;
   }
   return 0;
}

/*
Output:

Case char ch = '1'

*/
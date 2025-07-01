// nested switch

#include <iostream>
using namespace std;

int main()
{
   int num = 1;
   char ch = '1';

   switch (num)
   {
   case 1:
      switch (ch)
      {
      case '0':
         cout << "Case 0" << endl;
         break;
      case '1':
         cout << "Case 1" << endl;
         break;
      case '2':
         cout << "Case 2" << endl;
         break;
      }

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

Case 2 {because there is no break in case 1, it falls through to case 2}

*/
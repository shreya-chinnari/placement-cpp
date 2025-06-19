// when there is no break

#include <iostream>
using namespace std;

int main()
{
   int n = 1;

   switch (n)
   {

   case 1:
      cout << "Case 1" << endl;
      // break;
      // fall through
   case 2:
      cout << "Case 2" << endl;
      cout << "Case 2" << endl;
      cout << "Case 2" << endl;
      // break;
      // fall through
   case 3:
      cout << "Case 3" << endl;
      break;
   default:
      cout << "Default case" << endl;
   }
   return 0;
}

/* Output:
Case 1
Case 2
Case 2
Case 2
Case 3
*/
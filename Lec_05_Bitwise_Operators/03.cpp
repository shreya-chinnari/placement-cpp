// i++ - post increment operator
// ++i - pre increment operator
// i-- - post decrement operator
// --i - pre decrement operator
#include <iostream>
using namespace std;

int main()
{
   int a = 1;
   int b = 2;

   if (a-- > 0 || ++b > 2)
   {
      cout << "Stage1 - Inside If ";
   }
   else
   {
      cout << "Stage2 - Inside else ";
   }

   cout << a << " " << b << endl;

   return 0;
}
// Stage1 - Inside If 0 2
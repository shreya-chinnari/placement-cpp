#include <iostream>
using namespace std;

int main()
{
   int i = 5;

   int *p = 0; // null pointer
   p = &i;

   cout << p << endl;  // 0xd9357ff954
   cout << *p << endl; //    5

   // verify

   int *q = &i;
   cout << q << endl;  // 0xd9357ff954
   cout << *q << endl; //    5
   return 0;
}
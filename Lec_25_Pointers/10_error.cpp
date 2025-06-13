#include <iostream>
using namespace std;

int main()
{
   int *p;
   cout << *p << endl; // will print some garbage number

   int *p1 = 0;
   cout << *p1 << endl; // segmentation fault

   return 0;
}
#include <iostream>
using namespace std;

int main()
{
   int num = 10;
   int *p = &num;

   cout << num << endl;
   cout << *p << endl; // dereference
   return 0;
}
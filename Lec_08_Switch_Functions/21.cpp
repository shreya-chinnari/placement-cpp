#include <iostream>
using namespace std;

int update(int a)
{
   a -= 5;
   return a;
}

int main()
{
   int a = 15;
   update(a);         // return value is ignored
   cout << a << endl; // prints original a
   return 0;
}

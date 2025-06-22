#include <iostream>
using namespace std;

void modify(int x)
{
   x = x + 10;
   cout << "Inside function, x = " << x << endl;
}

int main()
{
   int a = 5;
   modify(a); // Call by value
   cout << "After function call, a = " << a << endl;
   return 0;
}

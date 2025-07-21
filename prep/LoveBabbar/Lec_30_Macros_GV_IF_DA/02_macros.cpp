// ✅ 2. Function - like Macros

#include <iostream>
using namespace std;

#define SQUARE(x) ((x) * (x)) // Function-like macro

int main()
{
   int num = 4;
   cout << "Square of " << num << " is " << SQUARE(num) << endl;
   return 0;
}

#include <iostream>
using namespace std;

int update(int a)
{
   int ans = a * a;
   return ans;
} // Any changes made inside the function do not affect the original variable in main() — unless the result is assigned back.
// ✅ Function returns a * a
// ✅ The return value is assigned back to a, so a is updated !

/*
✅ General Rule:
If you want to modify a variable permanently:
   - Either assign the return value back to the variable.
   - Or pass the variable by reference using int &a.
*/

int main()
{
   int a = 14;
   a = update(a);     // a becomes 14 * 14 = 196
   cout << a << endl; // prints 196
}

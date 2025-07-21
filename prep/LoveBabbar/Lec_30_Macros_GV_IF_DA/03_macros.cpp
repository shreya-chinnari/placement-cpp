// ✅ 3. Predefined Macros (Compiler Built-in Info)

#include <iostream>
using namespace std;

int main()
{
   cout << "File: " << __FILE__ << endl;
   cout << "Line: " << __LINE__ << endl;
   cout << "Compiled on: " << __DATE__ << " at " << __TIME__ << endl;
   cout << "C++ version: " << __cplusplus << endl;
   return 0;
}

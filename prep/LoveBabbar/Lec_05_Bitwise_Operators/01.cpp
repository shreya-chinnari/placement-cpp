#include <iostream>
using namespace std;

int main()
{

   int a = 4, b = 6;

   cout << "a&b = " << (a & b) << endl; // 4
   cout << "a|b = " << (a | b) << endl; // 6
   cout << "a^b = " << (a ^ b) << endl; // 2
   cout << "~a = " << (~a) << endl;     // -5

   return 0;
}
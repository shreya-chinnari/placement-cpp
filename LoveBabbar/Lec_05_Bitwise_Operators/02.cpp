#include <iostream>
using namespace std;

int main()
{
   cout << (17 >> 1) << endl; // 8
   cout << (17 << 1) << endl; // 34
   cout << (17 >> 2) << endl; // 4
   cout << (17 << 2) << endl; // 68

   // left shift - multiply by 2
   // right shift - divide by 2

   return 0;
}
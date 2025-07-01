// continue - skip the current iteration of the loop

#include <iostream>
using namespace std;

int main()
{
   for (int i = 0; i < 5; i++)
   {
      cout << "Hello " << i << endl;
      continue;                          // skip the current iteration
      cout << "World " << i * 2 << endl; // this line will never be executed
   }
   // Hello 0
   // Hello 1
   // Hello 2
   // Hello 3
   // Hello 4
   return 0;
}
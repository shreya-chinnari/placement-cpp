#include <iostream>
using namespace std;

int main()
{
   for (int i = 0; i <= 5; i--)
   {
      cout << i << " ";
      i++;
   }
   // 0 0 0 0 0 0 0 ............. 0 0 0 0 0 0 0 0 0 0 0
   return 0;
}

/*
   : i-- (in the loop header) → decrements i

   : Inside the loop: i++ → immediately cancels the decrement

   : So i never changes overall — always stuck at 0

   : Condition i <= 5 is always true

   : ⇒ Infinite loop
*/
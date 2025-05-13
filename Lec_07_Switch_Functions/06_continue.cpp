// The reason continue is not valid in a switch statement is because continue is designed specifically for loops, not for branching constructs like switch.
// continue is used inside loops (for, while, do-while) to skip the rest of the current iteration and jump to the next iteration of the loop.
// switch is a conditional branching statement that selects a block of code to run based on the value of an expression. It’s not a loop, so using continue directly in a switch (outside of a loop) will result in a compile - time error.

#include <iostream>
using namespace std;

int main()
{
   int n = 1;

   switch (n)
   {
   case 1:
      cout << "Case 1" << endl;
      // continue; // This will cause a compilation error
   case 2:
      cout << "Case 2" << endl;
      break;
   case 3:
      cout << "Case 3" << endl;
      break;
   }

   return 0;
}

/*
error: continue statement not within a loop
   14 |       continue; // This will cause a compilation error
      |       ^~~~~~~~

*/
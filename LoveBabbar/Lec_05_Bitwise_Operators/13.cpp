#include <iostream>
using namespace std;

int main()
{
   for (int i = 0; i < 5; i++)
   {
      for (int j = 1; j <= 5; j++)
      {
         if (i + j == 6)
         {
            break;
         }
         cout << i << " " << j << endl;
      }
      cout << endl; // print a new line after each inner loop
   }
   return 0;
}

/*
output :
      0 1
      0 2
      0 3
      0 4
      0 5

      1 1
      1 2
      1 3
      1 4

      2 1
      2 2
      2 3

      3 1
      3 2

      4 1
*/
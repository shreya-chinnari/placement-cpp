// search element in 2d array

#include <iostream>
using namespace std;
// In C++, when passing a 2D array to a function, the number of columns must be known so the compiler can correctly calculate memory offsets.
// This is because arrays are stored in row-major order, and accessing arr[i][j] requires knowing the row width (columns).
bool isPresent(int arr[][4], int target, int row, int col)
{
   for (row = 0; row < 2; row++)
   {
      for (col = 0; col < 3; col++)
      {
         if (arr[row][col] == target)
         {
            return 1; // true
         };
      }
   }
   return 0; // false
}

int main()
{
   int arr[3][4] = {0, 4, 2, 6, 2, 5, 3, 7, 3, 6, 4, 5};
   int target = 10;

   isPresent(arr, target, 3, 4) ? cout << "present" : cout << "absent";
   return 0;
}
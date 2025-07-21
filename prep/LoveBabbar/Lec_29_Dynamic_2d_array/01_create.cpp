#include <iostream>
using namespace std;

int main()
{
   int row, col;
   cout << "rows: ";
   cin >> row;
   cout << "cols: ";
   cin >> col;

   int **arr = new int *[row]; // Create an array of pointers to int

   // create a 2D array dynamically
   for (int i = 0; i < row; i++)
   {
      arr[i] = new int[col]; // Allocate memory for each row
   }
   return 0;
}
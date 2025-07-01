#include <iostream>
using namespace std;

int main()
{
   int row, col;
   cout << "rows: ";
   cin >> row;
   cout << "cols: ";
   cin >> col;

   int **arr = new int *[row];

   // create a 2D array dynamically
   for (int i = 0; i < row; i++)
   {
      arr[i] = new int[col];
   }

   // Taking input for the 2D array
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cout << "Enter element at [" << i << "][" << j << "]: ";
         cin >> arr[i][j];
      }
   }
   // Printing output for the 2D array
   for (int i = 0; i < row; i++)
   {
      for (int j = 0; j < col; j++)
      {
         cout << arr[i][j];
      }
      cout << endl;
   }

   // Deleting the dynamically allocated memory
   for (int i = 0; i < row; i++)
   {
      delete[] arr[i]; // Delete each row
   }

   delete[] arr; // Delete the array of pointers
   cout << "Memory deallocated successfully." << endl;
   return 0;
}
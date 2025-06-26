#include <iostream>
using namespace std;

int main()
{
   int rows;

   // Ask user for number of rows
   cout << "Enter number of rows: ";
   cin >> rows;

   // Step 1: Create an array of int pointers
   int **jaggedArray = new int *[rows];
   int *colSizes = new int[rows]; // to store column sizes per row

   // Step 2: For each row, get number of columns and allocate memory
   for (int i = 0; i < rows; i++)
   {
      cout << "Enter number of columns for row " << i << ": ";
      cin >> colSizes[i];

      jaggedArray[i] = new int[colSizes[i]];

      // Take input for each element
      cout << "Enter " << colSizes[i] << " elements for row " << i << ": ";
      for (int j = 0; j < colSizes[i]; j++)
      {
         cin >> jaggedArray[i][j];
      }
   }

   // Step 3: Print the jagged array
   cout << "\nJagged Array Output:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < colSizes[i]; j++)
      {
         cout << jaggedArray[i][j] << " ";
      }
      cout << endl;
   }

   // Step 4: Free memory
   for (int i = 0; i < rows; i++)
   {
      delete[] jaggedArray[i];
   }
   delete[] jaggedArray;
   delete[] colSizes;

   return 0;
}

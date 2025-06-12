/*
🔁 Sine Wave Pattern Logic:
   - Traverse each column from left to right.
   - If the column index is even, print top to bottom.
   - If the column index is odd, print bottom to top.
*/

#include <iostream>
#include <vector>
using namespace std;

void printSineWave(int arr[100][100], int rows, int cols)
{
   cout << "Sine Wave Output: [ ";
   for (int j = 0; j < cols; j++)
   {
      if (j % 2 == 0)
      {
         // Even index -> Top to Bottom
         for (int i = 0; i < rows; i++)
         {
            cout << arr[i][j] << " ";
         }
      }
      else
      {
         // Odd index -> Bottom to Top
         for (int i = rows - 1; i >= 0; i--)
         {
            cout << arr[i][j] << " ";
         }
      }
   }
   cout << "]" << endl;
}

int main()
{
   int arr[100][100];
   int rows, cols;

   cout << "Enter number of rows and columns: ";
   cin >> rows >> cols;

   cout << "Enter matrix elements:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cin >> arr[i][j];
      }
   }

   printSineWave(arr, rows, cols);

   return 0;
}

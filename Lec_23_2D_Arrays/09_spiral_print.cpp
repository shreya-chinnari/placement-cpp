#include <iostream>
#include <vector>
using namespace std;

void spiralPrint(vector<vector<int>> &matrix)
{
   int rows = matrix.size();       // total number of rows
   int cols = matrix[0].size();    // total number of columns
   int top = 0, bottom = rows - 1; // vertical boundaries
   int left = 0, right = cols - 1; // horizontal boundaries

   while (top <= bottom && left <= right) // To ensure the last row or column is still printed when the boundaries collapse to a single row or column.
   {
      // Print top row
      for (int i = left; i <= right; ++i)
         cout << matrix[top][i] << " ";
      top++;

      // Print right column
      for (int i = top; i <= bottom; ++i)
         cout << matrix[i][right] << " ";
      right--;

      if (top <= bottom)
      {
         // Print bottom row
         for (int i = right; i >= left; --i)
            cout << matrix[bottom][i] << " ";
         bottom--;
      }

      if (left <= right)
      {
         // Print left column
         for (int i = bottom; i >= top; --i)
            cout << matrix[i][left] << " ";
         left++;
      }
   }
}

int main()
{
   vector<vector<int>> matrix = {
       {1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12},
       {13, 14, 15, 16}};

   spiralPrint(matrix);

   return 0;
}

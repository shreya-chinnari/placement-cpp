/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Simple print function
void printMatrix(const vector<vector<int>> &matrix)
{
   for (int i = 0; i < matrix.size(); i++)
   {
      for (int j = 0; j < matrix[0].size(); j++)
      {
         cout << matrix[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
}

int main()
{
   vector<vector<int>> matrix = {
       {1, 2, 3},
       {4, 5, 6},
       {7, 8, 9}};

   int n = matrix.size();

   cout << "Original Matrix:\n";
   printMatrix(matrix);

   // Step 1: Transpose the matrix
   for (int i = 0; i < n; i++)
   {
      for (int j = i + 1; j < n; j++)
      {
         swap(matrix[i][j], matrix[j][i]);
      }
   }

   cout << "After Transpose:\n";
   printMatrix(matrix);

   // Step 2: Reverse each row
   for (int i = 0; i < n; i++)
   {
      reverse(matrix[i].begin(), matrix[i].end());
   }

   cout << "After 90 Degree Clockwise Rotation:\n";
   printMatrix(matrix);

   return 0;
}

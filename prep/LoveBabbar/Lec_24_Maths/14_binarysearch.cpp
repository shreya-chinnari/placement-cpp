/*
Binary Search in a 2D Matrix, assuming the matrix is:
   - Row-wise and column-wise sorted such that:
      > Each row is in ascending order
      > The first element of each row is greater than the last element of the previous row
   (i.e., matrix behaves like a flat sorted 1D array)
*/

#include <iostream>
#include <vector>
using namespace std;

// Binary search in a 2D matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
   int rows = matrix.size();    // Number of rows
   int cols = matrix[0].size(); // Number of columns

   // Treat 2D matrix as a flat 1D array: total size = rows * cols
   int start = 0;
   int end = rows * cols - 1;

   // Standard binary search
   while (start <= end)
   {
      int mid = start + (end - start) / 2;

      // Convert mid index back to 2D index: row = mid / cols, col = mid % cols
      int midElement = matrix[mid / cols][mid % cols];

      if (midElement == target)
      {
         return true; // Target found
      }
      else if (midElement < target)
      {
         start = mid + 1; // Search right half
      }
      else
      {
         end = mid - 1; // Search left half
      }
   }

   return false; // Target not found
}

int main()
{
   // Sample matrix
   vector<vector<int>> matrix = {
       {1, 3, 5, 7},
       {10, 11, 16, 20},
       {23, 30, 34, 60}};

   int target = 16;

   // Perform search
   if (searchMatrix(matrix, target))
   {
      cout << "Target " << target << " found in the matrix.\n";
   }
   else
   {
      cout << "Target " << target << " not found in the matrix.\n";
   }

   return 0;
}

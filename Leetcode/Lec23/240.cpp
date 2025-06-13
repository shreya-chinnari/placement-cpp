/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

   - Integers in each row are sorted in ascending from left to right.
   - Integers in each column are sorted in ascending from top to bottom.

   1  4  7
   2  5  8
   3  6  9
*/

/*
This is not the same as the fully sorted (flattened) matrix. So binary search won’t work directly across all elements.
Instead, we use a smart traversal starting from the top-right or bottom-left corner.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to search target in a row-wise and column-wise sorted matrix
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
   int rows = matrix.size();
   int cols = matrix[0].size();

   // Start from the top-right corner
   int rowIndex = 0;
   int colIndex = cols - 1;

   // While we are within bounds
   while (rowIndex < rows && colIndex >= 0)
   {
      int currentElement = matrix[rowIndex][colIndex];

      if (currentElement == target)
      {
         return true; // Found the target
      }
      else if (currentElement > target)
      {
         colIndex--; // Move left
      }
      else
      {
         rowIndex++; // Move down
      }
   }

   return false; // Target not found
}

int main()
{
   vector<vector<int>> matrix = {
       {1, 4, 7},
       {2, 5, 8},
       {3, 6, 9}};

   int target = 5;

   if (searchMatrix(matrix, target))
   {
      cout << "Target " << target << " found in matrix.\n";
   }
   else
   {
      cout << "Target " << target << " not found in matrix.\n";
   }

   return 0;
}

/*
🔁 General Movement Rule:
   > Start at top-right
   > If value > target → go left
   > If value < target → go down
*/

// time complexity :O(m+n)

/*
At each step:

   You either move left (col--) or move down (row++)
   You never revisit any element

So in the worst-case:

   You make at most m downward moves
   And at most n leftward moves
*/
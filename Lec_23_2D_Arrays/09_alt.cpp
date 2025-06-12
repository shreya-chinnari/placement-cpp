#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
   vector<int> spiralOrder(vector<vector<int>> &matrix)
   {
      vector<int> ans;
      int row = matrix.size();
      int col = matrix[0].size();

      int count = 0; // Keeps track of how many elements have been added to the answer.
      int total = row * col;

      // Index initialization
      // top and bottom limits.
      int startingRow = 0;
      int endingRow = row - 1;
      // left and right limits.
      int startingCol = 0;
      int endingCol = col - 1;
      // Each time a row or column is printed, the corresponding boundary is moved inward.

      while (count < total) // Keeps traversing until all total elements are added to the result (ans). Each iteration covers one outer layer of the matrix.
      {
         // Print starting row
         for (int index = startingCol; index <= endingCol && count < total; index++)
         {
            ans.push_back(matrix[startingRow][index]);
            count++;
         }
         startingRow++;

         // Print ending column
         for (int index = startingRow; index <= endingRow && count < total; index++)
         {
            ans.push_back(matrix[index][endingCol]);
            count++;
         }
         endingCol--;

         // Print ending row
         for (int index = endingCol; index >= startingCol && count < total; index--)
         {
            ans.push_back(matrix[endingRow][index]);
            count++;
         }
         endingRow--;

         // Print starting column
         for (int index = endingRow; index >= startingRow && count < total; index--)
         {
            ans.push_back(matrix[index][startingCol]);
            count++;
         }
         startingCol++;
      }

      return ans;
   }
};

int main()
{
   vector<vector<int>> matrix = {
       {1, 2, 3, 4},
       {5, 6, 7, 8},
       {9, 10, 11, 12},
       {13, 14, 15, 16}};

   Solution sol;
   vector<int> result = sol.spiralOrder(matrix);

   cout << "Spiral Order: ";
   for (int num : result)
      cout << num << " ";
   cout << endl;

   return 0;
}

/*
🔐 Why count < total in each loop?

✅ Prevents duplicate entries when rows/columns overlap in small or edge cases, like:
   1×N or N×1 matrices
Odd dimensions (e.g. 3×3, where middle element would be traversed twice)

*/
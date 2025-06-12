#include <iostream>
#include <climits>
using namespace std;

int largestRowSum(int arr[100][100], int row, int col)
{
   int maxi = INT_MIN;
   int rowIndex = -1;

   cout << "\nRow-wise Sums:\n";
   for (int i = 0; i < row; i++)
   {
      int rowSum = 0;
      for (int j = 0; j < col; j++)
      {
         rowSum += arr[i][j];
      }

      cout << "Sum of row " << i << ": " << rowSum << endl;

      if (rowSum > maxi)
      {
         maxi = rowSum;
         rowIndex = i;
      }
   }

   cout << "Max row sum: " << maxi << endl;
   return rowIndex;
}

int largestColSum(int arr[100][100], int row, int col)
{
   int maxi = INT_MIN;
   int colIndex = -1;

   cout << "\nColumn-wise Sums:\n";
   for (int j = 0; j < col; j++)
   {
      int colSum = 0;
      for (int i = 0; i < row; i++)
      {
         colSum += arr[i][j];
      }

      cout << "Sum of column " << j << ": " << colSum << endl;

      if (colSum > maxi)
      {
         maxi = colSum;
         colIndex = j;
      }
   }

   cout << "Max column sum: " << maxi << endl;
   return colIndex;
}

int main()
{
   int rows, cols;
   int arr[100][100]; // assuming max size

   cout << "Enter number of rows and columns: ";
   cin >> rows >> cols;

   cout << "Enter array elements:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cin >> arr[i][j];
      }
   }

   int rowMaxIndex = largestRowSum(arr, rows, cols);
   cout << "The largest row-sum is at row index: " << rowMaxIndex << endl;

   int colMaxIndex = largestColSum(arr, rows, cols);
   cout << "The largest column-sum is at column index: " << colMaxIndex << endl;

   return 0;
}

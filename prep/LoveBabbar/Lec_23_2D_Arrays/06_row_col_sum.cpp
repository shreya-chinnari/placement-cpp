// row-wise sum

#include <iostream>
using namespace std;

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

   // sum - row wise
   cout << "\nRow-wise Sums:\n";
   for (int i = 0; i < rows; i++)
   {
      int rowSum = 0;
      for (int j = 0; j < cols; j++)
      {
         rowSum += arr[i][j];
      }
      cout << "Sum of row " << i << ": " << rowSum << endl;
   }

   // sum - col wise

   cout << "\nColumn-wise Sums:\n";
   for (int j = 0; j < cols; j++)
   {
      int colSum = 0;
      for (int i = 0; i < rows; i++)
      {
         colSum += arr[i][j];
      }
      cout << "Sum of column " << j << ": " << colSum << endl;
   }
   return 0;
}

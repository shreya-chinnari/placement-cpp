#include <iostream>
using namespace std;

const int MAX = 100;

void inputRowWise(int arr[MAX][MAX], int rows, int cols)
{
   cout << "Enter elements (Row-wise):\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cin >> arr[i][j];
      }
   }
}

void inputColWise(int arr[MAX][MAX], int rows, int cols)
{
   cout << "Enter elements (Column-wise):\n";
   for (int j = 0; j < cols; j++)
   {
      for (int i = 0; i < rows; i++)
      {
         cin >> arr[i][j];
      }
   }
}

void printMatrix(int arr[MAX][MAX], int rows, int cols)
{
   cout << "\n2D Array Output:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
}

int main()
{
   int rows, cols;
   int arr[MAX][MAX];

   cout << "Enter number of rows and columns: ";
   cin >> rows >> cols;

   // Uncomment the input method you want to use:

   inputRowWise(arr, rows, cols);
   // inputColWise(arr, rows, cols);

   printMatrix(arr, rows, cols);

   return 0;
}

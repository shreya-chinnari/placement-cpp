#include <iostream>
using namespace std;

int main()
{
   int rows, cols;

   cout << "Enter number of rows and columns: ";
   cin >> rows >> cols;

   int arr[100][100]; // assuming max size

   // take input -->> ROW-WISE INPUT
   cout << "Enter elements:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cin >> arr[i][j]; // Input
      }
   }
   // print output
   cout << "\n2D Array Output:\n";
   for (int i = 0; i < rows; i++)
   {
      for (int j = 0; j < cols; j++)
      {
         cout << arr[i][j] << " "; // Output
      }
      cout << endl;
   }

   return 0;
}

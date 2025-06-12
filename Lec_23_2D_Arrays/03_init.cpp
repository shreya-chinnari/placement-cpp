#include <iostream>
using namespace std;

int main()
{
   // you define which element to put in which position
   int arr[2][3] = {
       {1, 2, 3},
       {4, 5, 6}};
   // just give a list of elements
   int arr1[2][3] = {1, 2, 3, 4, 5, 6};

   // print [arr]
   cout << "Hardcoded 2D Array:\n";
   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << arr[i][j] << " ";
      }
      cout << endl;
   }
   cout << endl;
   // print [arr1]
   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         cout << arr1[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}

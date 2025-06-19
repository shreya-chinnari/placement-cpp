// Sum of array elements

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main()
{
   int arr[42];
   std::fill_n(arr, 42, 1);
   printArray(arr, 42);

   int sum = 0;
   for (int i = 0; i < 42; i++)
   {
      sum = sum + arr[i];
   }
   cout << "sum: " << sum;
   return 0;
}
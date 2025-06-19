// Copy one array into another

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
   cout << "array elements: ";
   for (int i = 0; i < size; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

int main()
{
   int a[10], b[10];
   std::fill_n(a, 10, 4);
   for (int i = 0; i < 10; ++i)
      b[i] = a[i];
   printArray(a, 10);
   printArray(b, 10);

   return 0;
}
// Initialize and print array in reverse

#include <iostream>
using namespace std;

void printReversedArray(int arr[], int size)
{
   cout << "reversed array: ";
   for (int i = size; i >= 0; i--)
   // for (int i = size; i >= 0; --i) - same output
   {
      cout << arr[i] << " ";
   }

   cout << endl;
}

int main()
{
   int arr[10];
   for (int i = 0; i < 10; ++i)
   // for (int i = 0; i < 10; i++) - same for both ++i and i++ because iteration 0 : i = 0
   {
      arr[i] = i;
   }
   printReversedArray(arr, 10); // reversed array: 9 8 7 6 5 4 3 2 1 0
   return 0;
}
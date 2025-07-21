#include <iostream>
using namespace std;

int optimised(int arr[], int n)
{
   int smallest = arr[0];
   for (int i = 0; i < n; i++)
   {
      if (arr[i] < smallest)
      {
         smallest = arr[i];
      }
   }
   return smallest;
}
// TC : O()
// SC : O()

int main()
{
   int arr[6] = {3, 8, 2, 5, 1, 4};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "The smallest element is: " << optimised(arr, n) << endl;

   return 0;
}
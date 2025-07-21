#include <iostream>
using namespace std;

int optimised(int arr[], int n)
{
   int largest = arr[0];
   for (int i = 1; i < n; i++) // < n, not n - 1
   {
      if (arr[i] > largest)
         largest = arr[i];
   }
   return largest;
}

// TC : O(n)
// SC : O(1)

int main()
{
   int arr[6] = {3, 8, 2, 5, 1, 4};
   int n = sizeof(arr) / sizeof(arr[0]);

   cout << "The largest element is: " << optimised(arr, n) << endl;

   return 0;
}
#include <iostream>
using namespace std;

void rotateByK(int arr[], int n, int k)
{
   // Normalize k if it is greater than n
   k = k % n;

   // Step 1: Store last k elements into a temp[]
   int temp[k];
   for (int i = 0; i < k; i++)
   {
      temp[i] = arr[n - k + i];
   }

   // Step 2: Shift the rest of the array to the right by k positions
   for (int i = n - k - 1; i >= 0; i--)
   {
      arr[i + k] = arr[i];
   }

   // Step 3: Copy temp[] elements to the start of arr[]
   for (int i = 0; i < k; i++)
   {
      arr[i] = temp[i];
   }
}

int main()
{
   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;
   rotateByK(arr, n, k);

   cout << "Array after right rotation by " << k << " places: ";
   for (int i = 0; i < n; i++)
      cout << arr[i] << " ";

   return 0;
}

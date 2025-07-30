#include <iostream>
using namespace std;

// brute force :

// 1. transfer the first "k" elements to a "temp[]" array
// 2. shift the remaining elements {from arr[d] to arr[n]} to the left by "k" positions
// 3. copy the "temp[]" array back to the end of the original array {from arr[n-d] to arr[n]}

void rotateByK(int arr[], int n, int k)
{
   if (k > n)
      k = k % n;

   // 1. transfer the first "k" elements to a "temp[]" array
   int temp[k];

   for (int i = 0; i < k; i++)
   {
      temp[i] = arr[i];
   }

   // 2. shift the remaining elements {from arr[k] to arr[n]} to the left by "k" positions
   for (int i = k; i < n; i++)
   {
      arr[i - k] = arr[i];
   }

   // 3. copy the "temp[]" array back to the end of the original array {from arr[n-d] to arr[n]}
   for (int i = n - k; i < n; i++)
   {
      arr[i] = temp[i - (n - k)];
   }
}

int main()
{

   int arr[] = {1, 2, 3, 4, 5, 6, 7};
   int n = sizeof(arr) / sizeof(arr[0]);
   int k = 3;
   rotateByK(arr, n, k);
   cout << "Array after rotation by " << k << " places: ";
   for (int i = 0; i < n; i++)
   {
      cout << arr[i] << " ";
   }

   return 0;
}
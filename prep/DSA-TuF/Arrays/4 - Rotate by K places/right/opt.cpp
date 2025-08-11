#include <iostream>
#include <algorithm>
using namespace std;

void rotateByK(int arr[], int n, int k)
{
   k = k % n;

   // Step 1: Reverse last k elements
   reverse(arr + n - k, arr + n);

   // Step 2: Reverse first n-k elements
   reverse(arr, arr + n - k);

   // Step 3: Reverse whole array
   reverse(arr, arr + n);
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

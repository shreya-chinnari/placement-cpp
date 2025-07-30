#include <iostream>
#include <algorithm> // For std::reverse
using namespace std;

// brute force :

// 1. transfer the first "k" elements to a "temp[]" array
// 2. shift the remaining elements {from arr[d] to arr[n]} to the left by "k" positions
// 3. copy the "temp[]" array back to the end of the original array {from arr[n-d] to arr[n]}

void rotateByK(int arr[], int n, int k)
{
   reverse(arr, arr + k);     // Reverse the first k elements - O(k)
   reverse(arr + k, arr + n); // Reverse the remaining n-k elements - O(n-k)
   reverse(arr, arr + n);     // Reverse the entire array to get the final rotated array - O(n)
}

// Time Complexity: O(2n)
// Space Complexity: O(1) - no extra space used

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